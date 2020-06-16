class Solution {
public:
    class Event{
    public:
        int type;
        int id;
        int ts;
        Event(int ty, int i, int t):type(ty), id(i), ts(t){}
        bool operator<(const Event& e) const {
            return ts<e.ts;
        }
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<Event> events;
        for(auto s : logs){
            int last_pos = 0;
            int pos = 0;
            vector<string> a;
            while((pos = s.find(':', last_pos))!=string::npos){
                string t = s.substr(last_pos, pos-last_pos);
                last_pos = pos+1;
                a.push_back(t);
            }
            auto ft = s.substr(last_pos, string::npos);
            a.push_back(ft);
            cout<<"id: "<<stoi(a[0])<<"; event: "<<a[1]<<"; time "<<stoi(a[2])<<endl;
            events.push_back(Event((a[1]=="end"?0:1), stoi(a[0]), stoi(a[2])));
            
        }
        //sort(events.begin(), events.end());
        vector<int> res(100,0);
        stack<Event> s;
        for(const auto& e : events){
            if(e.type==1){
                s.push(e);
            }else{
                auto b = s.top();
                s.pop();
                res[e.id] += (e.ts - b.ts +1);
                if(!s.empty()){
                    //cout<<"stack not empty subtract "
                    res[s.top().id]-=(e.ts - b.ts +1);
                }
            }
        }
        res.erase(remove(res.begin(), res.end(), 0),res.end());
        return res;
    }
};
