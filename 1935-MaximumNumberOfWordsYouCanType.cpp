lass Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int pos = 0;
        int last_pos = 0;
        vector<string> words;
        while(((pos = text.find(' ', last_pos))!=string::npos)){
            string w = text.substr(last_pos, pos-last_pos);
            last_pos = pos+1;
            words.push_back(w);
        }
        auto w = text.substr(last_pos);
        words.push_back(w);
        for(const auto& w : words){
            cout<<w<<" "<<endl;
        }
        cout<<endl;
        int res = 0;
        for(int i = 0; i<words.size(); i++){
            bool broken = false;
            for(const auto& c : brokenLetters){
                if(words[i].find(c)!=string::npos){
                    broken = true;
                    break;
                }
            }
            if(!broken) res++;
        }
        return res;
    }
};
