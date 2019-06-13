class Solution {
    int printAllSubStrings(string s){
        size_t res = 0;
        int a[255];
        for(size_t start = 0; start < s.length(); start++){
            for(int i = 0; i<255; i++){
                a[i]=0;
            }
            for(size_t length = 1; length<=(s.length()-start); length++){
                string ss = s.substr(start, length);
                //cout<<"checking "<<ss<<endl;
                int lc = ss[ss.length()-1];
                //cout<<"last char is "<<lc<<endl;
                if(!a[lc]){
                    //cout<<"was zero "<<endl;
                    res = max(res, length);
                    //cout<<"res is "<<res<<endl;
                    a[lc]++;
                }
                else{
                    //cout<<"was non zero "<<endl;
                    break;
                }
            }
        }
        return res;
    }
public:
    int lengthOfLongestSubstring(string s) {
        return printAllSubStrings(s);
    }
};
