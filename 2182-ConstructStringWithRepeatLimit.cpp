class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        unordered_map<char, int> f;
        priority_queue<char, vector<char>, less<char>> pq;
        for(const auto& c : s) f[c]++;
        for(const auto& it : f){
            pq.push(it.first);
        }
        string res;
        char l = '-';
        //cout<<"s.size() = "<<s.size()<<endl;
        while(!pq.empty()){
            //cout<<"res = "<<res<<endl;
            //cout<<"res.size() =  "<<res.size()<<endl;
            if(pq.size()>=2){
                auto t = pq.top(); pq.pop();
                auto s = pq.top(); pq.pop();
                //cout<<">=2"<<" t = "<<t<<" s = "<<s<<endl;
                if(l==t) {
                    res+=string(1, s);
                    f[s] = min(f[s], f[s]-1);
                    l = s;
                    if(f[s]) pq.push(s);
                    pq.push(t);
                    continue;
                }
                bool insert = true;
                while(f[t]&&l!=t){
                    insert = false;
                    res += string(min(f[t], lim), t);
                    f[t] = max(0, f[t]-lim);
                    //cout<<"f[t] = "<<f[t]<<endl;
                    //cout<<"f[s] = "<<f[s]<<endl;
                    l = t;
                    if(!f[s]) continue;
                    int slim = min(f[s], lim);
                    if(f[t]) {
                        slim = 1;
                    }
                    res += string(slim, s);
                    //res += string(min(f[s], lim), s);
                    f[s] = max(0, f[s]-slim);
                    l = s;
                }
                if(f[t]) pq.push(t);
                if(f[s]) pq.push(s);
            }else{
                auto t = pq.top(); pq.pop();
                //cout<<"<2"<<" t = "<<t<<endl;
                if(l == t) break;
                res += string(min(f[t], lim), t);
                if(f[t]) pq.push(t);
                break;
            }
        }
        return res;
    }
};
