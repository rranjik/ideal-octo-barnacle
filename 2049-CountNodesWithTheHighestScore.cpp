class Solution {
public:
    unordered_map<int, int> c;
    vector<vector<int>> adjl;
    int n;
    int dfs(int s){
        int res = 1;
        for(int i = 0; i<adjl[s].size(); i++){
            res+=dfs(adjl[s][i]);
        }
        c[s] = res;
        return res;
    }
    long long gmax = 0;
    long long gres = 0;
    void tr(int s){
        for(int i = 0; i<adjl[s].size(); i++){
            tr(adjl[s][i]);
        }
        long long up = 1;
        long long l = 1;
        long long r = 1;
        long long pc = 1;
        if(p[s]!=-1){
            pc = c[p[s]]-c[s];
        }
        if(adjl[s].size()==2){
            l = c[adjl[s][0]];
            r = c[adjl[s][1]];
            up = n-l-r-1;
        }else if(adjl[s].size()==1){
            l = c[adjl[s][0]];
            up = n-l-1;
        }else{
            up = n-1;
        }
        //cout<<"s = "<<s<<" up = "<<up<<" l = "<<l<<" r = "<<r<<endl;
        long long here = ((up==0?1:up)*l*r);
        if(here>gmax){
            gmax = here;
            gres = 1;
        }else if(here==gmax){
            gres++;
        }
    }
    vector<int> p;
    int countHighestScoreNodes(vector<int>& parents) {
        p = parents;
        n = parents.size();
        adjl = vector<vector<int>>(n);
        for(int i = 0; i<n ; i++){
            int p = parents[i];
            if(p==-1) continue;
            adjl[p].push_back(i);
        }
        dfs(0);
        for(const auto& it : c){
            //cout<<it.first<<" has "<<it.second<<endl;
        }
        tr(0);
        return gres;
    }
};
