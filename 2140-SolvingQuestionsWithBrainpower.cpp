class Solution {
public:
    vector<vector<int>> q;
    unordered_map<int, long long> c;
    long long at(int i){
        if(c.find(i)!=c.end()) return c[i];
        if(i>=q.size()) return 0;
        long long solve = q[i][0];
        solve+=at(i+q[i][1]+1);
        long long skip = 0;
        skip+=at(i+1);
        return c[i] = max(solve, skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        q = questions;
        return at(0);
    }
};
