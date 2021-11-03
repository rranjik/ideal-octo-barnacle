class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        int from{};
        int pos{};
        while((pos=text.find(' ', from))!=string::npos){
            string word = text.substr(from, pos-from);
            from = pos+1;
            words.push_back(word);
        }
        string lastword = text.substr(from);
        words.push_back(lastword);
        stable_sort(words.begin(), words.end(), [](const string& a, const string& b){return a.length()<b.length();});
        if(!words.size()) return {};
        string res;
        words[0][0] = toupper(words[0][0]);
        res+=words[0];
        res+=" ";
        for(int i = 1; i<words.size(); i++){
            words[i][0] = tolower(words[i][0]);
            res+=words[i];
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};
