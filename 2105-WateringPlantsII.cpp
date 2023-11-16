class Solution {
public:
    int minimumRefill(vector<int>& p, int ca, int cb) {
        int i = 0;
        int j = p.size()-1;
        int a = ca;
        int b = cb;
        int res = 0;
        //exit if you meet each other
        while(i<j){
            //does anyone need a refill? 
            res += (a<p[i]?1:0) + (b<p[j]?1:0);
            //if you refilled reduce current from full bucket 
            //else reduce current from bucket 
            a = (a<p[i]?ca:a)-p[i];
            b = (b<p[j]?cb:b)-p[j];
            i++; j--;
        }
        //at the same ? and a need a refill ?
        return res+(i==j&&max(a,b)<p[i]);
    }
};
