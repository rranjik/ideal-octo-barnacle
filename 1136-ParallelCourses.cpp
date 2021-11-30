class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> indegree(N);
        vector<vector<int>> adjl(N);
        for(const auto& r : relations){
            indegree[r[1]-1]++;
            adjl[r[0]-1].push_back(r[1]-1);
        }
        queue<int> q;
        unordered_set<int> seen;
        for(int i = 0; i<N; i++){
            if(!indegree[i]) {
                q.push(i);
                seen.insert(i);
            }
        }
        int res = 0;
        while(!q.empty()){
            res++;
            auto len = q.size();
            for(int i = 0; i<len; i++){
                auto c = q.front();
                q.pop();
                for(const auto& rc : adjl[c]){
                    indegree[rc]--;
                    if(!indegree[rc]) {
                        seen.insert(rc);
                        q.push(rc);
                    }
                }
            }
        }
        if(seen.size()!=N) return -1;
        return res;
    }
};
