class Solution {
public:
    struct Trie{
        struct node{
            bool isw = false;
            int cnt = 0;
            //vector<shared_ptr<node>> children;
            vector<node*> children;
            node(){
                //children = vector<shared_ptr<node>>(26);
                children = vector<node*>(26, nullptr);
            }
        };
        //shared_ptr<node> root;
        node* root;
        Trie(){
            //root = make_shared<node>(); 
            root = new node();
        }
        void insert(string s){
            auto r = root;
            //  auto cs = s;
            //  int i = s.size()-1;
            //  for(; i>=0; i--){
            //      if(dpn.find(cs)!=dpn.end()){
            //          //cout<<"found a longer prefix "<<cs<<endl;
            //          r = dpn[cs];
            //          break;
            //      }
            //      cs.pop_back();
            //  }
            //  auto ts = i==-1?s:cs;
            //  i = i==-1?0:cs.size();
            //  //cout<<"inserting from "<<ts<<endl;
            for(int i = 0; i<s.size(); i++){
                if(r->children[s[i]-'a']==nullptr){
                    //r->children[s[i]-'a'] = make_shared<node>();
                    r->children[s[i]-'a'] = new node();
                }
                //ts+=s[i];
                //dpn[ts] = r->children[s[i]-'a'];
                r->children[s[i]-'a']->cnt++;
                r = r->children[s[i]-'a'];
            }
        }
        //void dfsint(char _ch = 'a', shared_ptr<node> r = nullptr){
        void dfsint(char _ch = 'a', node* r = nullptr){
            if(!r) return;
            cout<<_ch<<" "<<r->cnt<<endl;
            char ch = 'a';  
            for(const auto& c : r->children){
                dfsint(ch, c);
                ch++;
            }
        }
        int dfs(string s){
            //  cout<<"dfs "<<s<<endl;
            //  if(dp.find(s)!=dp.end()) {
            //      //cout<<"known "<<endl;
            //      return dp[s];
            //  }
            //  auto r = root;
            //  int res = 0;
            //  auto cs = s;
            //  int i = s.size()-1;
            //  for(; i>=0; i--){
            //      if(dpn.find(cs)!=dpn.end()){
            //          //cout<<"found a longer prefix "<<cs<<endl;
            //          r = dpn[cs];
            //          res+=dp[cs];
            //          break;
            //      }
            //      cs.pop_back();
            //  }
            //  i = cs.size();
            //  auto ts = cs;
            //  //cout<<"found upto "<<ts<<" res = "<<res<<endl;
            int res = 0;
            auto r = root;
            for(int i = 0; i<s.size(); i++){
                //ts+=s[i];
                res += r->children[s[i]-'a']->cnt;
                //dp[ts] = res;
                //dpn[ts] = r->children[s[i]-'a'];
                r = r->children[s[i]-'a'];
            }
            //cout<<s<<" returning "<<res<<endl;
            //dpn[s] = r;
            //return dp[s] = res;
            return res;
        }
        unordered_map<string, int> dp;
        //unordered_map<string, shared_ptr<node>> dpn;
        unordered_map<string, node*> dpn;
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        vector<pair<string, int>> p;
        for(int i = 0; i<words.size(); i++){
            p.push_back({words[i], i});
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        for(const auto& [w, i] : p){
            t.insert(w);
        }
        //t.dfsint('a', t.root);
        int n = words.size();
        cout<<"n = "<<n<<endl;
        vector<int> res(n);
        for(const auto& [w, i] : p){
            //cout<<"finding "<<w<<endl;
            res[i] = (t.dfs(w));
        }
        return res;
    }
};
