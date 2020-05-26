class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> p(1440, 0);
        for(int i = 0; i<t.size(); i++){
            auto pos = t[i].find(':');
            auto hours = stoi(t[i].substr(0, pos))*60;
            auto minutes = stoi(t[i].substr(pos+1, string::npos))+hours;
            p[minutes]++;
            cout<<minutes<<" ";
        }
        cout<<endl;
        auto first = 0;
        int res = 1441;
        auto last_seen = -1;
        for(int i = 0; i<p.size(); i++){
            if(p[i] == 1){
                if(last_seen == -1){
                    last_seen = i;
                    first = i;
                }else{
                    auto diff = (i - last_seen);
                    auto odiff = ((last_seen - i)%1440)+1440;
                    cout<<"diff = "<<diff<<"; odiff = "<<odiff<<endl;
                    last_seen = i;
                    res = min(res, min(diff, odiff));
                }
            }else if (p[i]>=2) return 0;
        }
        auto diff = (last_seen - first);
        auto odiff = ((first - last_seen)%1440)+1440;
        res = min(res, min(diff, odiff));
        return res;
    }
};
