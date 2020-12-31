class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        if(!customers.size()) return 0;
        queue<pair<int, int>> c;
        double tres{};
        int time{};
        for(int i = 0; i<customers.size(); i++)
        c.push({customers[i][0], customers[i][1]});
        int i = 0;
        while(c.size()){
            auto j = c.front();c.pop();
            time = max(j.first, time);
            time += j.second;
            int w = time-j.first;
            cout<<"time = "<<time<<" waittime = "<<w<<endl;
            tres += w;
        }
        return tres/customers.size();
    }
};
