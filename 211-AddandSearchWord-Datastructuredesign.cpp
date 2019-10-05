class TrieNode{
public:
    bool word = false;
    vector<TrieNode*> c{vector<TrieNode*>(26, nullptr)};
};
class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* r = root;
        for(const auto& ch : word){
            int i = ch - 'a';
            if(r->c[i]==nullptr){
                r->c[i] = new TrieNode();
            }
            r=r->c[i];
        }
        r->word= true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word){
        return search(word, root, 0);
    }
    bool search(const string& word, TrieNode* r, const int i) {
        //cout<<"i = "<<i<<endl;
        if(i==word.size()){
            return r->word;
        }
        //cout<<"word["<<i<<"] = "<<word[i]<<endl;
        if(word[i]=='.'){
            bool found = false;
            for(const auto& child : r->c){
                if(child!=nullptr)
                   found|=search(word, child, i+1);
            }
            return found;
        }
        else{
            int j = word[i]-'a';
            if(r->c[j]!=nullptr){
                //cout<<"r->c[j] was not null"<<endl;
                return search(word, r->c[j], i+1);
            }
            else return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
