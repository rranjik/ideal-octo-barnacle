class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    unordered_multimap<string, char> d;
    unordered_set<string> a;
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto w : dict){
            a.insert(w);
            for(int i = 0; i<w.length(); i++){
                string nw = w.substr(0, i);
                nw+="*";
                nw+=w.substr(i+1);
                d.insert({nw, w[i]});
                //cout<<nw<<" ";
            }
        }
        //cout<<endl;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string w) {
        cout<<"searching: ";
        for(int i = 0; i<w.length(); i++){
            string nw = w.substr(0, i);
            nw+="*";
            nw+=w.substr(i+1);
            cout<<nw<<" ";
            auto range = d.equal_range(nw);
            for(auto it = range.first; it!=range.second; it++){
                if(it->second!=w[i]) {
                    //cout<<endl;
                    return true;
                }
            }
        }
        //cout<<endl;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
