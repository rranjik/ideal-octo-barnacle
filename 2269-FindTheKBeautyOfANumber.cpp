class Solution {
public:
    int divisorSubstrings(int num, int k) {
        auto s = to_string(num);
        int res = 0;
        for(int i = 0; i<=s.size()-k; i++){
            auto ss = s.substr(i, k);
            cout<<ss<<endl;
            auto d = stoi(ss);
            if(d&&num%d==0) res++;
        }
        return res;
    }
};
