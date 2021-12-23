struct trie{
    struct node{
        vector<shared_ptr<node>> children;
        node(){
            children = vector<shared_ptr<node>>(26);
        }
    };
    shared_ptr<node> root;
    void insert(const string& s){
        auto r = root;
        for(int i = 0; i<s.length(); i++){
            if(!r->children[s[i]-'a']){
                r->children[s[i]-'a'] = make_shared<node>();
            }
            r = r->children[s[i]-'a'];
        }
    }
    void dfs(shared_ptr<node> r, int d, int& res){
        bool isleaf = true;
        for(int i = 0; i<26; i++){
            if(r->children[i]){
                isleaf = false;
                dfs(r->children[i], d+1, res);
            }
        } 
        if(isleaf) res+=(d+1);
    }
    trie(){
        root = make_shared<node>();
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        trie t;
        for(auto& w : words){
            reverse(w.begin(), w.end());
            t.insert(w);
        }
        int res = 0;
        t.dfs(t.root, 0, res);
        return res;
    }
};
