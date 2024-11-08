class Solution {
public:
    /*
    i points at left edge in a
    j point next avail num to mulitply in b
    you have used i numbers in a
    you have used j numbers in b
    j-i gives the number of numbers you have used 
    from the right side of a
    */
    unordered_map<int, unordered_map<int, int>> c;
    int dp(int i, int j){
        int right_edge = n-1-(j-i);
        if(j>=m) return 0;
        if(c.find(i)!=c.end()&&c[i].find(j)!=c[i].end()) return c[i][j];
        int res = 0;
        res+=max(dp(i+1, j+1)+a[i]*b[j], dp(i, j+1)+a[right_edge]*b[j]);
        return c[i][j] = res;
    }
    vector<int> a;
    vector<int> b;
    int n; int m;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        a = nums; b = multipliers;
        n = a.size(); m = b.size();
        return dp(0, 0);
    }
};
