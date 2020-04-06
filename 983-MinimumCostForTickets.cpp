class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> d(days.begin(), days.end());
        vector<int> c(366, 0);
        for(int i = 1; i<366; i++){
            if(d.find(i)==d.end()) c[i] = c[i-1];
            else{
                c[i] = min(c[i-1]+costs[0], min(c[max(0, i-7)]+costs[1], c[max(0, i-30)]+costs[2]));
            }
        }
        return c[365];
    }
};
