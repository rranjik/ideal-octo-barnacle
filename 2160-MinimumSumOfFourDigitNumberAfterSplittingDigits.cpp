class Solution {
public:
    int minimumSum(int a) {
        vector<int> s;
        string ss = to_string(a);
        for(int i=0; i<4; i++)
            s.push_back(ss[i]-'0');
        sort(s.begin(), s.end());
        return (10*s[0]+s[2])+ (10*s[1]+s[3]);
    }
};
