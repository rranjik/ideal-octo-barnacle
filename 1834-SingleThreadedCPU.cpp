class Solution {
public:
    struct task{
        int id; int et; int pt;
        task(int _i, int _e, int _p):id(_i), et(_e), pt(_p){}
        bool operator>(const task& t)const{
            if(pt==t.pt) return id>t.id;
            return pt>t.pt;
        }
    };
    int q(priority_queue<task, vector<task>, greater<task>>& pq, int in, const vector<task>& tasks, int time){
        //cout<<"q called with in = "<<in<<" time = "<<time<<endl;
        while(in<tasks.size() && time>=tasks[in].et){
            pq.push(tasks[in]);
            in++;
        }
        return in;
    }
    vector<int> getOrder(vector<vector<int>>& ts) {
        vector<task> tasks;
        for(int i = 0; i<ts.size(); i++){
            tasks.push_back({i, ts[i][0], ts[i][1]});
        }
        sort(begin(tasks), end(tasks), [](const task& a, const task& b){return a.et<b.et; });
        //for(const auto& t : tasks){
        //    cout<<"id = "<<t.id<<";  et = "<<t.et<<"; pt = "<<t.pt<<endl;
        //}
        priority_queue<task, vector<task>, greater<task>> pq;
        //for(const auto& t : tasks){
        //    pq.push(t);
        //}
        //while(!pq.empty()){
        //    auto t = pq.top(); pq.pop();
        //    cout<<"id = "<<t.id<<";  et = "<<t.et<<"; pt = "<<t.pt<<endl;
        //}
        long long time = tasks[0].et;
        //cout<<"start time = "<<time<<endl;
        auto in = q(pq, 0, tasks, time);
        vector<int> res;
        while(!pq.empty()||in<tasks.size()){
            auto t = pq.top(); pq.pop();
            res.push_back(t.id);
            time+=t.pt;
            in = q(pq, in, tasks, time);
            if(pq.empty()&&in<tasks.size()) {
                time = tasks[in].et;
                in = q(pq, in, tasks, time);
            }
        }
        return res;
    }
};
