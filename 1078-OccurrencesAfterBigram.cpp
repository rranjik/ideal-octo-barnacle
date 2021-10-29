class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        int from = 0;
        int pos = -1;
        while((pos = text.find(" ", from))!=string::npos){
            string word = text.substr(from, pos-from);
            from = pos+1;
            words.push_back(word);
        }
        string lastword = text.substr(from);
        words.push_back(lastword);
        vector<string> res;
        for(int i = 0; i<words.size()-2; i++){
            if(words[i]==first&&words[i+1]==second) res.push_back(words[i+2]);
        }
        return res;
    }
};
