class Solution {
public:
    int firstOcc(const string& s, char c){
        int res = -1;
        for(int i = 0; i<s.size(); i++){
            int res = -1;
            if(s[i]==c) return i;
        }
        return res;
    }
    int lastOcc(const string& s, char c){
        int res = -1;
        for(int i = s.size()-1; i>=0; i--){
            int res = -1;
            if(s[i]==c) return i;
        }
        return res;
    }
    int uniqBetween(const string& s, int i, int j){
        unordered_set<char> c;
        for(int k = i+1; k<=j-1; k++){
            c.insert(s[k]);
        }
        return c.size();
    }
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for(char c = 'a'; c<='z'; c++){
            auto first = firstOcc(s, c);
            auto last = lastOcc(s, c);
            //cout<<"c = "<<c<<" first = "<<first<<" last = "<<last<<endl;
            if(first!=-1&&last!=-1)
                res += uniqBetween(s, first, last);
        }
        return res;
    }
};
