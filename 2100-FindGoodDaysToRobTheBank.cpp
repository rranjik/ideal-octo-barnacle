class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& g, int time) {
        int n = g.size();
        vector<int> p(n), s(n);
        int c = 1;
        p[0] = c;
        for(int i = 1; i<n; i++){
            if(g[i]<=g[i-1]){
                c++;
            }else{
                c = 1;
            }
            p[i] = c;
        }
        c = 1;
        s[n-1] = c;
        for(int i = n-2; i>=0; i--){
            if(g[i]<=g[i+1]){
                c++;
            }else{
                c = 1;
            }
            s[i] = c;
        }
        vector<int> res;
        for(int i=time; i<n-time; i++){
            if(p[i]-1>=time&&s[i]-1>=time){
                res.push_back(i);
            }
        }
        return res;
    }
};
