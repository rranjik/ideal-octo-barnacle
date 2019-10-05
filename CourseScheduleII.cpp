class Solution {
public:
    vector<int> res;
    vector<pair<int, vector<int>>> aL;
    bool dfs(int src){
        int i =0;
        aL[src].first=1;
        for(const auto& a : aL[src].second){
            if(aL[a].first == 0){
                if(!dfs(a)){
                    return false;
                }
            }
            else if(aL[a].first==1)
                return false;
        }
        aL[src].first=2;
        res.push_back(src);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0)
            return vector<int>();
        vector<pair<int, vector<int>>> adjList(numCourses, pair<int, vector<int>>(0, 0));
        for(const auto& prereq : prerequisites){
            adjList[prereq[0]].second.push_back(prereq[1]);
        }
        aL = adjList;
        for(int i = 0; i<numCourses; i++){
            if(aL[i].first==0)
                if(!dfs(i))
                    return vector<int>(); 
        }
        return res;
    }
};
