class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adjl = vector<vector<pair<int, double>>>(n);
        auto d = vector<double>(n, numeric_limits<double>::min());
        for(int i = 0; i<edges.size(); i++){
            auto e = edges[i];
            adjl[e[0]].push_back({e[1], succProb[i]});
            adjl[e[1]].push_back({e[0], succProb[i]});
        }
        d[start] = 1;
        using p = pair<double, int>;
        //priority_queue<p, vector<p>, greater<p>> q;
        priority_queue<p> q;
        q.push({d[start], start});
        vector<bool> v(n);
        while(!q.empty()){
            auto n = q.top();
            q.pop();
            //cout<<"popped "<<n.second<<endl;
            int h = n.second;
            auto dh = d[h];
            v[h] = true;
            for(const auto& a : adjl[h]){
                //cout<<a.first<<" is near "<<endl;
                auto nei = a.first;
                auto w = a.second;
                if(!v[nei]){
                    if(d[nei]<dh*(w)){
                        //cout<<"distance to "<<nei<<" was "<<d[nei]<<" and it worse than ";
                        d[nei]=dh*w;
                        cout<<d[nei]<<endl;
                        q.push({d[nei], nei});
                    }
                }
            }
        }
        return d[end]<0?0:d[end];
    }
};
