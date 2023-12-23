class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for(const auto& s : sentences){
            int spaces = 0;
            for(int i = 0; i<s.size(); i++){
                if(s[i]==' ')
                    spaces++;
            }           
            res = max(res, spaces+1);
        }
        return res;
    }
};
