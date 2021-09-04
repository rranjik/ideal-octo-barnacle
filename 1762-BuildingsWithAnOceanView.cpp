class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        stack<pair<int, int>> s;
        for(int i = 0; i<h.size(); i++){
            while(!s.empty()&&s.top().first<=h[i]){
                s.pop();
            }
            s.push({h[i], i});
        }
        vector<int> res;
        while(!s.empty()) {
            res.push_back(s.top().second);
            s.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
