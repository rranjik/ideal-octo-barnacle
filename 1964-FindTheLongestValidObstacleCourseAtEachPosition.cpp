class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> p;
        int n = obs.size();
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            int v = obs[i];
            auto it = upper_bound(begin(p), end(p), v);
            if(it==p.end()){
                p.push_back(v);
                res[i] = p.size();
            }else{
                *it = v;
                res[i] = it-p.begin()+1;
            }
        }
        return res;
    }
};
