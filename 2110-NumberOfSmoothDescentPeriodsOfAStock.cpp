class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int n = p.size();
        vector<int> d(n);
        long long res = 1;
        d[0] = 1;
        for(int i = 1; i<p.size(); i++){
            if(p[i]==p[i-1]-1){
                d[i] = d[i-1]+1;
            }
            else{
                d[i] = 1;
            }
            //cout<<"adding "<<d[i]<<endl;
            res += d[i];
        }
        return res;
    }
};
