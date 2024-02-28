class Solution {
public:
    struct ev {
        bool fp;
        int s; int e;
        ev(int _s, int _e, bool _fp){
            s = _s;
            e = _e;
            fp = _fp;
        }
        bool operator<(const ev& x){
            if(s==x.s){
                return fp>x.fp;
            }
            return s<x.s;
        }
        bool operator>(const ev& x) const{
            return e>x.e;
            if(s==x.s){
                return e>x.e;
            }
            return e>x.e;
        }
    };
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<ev> evs;
        evs.push_back({-2, -1, true});
        for(int i = 0; i<flowers.size(); i++){
            evs.push_back({flowers[i][0], flowers[i][1], true});
        }
        unordered_map<int, vector<int>> pm;
        for(int i = 0; i<people.size(); i++){
            pm[people[i]].push_back(i);
        }
        for(const auto& [visit, idx]:pm){
            evs.push_back({visit, visit, false});
        }
        sort(evs.begin(), evs.end());
        priority_queue<ev, vector<ev>, greater<ev>> pq;
        int n = people.size();
        vector<int> res(n);
        for(int i = 0; i<evs.size(); i++){
            auto f = evs[i];
            cout<<"top = "<<f.s<<" "<<f.e<<" "<<(f.fp?"flower":"person")<<(!pq.empty()?to_string(pq.top().e):"*")<<endl;
            if(f.fp==false){
                while(!pq.empty()&&pq.top().e<f.s){
                    cout<<" popped "<<pq.top().e<<endl;
                    pq.pop();
                }
                for(const auto& i : pm[f.s]){
                    res[i] = (pq.size());
                }
            }else{
                while(!pq.empty()&&pq.top().e<f.s){
                    cout<<" popped "<<pq.top().e<<endl;
                    pq.pop();
                }
                pq.push({f});
                cout<<" pushed "<<f.e<<endl;
            }
        }
        return res;
    }
};
