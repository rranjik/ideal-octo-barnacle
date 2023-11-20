class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, multiset<int>> msortaccess;
        unordered_map<string, multiset<int>> m;
        unordered_set<string> res;
        for(const auto& at : access_times){
            auto emp = at[0];
            auto time = at[1];
            auto hour = stoi(time.substr(0, 2));
            auto min = stoi(time.substr(2));
            auto minuteofday = hour*60+min;
            //cout<<"emp = "<<emp<<" minuteofday = "<<minuteofday<<endl;
            msortaccess[emp].insert(minuteofday);
        }
        for(const auto& [emp, times] : msortaccess){
            for(const auto& e : times){
                auto minuteofday = e;
                //cout<<"emp = "<<emp<<" minuteofday = "<<minuteofday<<endl;
                m[emp].insert(minuteofday);
                auto m59 = m[emp].equal_range(minuteofday-59);
                auto now = m[emp].equal_range(minuteofday);
                auto min_minus_59_dist = distance(m59.first, now.second);
                //cout<<"dist = "<<min_minus_59_dist<<endl;
                if(min_minus_59_dist>=3) res.insert(emp);
            }
        }
        vector<string> rres;
        for(const auto& e : res){
            rres.push_back(e);
        }
        return rres;
    }
};
