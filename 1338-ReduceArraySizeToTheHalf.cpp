class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> f;
        for(const auto& n :arr){
            f[n]++;
        }
        map<int, vector<int>, greater<int>> ivf;
        for(auto it : f){
            ivf[it.second].push_back(it.first);
        }
        int n = arr.size();
        if(n%2) n++;
        int res = 0;
        int elem = 0;
        for(auto it : ivf){
            int nn = it.second.size();
            while(nn){
                elem+=it.first;
                res++;
                if(elem>=n/2) return res;
                nn--;
            }
        }
        return res;
    }
};
