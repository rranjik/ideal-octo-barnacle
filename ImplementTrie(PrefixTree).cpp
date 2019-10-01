class TrieNode{
public:
    bool word = false;
    vector<TrieNode*> c{vector<TrieNode*>(26, nullptr)};
};
class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* r = root;
        for(const auto& ch : word){
            int i = ch - 'a';
            if((r->c[i] == nullptr)){
                r->c[i]= new TrieNode();
            }
            r= r->c[i];
        }
        r->word= true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* r = root;
        for(const auto& ch : word){
            int i = ch - 'a';
            if(r->c[i] == nullptr){
                return false;
            }
            r= r->c[i];
        }
        return r->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* r = root;
        for(const auto& ch : prefix){
            int i = ch - 'a';
            if(r->c[i] == nullptr){
                return false;
            }
            r= r->c[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
