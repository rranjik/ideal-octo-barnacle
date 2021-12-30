class Solution {
public:
    int mini = -1e9;
    unordered_map<int, unordered_map<int, int>> c;
    int dp(int i, int j){
        if(c.find(i)!=c.end()&&c[i].find(j)!=c[i].end()) return c[i][j];
        if(i<0||j<0){
            //cout<<"i = "<<i<<"; j = "<<j<<" returning mini = "<<mini<<endl;
            c[i][j] = mini;
            return mini;
        }
        int res = n1[i]*n2[j];
        auto mult = dp(i-1, j-1);
        auto multn = dp(i-1, j-1);
        auto multi1j = dp(i-1, j);
        auto multij1 = dp(i, j-1);
        auto multi1j1 = dp(i-1, j-1);
        res = max(res, multi1j);
        res = max(res, multij1);
        res = max(res, multi1j1);
        res = max({res, (mult<=mini?0:mult)+n1[i]*n2[j], multn});
        c[i][j] = res;
        //cout<<"i = "<<i<<"; j = "<<j<<" returning res = "<<res<<endl;
        return res;
    }
    vector<int> n1;
    vector<int> n2;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        return dp(n1.size()-1, n2.size()-1);
    }
};
