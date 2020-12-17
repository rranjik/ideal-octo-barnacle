class Trie{
public:
    class Node;
    using NodePtr = shared_ptr<Node>;
    class Node{
    public:
        bool word = false;
        vector<shared_ptr<Node>> children;
        Node(){
            children = vector<shared_ptr<Node>>(26, nullptr);
        }
    };
    NodePtr root;
    Trie(){
        cout<<"trie ctored"<<endl;
        root = make_shared<Node>();
    }
    void add(NodePtr root, string word){
        if(!word.length()) {
            root->word = true;
            return;
        }
        if(!root) return;
        if(!root->children[word[0]-'a']){
            root->children[word[0]-'a'] = make_shared<Node>();
        }
        add(root->children[word[0]-'a'], word.substr(1, string::npos));
    }
    void dfs(NodePtr root, string curr, vector<string>& res){
        if(res.size()>=3) return;
        if(!root) return;
        if(root->word) {
            res.push_back(curr);
        }
        for(int i = 0; i<26; i++){
            if(root->children[i]){
                curr+=('a'+i);
                dfs(root->children[i], curr, res);
                curr.pop_back();
            }
        }
    }
    bool search(NodePtr root, string prefix, string curr, vector<string>& res){
        for(const auto c : prefix){
            if(!root->children[c-'a']) return false;
            root = root->children[c-'a'];
        }
        dfs(root, prefix, res);
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for(const auto& w : products){
            t.add(t.root, w);
        }
        vector<vector<string>> res;
        for(int i = 1; i<=searchWord.length(); i++){
            string curr;
            vector<string> sres;
            if(t.search(t.root, searchWord.substr(0, i), curr, sres)){
                //sres.push_back(searchWord);
                res.push_back(sres);
            }else{
                res.push_back(sres);
            }
        }
        return  res;
    }
};
