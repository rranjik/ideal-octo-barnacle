class Solution {
public:
    map<int, vector<int>> m;
    int n;
    void dfs(string c, vector<string>& res){
        if(c.length() == n){
            res.push_back(c);
            return;
        }else{
            if(c.length()>0){
                for(int i = 0; i<m[c[c.length()-1]-'0'].size(); i++){
                    c+=(to_string(m[c[c.length()-1]-'0'][i]));
                    dfs(c, res);
                    c.pop_back();
                }
            }else{
                for(int i = 1; i<10; i++){
                    c+=(to_string(i));
                    dfs(c, res);
                    c.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        n = N;
        for(int i = 0; i<10; i++){
            auto n = i + K;
            if(n<10)
                m[i].push_back(n);
            auto p = i - K;
            if(p>=0)
                m[i].push_back(p);
        }
        for(const auto& i : m){
            cout<<i.first<<": ";
            for(const auto&  e: i.second){
                cout<<e<<" ";
            }
            cout<<endl;
        }
        vector<string> rs;
        vector<int> res;
        dfs("", rs);
        for(const auto& s : rs){
            res.push_back(stoi(s));
        }
        if(n==1)
            res.push_back(0);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
