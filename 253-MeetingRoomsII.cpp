class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b){return a[0]<b[0];});
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        for(const auto& m : intervals){
            cout<<"interval is "<<m[0]<<" "<<m[1]<<endl;
            cout<<"q has "<<q.size()<<" room"<<endl;
            if(res<q.size()) {
                cout<<"setting res to "<<res<<endl;
                res = q.size();
            }
            if(q.empty()){
                cout<<"empty, pushing "<<m[1]<<endl;
                q.push(m[1]);
            }else{
                if(q.top()<=m[0]){
                    cout<<"ended "<<q.top()<<endl;
                    q.pop();
                }
                cout<<"pushing "<<m[1]<<endl;
                q.push(m[1]);
            }
        }
        if(res<q.size()) res = q.size();
        return res;
    }
};
