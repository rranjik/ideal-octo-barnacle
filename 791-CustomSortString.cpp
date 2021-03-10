class Solution {
public:
    string customSortString(string S, string T) {
        map<int, char> s;
        for(int i = 0; i<S.size(); i++){
            s[i] = S[i];
        }
        vector<int> tf(26, 0);
        for(int i = 0; i<T.size(); i++){
            tf[T[i]-'a']++;
        }
        string res;
        for(const auto& it : s){
            if(tf[it.second-'a']){
                int c = tf[it.second-'a'];
                for(int j = 0; j<c; j++){
                    res+=it.second;
                }
                tf[it.second-'a'] = 0;
            }
        }
        for(int i = 0; i<26; i++){
            if(tf[i]){
                int c = tf[i];
                for(int j = 0; j<c; j++){
                    res+=('a'+i);
                }
            }
        }
        return res;
    }
};
