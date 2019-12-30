class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i<num.size(); i++){
            string s1 = num.substr(0, i);
            if(s1.size()>1&& s1[0]=='0') break;
            for(int j = i+1; j<num.size(); j++){
                string s2 = num.substr(i, j-i);
                if(s2.size()>1&& s2[0]=='0') break;
                long n1 = stol(s1); 
                long n2 = stol(s2);
                long next = n1+n2;
                string ns =to_string(next);
                if(ns == num.substr(j, ns.length())){
                    string as = s1+s2+ns;
                    while(as.size()<num.size()){
                        n1 = n2;
                        n2 = next;
                        next = n1+n2;
                        ns = to_string(next);
                        as +=ns;
                    }
                    if(as == num) return true;
                }
            }
        }
        return false;
    }
};
