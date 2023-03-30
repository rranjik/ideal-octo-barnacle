class Solution {
public:
    string pushDominoes(string d) {
        queue<int> q;
        int n = d.size();
        vector<bool> v(n);
        for(int i = 0; i<n; i++){
            if(d[i]!='.'){
                q.push(i);
                v[i] = true;
            }
        }
        cout<<"q.size() = "<<q.size()<<endl;
        string res = d;
        while(!q.empty()){
            int s = q.size();
            map<int, char> m;
            for(int i = 0; i<s; i++){
                auto t = q.front(); q.pop();
                cout<<"looking at t = "<<t<<endl;
                if(t-1>=0&&!v[t-1]&&res[t]=='L'){
                    if(m.find(t-1)==m.end()){
                        m[t-1] = res[t];
                        cout<<t-1<<" topples to the "<<d[t]<<endl;
                    }else {
                        cout<<t-1<<" is balannced "<<endl;
                        m[t-1] = '.';
                    }
                }
                if(t+1<n&&!v[t+1]&&res[t]=='R'){
                    if(m.find(t+1)==m.end()){
                        cout<<t+1<<" topples to the "<<d[t]<<endl;
                        m[t+1] = res[t];
                    }else {
                        cout<<t+1<<" is balannced "<<endl;
                        m[t+1] = '.';
                    }
                }
            }
            for(auto const& it : m){
                q.push(it.first);
                res[it.first] = it.second;
                v[it.first] = true;
            }
        }
        return res;
    }
};
