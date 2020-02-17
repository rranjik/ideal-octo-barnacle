class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int res = 0;
        for(const auto& a : arr){
            //cout<<"a = "<<a<<endl;
            //cout<<"m[a-difference]+1 = "<<m[a-difference]+1<<endl;
            res = max(res, m[a-difference]+1);
            m[a] = m[a-difference]+1;
            //cout<<"m[a] = "<<m[a]<<endl;
        }
        return  res;
    }
};
