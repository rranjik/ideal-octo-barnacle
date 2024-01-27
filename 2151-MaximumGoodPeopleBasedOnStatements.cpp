class Solution {
public:
    vector<vector<int>> s;
    int n;
    vector<vector<int>> e;
    int check(int g){
        int res = 0;
        //cout<<"g = "<<g<<endl;
        for(int i = 0; i<n; i++){
            //i is good
            if(g&(1<<i)){
                res++;
                //check evaluations of i
                //by others
                for(int j = 0; j<e[i].size(); j++){
                    //j is also good
                    if(g&(1<<j)){
                        if(e[i][j]==0){
                            //cout<<"assumed "<<i<<" is good but "<<j<<" who is also good said that "<<i<<" is bad"<<endl;
                            return -1;
                        }
                    }
                }
            }else{
                //check evaluations of i
                //by others
                for(int j = 0; j<e[i].size(); j++){
                    //j is also good
                    if(g&(1<<j)){
                        if(e[i][j]==1){
                            //cout<<"assumed "<<i<<" is bad but "<<j<<" who is good said that "<<i<<" is bad"<<endl;
                            return -1;
                        }
                    }
                }
            }
        }
        return res;
    }
    int maximumGood(vector<vector<int>>& S) {
        s = S;
        n = s.size();
        e = vector<vector<int>> (n, vector<int>(n));
        for(int j = 0; j<n; j++){
            for(int i = 0; i<n; i++){
                e[j][i] = s[i][j];
            }
        }
        int res = 0;
        for(int i = 0; i<(1<<n); i++){
            res = max(res, check(i));
        }
        return res;
    }
};
