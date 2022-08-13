class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> adjl(N);
        for(const auto& t : times){
            adjl[t[0]-1].push_back({t[1]-1, t[2]});
        }
        vector<bool> v(N);
        using pii = pair<int, int>;
        int d = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, K-1});
        v[K-1] =true;
        int re{};
        while(!q.empty()/*&&d<N*/){
            auto nn = q.top();
            q.pop();
            d++;
            //cout<<"d = "<<d<<endl;
            auto n = nn.second;
            if(!v[n])
                re = max(re, nn.first);
            //cout<<"popped "<<n<<" @ "<<nn.first<<endl;
            v[n] = true;
            for(const auto& c : adjl[n]){
                //cout<<"looking at "<<c.first<<" at distance "
                    //<<c.second<<" from "<<n<<endl;
                if(!v[c.first]){
                    //cout<<"pushed "<<c.first<<" @ "<<nn.first+c.second<<endl;
                    q.push({nn.first+c.second, c.first});
                }
            }
        }
        for(const auto& vv : v) if(!vv) return -1;
        return re;
    }
};
