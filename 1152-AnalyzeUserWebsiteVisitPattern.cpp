class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        //cout<<"in "<<endl;
        unordered_map<string, vector<pair<int, string>>> m;
        unordered_map<string, int> c;
        int maxx = 0;
        string res;
        //cout<<"start "<<endl;
        for(int i = 0; i<username.size(); i++){
            //cout<<"i = "<<i<<endl;
            m[username[i]].push_back({timestamp[i], website[i]});
        }
        //cout<<"entered "<<endl;
        for(auto& [user, visits] : m){
            for(const auto& [t,s]:visits){
                cout<<t<<" "<<s<<" ";
            }
            cout<<endl;
            sort(visits.begin(), visits.end());
            for(const auto& [t,s]:visits){
                cout<<t<<" "<<s<<" ";
            }
            cout<<endl;
        }
        cout<<"sorted "<<endl;
        for(const auto& [user, visits]: m){
            cout<<"user = "<<user<<endl;
            unordered_set<string> up;
            if(visits.size()<3) continue;
            for(int i = 0; i<visits.size()-2; i++){
                for(int j = i+1; j<visits.size()-1; j++){
                    for(int k = j+1; k<visits.size(); k++){
                        string p;
                        p=(visits[i].second+"$"+visits[j].second+"#"+visits[k].second);
                        cout<<"p = "<<p<<endl;
                        up.insert(p);
                    }
                }
            }
            for(const auto& p : up) c[p]++;
        }
        cout<<"left "<<endl;
        for(const auto& [p, f] : c){
            if(f>maxx){
                maxx = f;
                res = p;
            }else if(f==maxx){
                res = min(res, p);
            }
        }
        auto d = res.find("$"); 
        auto h = res.find("#");
        return {res.substr(0, d), res.substr(d+1, h-d-1), res.substr(h+1)};
    }
};
