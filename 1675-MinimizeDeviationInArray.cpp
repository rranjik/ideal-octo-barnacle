class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> poss;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2){
                poss.push_back({nums[i], i});
                poss.push_back({nums[i]*2, i});
            }else{
                poss.push_back({nums[i], i});
                while(nums[i]%2==0){
                    poss.push_back({nums[i]/2, i});
                    nums[i]/=2;
                }
            }
        }
        int nn = poss.size();
        sort(poss.begin(), poss.end());
        int i = 0;
        int j = 0;
        vector<int> f(n);
        int seen = 0;
        int res = numeric_limits<int>::max();
        //for(const auto& p : poss) cout<<"{"<<p.first<<", "<<p.second<<"}"<<", "; 
        //cout<<endl;
        while(j<nn){
            if(f[poss[j].second]==0){
                seen++;
            }
            f[poss[j].second]++;
            while(seen==n){
                res = min(res, poss[j].first-poss[i].first);
                f[poss[i].second]--;
                if(f[poss[i].second]==0) seen--;
                i++;
            }
            j++;
        }
        return res;
    }
};
