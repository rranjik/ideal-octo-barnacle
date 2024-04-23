class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(), logs.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int pop{};
        int res{};
        int year{};
        for(int i = 0; i<logs.size(); i++){
            auto b = logs[i][0]; auto d = logs[i][1];
            while(!pq.empty()&&(pq.top()<=b)) pq.pop();
            pq.push(d);
            pop=pq.size();
            if(res<pop){
                res = pop;
                year = b;
            }
        }
        return year;
    }
};
