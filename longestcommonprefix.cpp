class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest="";
        if(strs.size()==0)
            return "";
        char m = strs[0][0];
        int pos = 0;
        char n = '-';
        while(true){
            cout<<"m is: "<<m<<endl;
            cout<<"pos is: "<<pos<<endl;
            for(const auto& s : strs){
                if(pos >= s.length()||s[pos]!=m)
                    return longest;
                if(pos<s.length()-1)
                    n = s[pos+1];
            }
            longest+=(strs[0][pos]);
            pos++;
            m=n;
            cout<<"longest now: "<<longest<<endl;
        }
        return "";
    }
};
