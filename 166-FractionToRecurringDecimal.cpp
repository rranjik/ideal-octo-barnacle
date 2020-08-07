class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(!num) return "0";
        string res;
        if((num>0)^(den>0)) res+="-";
        long n = abs((long)num);
        long d = abs((long)den);
        long q = n/d;
        res.append(to_string(q));
        long r = n%d;
        if(!r) return res;
        res.append(".");
        unordered_map<long, int> rems;
        while(r){
            if(rems.find(r)!=rems.end()){
                res.insert(rems[r], "(");
                res.append(")");
                return res;
            }
            rems[r] = res.size();
            r*=10;
            res.append(to_string(r/d));
            r%=d;
        }
        return res;
    }
};
