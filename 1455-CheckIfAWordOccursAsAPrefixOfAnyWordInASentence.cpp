class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        int from{};
        int pos{};
        int nword = 0;
        while((pos = sentence.find(' ', from))!=string::npos){
            nword++;
            auto word = sentence.substr(from, pos-from+1);
            from = pos+1;
            if(word.find(searchWord)==0)
                return nword;
        }
        nword++;
        string lastword = sentence.substr(from);
        if(lastword.find(searchWord)==0)
            return nword;
        return -1;
    }
};
