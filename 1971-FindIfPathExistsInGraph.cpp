class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        if(s==d) return true;
        queue<int> q;
        q.push(s);
        vector<bool> v(n, false);
        vector<vector<int>> adjl(n);
        for(const auto& a : e){
            adjl[a[0]].push_back(a[1]);
            adjl[a[1]].push_back(a[0]);
        }
        v[s] = true;
        while(!q.empty()){
            auto t = q.front();
            cout<<"t = "<<t<<endl;
            q.pop();
            for(const auto& c : adjl[t]){
                cout<<" c = "<<c<<endl;
                if(c==d) return true;
                if(!v[c]){
                    v[c] = true;
                    q.push(c);
                }
            }
        }
        return false;
    }
};
