class Solution {
public:
    vector<int> a;
    vector<bool> vstd;
    bool dfs(int src, const vector<vector<int>>& adjl){
        //cout<<"dfs from "<<src<<endl;
        vstd[src] = true;
        if(a[src]==0){ 
            return true;
        }
        int res = false;
        for(int i = 0; (!res)&&i<adjl[src].size(); i++){
            if(!vstd[adjl[src][i]]){
                res|=dfs(adjl[src][i], adjl);
            }
        }
        return res;
    }
    bool canReach(vector<int>& arr, int start) {
        a = arr;
        vstd = vector<bool>(arr.size(), false);
        vector<vector<int>> adjl(arr.size());
        for(int i = 0; i<arr.size(); i++){
            if(i-arr[i]>=0&&(arr[i]!=0)){
                adjl[i].push_back(i-arr[i]);
            }
            if(i+arr[i]<arr.size()&&(arr[i]!=0)){
                adjl[i].push_back(i+arr[i]);
            }
        }
        return dfs(start, adjl);
    }
};
