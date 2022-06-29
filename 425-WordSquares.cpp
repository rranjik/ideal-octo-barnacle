struct Trie{
    struct Node{
        vector<shared_ptr<Node>> children;
        bool word{false};
        Node(){children = vector<shared_ptr<Node>>(26, nullptr);}
    };
    using NodePtr = shared_ptr<Node>;
    NodePtr root;
    void insert(const string& s){
        auto r = root;
        for(const auto& c : s){
            if(!r->children[c-'a']) r->children[c-'a'] = make_shared<Node>();
            r = r->children[c-'a'];
        }
        r->word = true;
    }
    void dfs(NodePtr r, string& curr, vector<string>& res){
        if(!r) return;
        if(r->word) res.push_back(curr);
        for(int i = 0; i<r->children.size(); i++){
            if(r->children[i]){
                curr+=('a'+i);
                dfs(r->children[i], curr, res);
                curr.pop_back();
            }
        }
    }
    bool search(string& s, vector<string>& res){
        auto r = root;
        for(const auto& c: s){
            if(!r->children[c-'a']) return false;
            r = r->children[c-'a'];
        }
        dfs(r, s, res);
        return true;
    }
    Trie(){
        root = make_shared<Node>();
    }
};

class Solution {
public:
    int len{0};
    bool dfs(int l, string& prefix, vector<string> curr, vector<vector<string>>& r){
        if(l==len) {
            r.push_back(curr);
            return true;
        }
        vector<string> rr;
        t.search(prefix, rr);
        if(rr.size()){
            bool rrr = false;
            for(const auto& s : rr){
                curr.push_back(s);
                string p;
                for(const auto& c : curr){
                    p+=c[prefix.length()+1];
                }
                rrr|=dfs(l+1, p, curr, r);
                curr.pop_back();
            }
            return rrr;
        }else return false;
    }
    Trie t{};
    vector<vector<string>> wordSquares(vector<string>& words) {
        if(!words.size()) return {};
        len = words[0].size();
        for(const auto& w : words){
            t.insert(w);
        }
        vector<vector<string>> res;
        for(int i = 0; i<words.size(); i++){
            vector<string> r;
            if(words[i].size()>1){
                vector<vector<string>> rr;
                string prefix = string(1, words[i][1]);
                r.push_back(words[i]);
                if(dfs(1, prefix, r, rr)){
                    for(const auto v : rr){
                        res.push_back(v);
                    }
                }
            }else{
                r.push_back(words[i]);
                res.push_back(r);
            }
        }
        return res;
    }
};
