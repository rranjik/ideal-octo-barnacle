class Solution {
public:
    unordered_map<int, queue<int>> freen;
    unordered_set<int> seen;
    unordered_map<int, bool> status;
    struct lakeday{
        int lake{-1};
        int day{-1};
        lakeday(int _l, int _d):lake(_l), day(_d){}
        bool operator<(const lakeday& ld) const {
            return day>ld.day;
        }
    };
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res;
        for(int i = 0; i<rains.size(); i++){
            int lake = rains[i];
            if(lake){
                if(seen.find(lake)==seen.end()) seen.insert(lake);
                else{
                    freen[lake].push(i);
                }
                    status[lake] = false;
            }
        }
        priority_queue<lakeday> q;
        //for(auto& it : freen){
        //    q.push({it.first, it.second.front()});
        //    it.second.pop();
        //}
        for(int i = 0; i<rains.size(); i++){
            int lake = rains[i];
            if(lake){
                if(status[lake]) return {};
                else res.push_back(-1);
                status[lake] = true;
                if(freen[lake].size()){
                    q.push({lake, freen[lake].front()});
                    //cout<<"next dry day for "<<ld.lake<<" is "<<freen[ld.lake].front()<<endl;
                    freen[lake].pop();
                }
            }
            else{
                //cout<<"free day"<<endl;
                if(q.size()){
                    res.push_back(q.top().lake);
                    auto ld = q.top();
                    //cout<<"drying "<<ld.lake<<endl;
                    status[ld.lake] = false;
                    q.pop();
                    if(freen[ld.lake].size()){
                        q.push({ld.lake, freen[ld.lake].front()});
                        //cout<<"next dry day for "<<ld.lake<<" is "<<freen[ld.lake].front()<<endl;
                        freen[ld.lake].pop();
                    }
                }else {
                    //cout<<"drying ****"<<endl;
                    res.push_back(1);
                }
            }
        }
        return res;
    }
};
