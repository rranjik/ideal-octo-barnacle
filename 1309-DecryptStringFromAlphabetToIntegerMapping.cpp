class Solution {
public:
    unordered_map<string, string> m = {
        {"1", "a"},
        {"2", "b"},
        {"3", "c"},
        {"4", "d"},
        {"5", "e"},
        {"6", "f"},
        {"7", "g"},
        {"8", "h"},
        {"9", "i"},
        {"10#", "j"},
        {"11#", "k"},
        {"12#", "l"},
        {"13#", "m"},
        {"14#", "n"},
        {"15#", "o"},
        {"16#", "p"},
        {"17#", "q"},
        {"18#", "r"},
        {"19#", "s"},
        {"20#", "t"},
        {"21#", "u"},
        {"22#", "v"},
        {"23#", "w"},
        {"24#", "x"},
        {"25#", "y"},
        {"26#", "z"}
    };
    string freqAlphabets(string s) {
        string res;
        for(int i = s.size()-1; i>=0;){
            if(s[i]=='#'){
                string lookup;
                lookup+=s[i-2];
                lookup+=s[i-1];
                lookup+=s[i];
                //cout<<"lookup = "<<lookup<<" res = "<<m[lookup]<<endl;
                res+=m[lookup];
                i-=3;
            }else{
                string lookup;
                lookup+=s[i];
                //cout<<"lookup = "<<lookup<<" res = "<<m[lookup]<<endl;
                res+=m[lookup];
                i-=1;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
