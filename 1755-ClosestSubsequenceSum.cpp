class Solution {
public:
    unordered_set<int> fhalfs;
    unordered_set<int> allsum(const vector<int>& v){
        unordered_set<int> res;
        int n = v.size();
        for(int i = 0; i<(1<<n); i++){
            int s = 0;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)){
                    s += v[j];
                }
            }
            res.insert(s);
        }
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        //similar to the approach in 
        //https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
        int n = nums.size();
        int nb2 = n/2;
        vector<int> fhalf(nb2);
        vector<int> shalf(n-nb2);
        for(int i = 0; i<nb2; i++){
            fhalf[i] = nums[i];
        }
        for(int j = 0, i = nb2; i<n; i++, j++){
            shalf[j] = nums[i];
        }
        fhalfs = allsum(fhalf);       
        auto shalfsums = allsum(shalf);
        set<int> shalfs(shalfsums.begin(), shalfsums.end());
        //for(const auto& v : shalfs) cout<<v<<" "; cout<<endl;
        //for(const auto& v : fhalfs) cout<<v<<" "; cout<<endl;
        int res = abs(goal);
        for(const auto& x : fhalfs){
            //x+y = sum
            //y = sum-x
            //cout<<"goal-x = "<<goal-x<<endl;
            auto yit = shalfs.lower_bound(goal-x);
            if(yit!=shalfs.begin()){
                auto cyit = yit;
                cyit--;
                auto prevy = *cyit;
                //cout<<"x = "<<x<<" prevy = "<<prevy<<endl;
                res = min(res, abs(goal-(x+prevy)));
                //cout<<"res = "<<res<<endl;
            }
            if(yit!=shalfs.end()){
                auto y = *yit;
                //cout<<"x = "<<x<<" y = "<<y<<endl;
                res = min(res, abs(goal-(x+y)));
                //cout<<"res = "<<res<<endl;
            }
        }
        return res;
    }
};
