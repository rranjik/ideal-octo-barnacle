class Solution {
public:
    //vector<vector<int>> d;
    //int dp(int i, int k){
    //    int taken = K-k;
    //    int btaken = taken-i;
    //    int j = c.size()-1-btaken;
    //    //cout<<"i = "<<i<<"; j = "<<j<<"; k = "<<k<<endl;
    //    if(i<0||i>=c.size()||j>=c.size()||j<0) return 0;
    //    if(d[i][k]!=-1) return d[i][k];
    //    if(!k) {d[i][k] = 0; return 0;}
    //    if(i>j) {d[i][k] = 0; return 0;}
    //    if(i==j) {d[i][k] = c[i]; return c[i];}
    //    int res = 0;
    //    res = max(res, dp(i+1, k-1)+c[i]);
    //    res = max(res, dp(i, k-1)+c[j]);
    //    d[i][k] = res;
    //    return res;
    //}
    //vector<int> c;
    //int K;
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> front(k+1);
        vector<int> back(k+1);
        for(int i = 0; i<k; i++){
            front[i+1] = front[i]+cardPoints[i];
        }
        cout<<"front: ";
        for(int i = 0; i<=k; i++) cout<<front[i]<<" "; cout<<endl;
        for(int i = cardPoints.size()-1, j = 0; j<k; i--, j++){
            back[j+1] = back[j]+cardPoints[i];
        }
        cout<<"back: ";
        for(int i = 0; i<=k; i++) cout<<back[i]<<" "; cout<<endl;
        
        int res = 0;
        for(int i = 0; i<=k; i++){
            //cout<<"i = "<<i<<"; k-i = "<<k-i<<endl;
            int f = front[i];
            int b = back[k-i];
            res = max(res, f+b);
        }
        return res;
    }
};
