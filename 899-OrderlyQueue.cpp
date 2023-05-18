class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string res = s;
            for(int i = 0; i<s.length(); i++){
                auto temp = s.substr(i) + s.substr(0, i);
                res = min(res, temp);
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
