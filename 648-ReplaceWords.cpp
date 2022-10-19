class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> d(dict.begin(), dict.end());
        int from = 0;
        int pos = 0;
        vector<string> words;
        while((pos = sentence.find(' ', from))!=string::npos){
            auto word = sentence.substr(from, pos-from);
            //cout<<word<<endl;
            words.push_back(word);
            from = pos+1;
        }
        vector<string> rr;
        auto word = sentence.substr(from);
        words.push_back(word);
        cout<<word<<endl;
        //cout<<"here "<<endl;
        for(const auto& w : words){
            //cout<<"at "<<w<<endl;
            bool done = false;
            for(int i = 1; i<w.length(); i++){
                auto p = w.substr(0, i);
                //cout<<"at prefix "<<p<<endl;
                if(d.find(p)!=d.end()) {
                    rr.push_back(p);
                    done = true;
                    break;
                }
            }
            if(!done) {
                rr.push_back(w);
            }
        }
        string res;
        for(int i =0; i<rr.size(); i++){
            if(i){
                res+=" ";
                res+=rr[i];
            }else {
                res = rr[i];
            }
        }
        return res;
    }
};
