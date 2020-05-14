class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> accum;
        int cum = 0;
        for(int i = 0; i<nums.size(); i++){
            cum+=nums[i];
            accum.push_back(cum);
        }
        unordered_map<int, vector<int>> m;
        m.insert({0, {-1}});
        for(int i = 0; i<accum.size(); i++){
            int c = accum[i];
            if(m.find(c)!=m.end()){
                m[c].push_back(i);
            }else {
                m[c] = vector<int>();
                m[c].push_back(i);
            }
        }
        int res = 0;
        for(int i = 0; i<accum.size(); i++){
            int t = (k-accum[i])*-1;
            cout<<"accum["<<i<<"] = "<<accum[i]<<" looking for "<<t<<endl;
            if(m.find(t)!=m.end()){
                for(int j = 0; j<m[t].size(); j++){
                    if(m[t][j]<i) res++;
                }
            }
        }
        return res;
    }
};
