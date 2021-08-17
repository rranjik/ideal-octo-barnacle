class Solution {
public:
    void parse(string c, int& a, int & b){
        auto plus = c.find('+', 1);
        auto sa = c.substr(0, plus);
        auto sb = c.substr(plus+1);
        sb.pop_back();
        a = stoi(sa);
        b = stoi(sb);
    }
    string complexNumberMultiply(string as, string bs) {
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        parse(as, a, b);
        parse(bs, c, d);
        auto r = a*c-(b*d);
        auto i = b*c+a*d;
        return to_string(r)+"+"+to_string(i)+"i";
    }
};
