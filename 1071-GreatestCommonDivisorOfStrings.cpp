class Solution {
public:
    //string gcdOfStrings(string str1, string str2) {
    //    if(str1.size()<str2.size()) return gcdOfStrings(str2, str1);
    //    if(str2.empty()) return str1;
    //    if(str1.substr(0, str2.size())!=str2) return "";
    //    while(str1.substr(0, str2.size())==str2) 
    //        str1 = str1.substr(str2.size());
    //    return gcdOfStrings(str1, str2);
    //}
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()<str2.size()) swap(str1, str2);
        for(int i = str2.size(); i>=1; i--){
            if(str1.size()%i) continue;
            if(str1.size()%i) continue;
            
            string s = str1.substr(0, i);
            bool flag = true;
            for(int j = 0; j<str1.size(); j+=i){
                if(str1.substr(j, i)!=s){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            for(int j = 0; j<str2.size(); j+=i){
                if(str2.substr(j, i)!=s){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            return s;
        }
        return "";
    }
};
