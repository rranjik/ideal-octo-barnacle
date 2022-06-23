class Solution {
public:
    string digitSum(string s, int k) {
        cout<<"s = "<<s<<endl;
        if(s.size()<=k) return s;
        int curr = 0;
        string res;
        int currs = 0;
        for(int i = 0; i<s.size(); i++){
            currs+=((int)s[i]-'0');
            curr++;
            if(curr==k){
                res+=to_string(currs);
                curr = 0; currs = 0;
            }
        }
        if(curr){
            res+=to_string(currs);
        }
        return digitSum(res, k);
    }
};
