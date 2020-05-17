class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(const auto& c : address){
            if(c!='.')
                res+=c;
            else {
                res+="[.]";
            }
        }
        return res;
    }
};
