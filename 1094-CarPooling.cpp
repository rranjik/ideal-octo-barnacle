class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int c) {
        sort(t.begin(), t.end(), [](const vector<int>& a, 
        const vector<int>& b){return a[1]<b[1];});
        int occ = 0;
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>> pq;
        for(int i = 0; i<t.size(); i++){
            while(pq.size()&&pq.top().first<=t[i][1]){
                auto [stop, num] = pq.top(); pq.pop();
                occ-=num;
            }
            if(occ+t[i][0]>c) return false;
            occ+=t[i][0];
            pq.push({t[i][2], t[i][0]});
        }
        return true;
    }
};
