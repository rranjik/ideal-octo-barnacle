class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i = 1; i<=n; i++){
            v.push_back(i);
        }
        string res;
        do{
            k--;
            if(!k) {
                for(const auto& n : v){
                    res+=to_string(n);
                }
                return res;
            }
        }while(next_permutation(v.begin(), v.end()));
        return res;
    }
};
