class Solution {
public:
    vector<pair<int, vector<int>>> aL;
    bool dfs(int src){
        //cout<<"src = "<<src<<endl;
        int i =0;
        //for(const auto& p : aL){
        //    cout<<"node "<< i <<"'s v is "<<p.first<<endl;
        //    cout<<i <<"-> ";
        //    for(const auto& a : p.second){
        //        cout<<a<<" -> ";
        //    }
        //    cout<<endl;
        //    i++;
        //}
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
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0)
            return true;
        vector<pair<int, vector<int>>> adjList(numCourses, pair<int, vector<int>>(0, 0));
        for(const auto& prereq : prerequisites){
            adjList[prereq[0]].second.push_back(prereq[1]);
        }
        aL = adjList;
        bool res = true;
        for(int i = 0; i<numCourses; i++){
            if(aL[i].first==0)
                if(!dfs(i))
                    return false; 
        }
        return true;
    }
};
