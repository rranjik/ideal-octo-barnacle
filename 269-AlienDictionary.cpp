class Solution {
public:
    pair<bool, pair<int, int>> getedge(const string& a, const string& b){
        int n = a.size(); int m = b.size();
        for(int i = 0; i<min(m,n); i++){
            if(a[i]!=b[i]) return {true, {a[i]-'a', b[i]-'a'}};
        }
        return {false, {}};
    }
    bool valid(const string& a, const string& b){
        if(a.size()>b.size()){
            if(a.find(b)==0)return false;
        }
        return true;
    }
    void print(vector<vector<int>> adjl){
        for(int i = 0; i<adjl.size(); i++){
            cout<<i<<"->";
            for(int j = 0; j<adjl[i].size(); j++){
                cout<<adjl[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    string alienOrder(vector<string>& words) {
        vector<vector<int>> adjl(26);
        vector<int> deg(26);
        unordered_set<int> all;
        for(int i = 0; i<words.size()-1; i++){
            if(!valid(words[i], words[i+1]))return "";
            auto [ok, e] = getedge(words[i], words[i+1]);
            auto [u, v] = e;
            if(!ok) continue;
            all.insert(v); all.insert(v);
            adjl[v].push_back(u);
            deg[u]++;
        }
        unordered_set<char> rres;
        for(const auto& w : words){
            for(const auto& c : w){
                rres.insert(c);
            }
        }
        if(all.size()==0){
            string s;
            for(const auto& c : rres){
                s+=c;
            }
            return s;
        }
        print(adjl);
        queue<int> q;
        if(all.size())
        for(int i = 0; i<26; i++){
            if(all.find(i)!=all.end()&&deg[i]==0){
                q.push(i);
            }
        }
        bool added = true;
        vector<int> res;
        while(q.size()){
            auto f = q.front();
            q.pop();
            res.push_back(f);
            all.erase(f);
            for(const auto& s : adjl[f]){
                deg[s]--;
                if(deg[s]==0) q.push(s);
            }
        }
        if(all.size()!=0) return "";
        string s;
        for(int i = 0; i<res.size(); i++){
            rres.erase('a'+res[i]);
            s+= 'a'+res[i];
        }
        reverse(s.begin(), s.end());
        for(const auto& x : rres){
            s.push_back(x);
        }
        return s;
    }
};
