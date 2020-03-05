class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string, int> v;
        for(const auto& d : cpdomains){
            //cout<<"d = "<<d<<endl;
            auto dc = d;
            auto space = dc.find_first_of(' ');
            //cout<<"space = "<<space<<endl;
            auto visits = stoul(dc.substr(0, space));
            //cout<<"visits = "<<visits<<endl;
            dc = dc.substr(space+1);
            //cout<<"dc = "<<dc<<endl;
            v[dc] += visits;
            auto dot = dc.find_first_of('.');
            //cout<<"dot = "<<dot<<endl;
            while(dot!=string::npos){
                dc = dc.substr(dot+1);
                //cout<<"dc = "<<dc<<endl;
                v[dc] += visits;
                dot = dc.find_first_of('.');
                //cout<<"dot = "<<dot<<endl;
            }
        }
        for(const auto& it : v){
            res.push_back(to_string(it.second)+" "+it.first);
        }
        return res;
    }
};
