class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> s;  
        s.push_back(a);
        s.push_back(b);
        s.push_back(c);
        sort(s.begin(), s.end());
        a = s[0]; b = s[1]; c = s[2];
        cout<<"a = "<<a<<"; b = "<<b<<"; c = "<<c<<endl;
        if((a+b)==c) return c;
        if((a+b)<c) return a+b;
        int diff = (a+b)-c;
        cout<<"diff = "<<diff<<endl;
        int res = 0;
        res += (diff/2);
        cout<<"resm = "<<res<<endl;
        a-=(res/2);
        b-=(res/2);
        res+=c;
        return res;
    }
};
