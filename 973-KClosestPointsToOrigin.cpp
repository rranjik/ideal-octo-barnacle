class Solution {
public:
    using pii = pair<int, int>;
    double disti(int x, int y){
        return sqrt(pow(x, 2)+pow(y, 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& p, int K) {
        auto l = [](const pair<double, pii>& a, const pair<double, pii>& b){
            return a.first < b.first;
        };
        priority_queue<pair<double, pii>, vector<pair<double, pii>>, decltype(l)> q(l);
        for(int i = 0; i<p.size(); i++){
            auto d = disti(p[i][0], p[i][1]);
            if(q.size()==K){
                if(d<q.top().first){
                    q.pop();
                    q.push(make_pair(d, make_pair(p[i][0], p[i][1])));
                }
            }else if(q.size()<K){
                q.push(make_pair(d, make_pair(p[i][0], p[i][1])));
            }
        }
        vector<vector<int>> res;
        while(!q.empty()){
            auto e = q.top();
            q.pop();
            res.push_back(vector<int>{e.second.first, e.second.second});
        }
        return res;
    }
};
