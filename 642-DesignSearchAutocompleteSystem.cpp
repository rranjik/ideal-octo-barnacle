class HotString{
public:
    string s;
    int occ;
    HotString(string _s, int _occ):s(_s), occ(_occ){}
    bool operator<(const HotString& h) const{
        if(occ==h.occ){
            return s>h.s;
        }
        return occ<h.occ;
    }
};
class Trie{
public:
    class Node{
    public:
        int times{0};
        bool word{false};
        vector<unique_ptr<Node>> children;
        Node(){
            for(int i = 0; i<27; i++){
                children.push_back(nullptr);
            }
        }
    };
    using NodePtr = unique_ptr<Node>;
    NodePtr root;
    Trie(){
        root = make_unique<Node>();
    }
    void insert(const string& s, int t){
        Node* r = root.get();
        for(const auto& c : s){
            if(c==' '){
                if(!r->children[26])
                    r->children[26] = make_unique<Node>();
                r = r->children[26].get();
            }else {
                if(!r->children[c-'a'])
                    r->children[c-'a'] = make_unique<Node>();
                r = r->children[c-'a'].get();
            }
        }
        r->times += t;
        r->word = true;
    }
    void dfs(Node* r, string& curr, vector<HotString>& v){
        if(!r) return;
        if(r->word) {
            v.push_back({curr, r->times});
        }
        for(int i = 0; i<r->children.size(); i++){
            if(i==26){
                curr+=' ';
                dfs(r->children[i].get(), curr, v);
                curr.pop_back();
            }else{
                curr+='a'+i;
                dfs(r->children[i].get(), curr, v);
                curr.pop_back();
            }
        }
    }
    vector<HotString> search(const string& s){
        vector<HotString> res;
        Node* r = root.get();
        for(const auto& c : s){
            if(c==' '){
                if(!r->children[26]) return res;
                r = r->children[26].get();
            }else{
                if(!r->children[c-'a']) return res;
                r = r->children[c-'a'].get();
            }
        }
        auto ss = s;
        dfs(r, ss, res);
        return res;
    }
};
class AutocompleteSystem {
public:
    Trie t{};
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i = 0; i<sentences.size(); i++){
            t.insert(sentences[i], times[i]);
        }
        //string s1 = "ironman";
        //string s2 = "i love leetcode";
        //vector<string> ss({s1, s2});
        //sort(begin(ss), end(ss));
        //for(const auto sss: ss)
        //    cout<<sss<<" ";
        //cout<<endl;
    }
    string curr;
    vector<string> input(char c) {
        if(c!='#')
            curr+=c;
        auto r = t.search(curr);
        //sort(begin(r), end(r));
        //reverse(begin(r), end(r));
        vector<string> res;
        int a = 0;  
        while(a<3&&r.size()){
            auto e = max_element(begin(r), end(r));
            res.push_back((*e).s);
            r.erase(e);
            a++;
        }
        //for(int i = 0; i<r.size()&&a<3; i++){
        //    //cout<<r[i].s<<" = "<<r[i].occ<<endl;
        //    res.push_back(r[i].s);
        //    a++;
        //}
        if(c=='#') {
            t.insert(curr, 1);
            curr="";
            return {};
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
