class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(const auto& a : arr){
            auto r = a%k;
            while(r<0){
                r+=k;
                r%=k;
            }
            m[r]++;
        }
        for(const auto& it : m){
            if(it.first){
                auto p = (k-it.first);
                if(m[p]!=it.second) return false;
            }else{
                if(it.second%2) return false;
            }
        }
        return true;
    }
};
