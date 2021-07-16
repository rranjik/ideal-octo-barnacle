class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'k', 'l'};
        unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> res;
        for(auto& w : words){
            auto wc = w;
            for(auto& c : w) c = tolower(c);
            auto f = w[0];
            if(row1.find(f)!=row1.end()){
                bool inrow = true;
                for(int i = 1; inrow&&i<w.length(); i++){
                    if(row1.find(w[i])==row1.end()) inrow=false;
                }
                if(inrow) res.push_back(wc);
            }
            else if(row2.find(f)!=row2.end()){
                bool inrow = true;
                for(int i = 1; inrow&&i<w.length(); i++){
                    if(row2.find(w[i])==row2.end()) inrow=false;
                }
                if(inrow) res.push_back(wc);
            }
            else if(row3.find(f)!=row3.end()){
                bool inrow = true;
                for(int i = 1; inrow&&i<w.length(); i++){
                    if(row3.find(w[i])==row3.end()) inrow=false;
                }
                if(inrow) res.push_back(wc);
            }
        }
        return res;
    }
};
