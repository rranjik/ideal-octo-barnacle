class Solution {
public:
    int calculateTime(string k, string word) {
        vector<int> c(26, -1);
        for(int i = 0; i<k.size(); i++){
            c[k[i]-'a'] = i;
        }
        int res = 0;
        int last_pos = -1;
        for(const auto& w : word){
            if(last_pos == -1){
                res+=abs(0-c[w-'a']);
                last_pos = c[w-'a'];
            }else {
                res+=abs(c[w-'a']- last_pos);
                last_pos = c[w-'a'];
            }
        }
        return res;
    }
};
