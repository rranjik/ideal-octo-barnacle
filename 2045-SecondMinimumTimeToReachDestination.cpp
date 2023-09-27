class Solution {
public:
    int calc(int s, int t, int c){
        cout<<"calcing "<<s<<endl;
        int res = 0;
        while(s){
            res+=t;
            s--;
            if(s>0&&(res/c)%2){
                res = ((res/c)+1)*c;
            }
        }
        return res;
    }
    int secondMinimum(int n, vector<vector<int>>& e, int t, int c) {
        vector<vector<int>> adjl(n+1);
        for(int i = 0; i<e.size(); i++){
            auto u = e[i][0];
            auto v = e[i][1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        vector<int> mins(n+1, 1e9);
        queue<int> q;
        auto step = 0;
        q.push(1);
        //while there's nodes left and you
        //not looking at steps more than n+1
        //edge lengths. 
        while(q.size()&&step<=n){
            int s = q.size();
            for(int i = 0; i<s; i++){
                auto h = q.front();
                q.pop();
                if(step==mins[h]||step>mins[h]+1) 
                    continue;
                mins[h] = min(mins[h], step);
                if(h==n&&step==mins[n]+1){
                    return calc(step, t, c);
                }
                for(const auto& c : adjl[h]) {
                    q.push(c);
                }
            }
            step++;
        }
        return calc(mins[n]+2, t, c);
    }
};
