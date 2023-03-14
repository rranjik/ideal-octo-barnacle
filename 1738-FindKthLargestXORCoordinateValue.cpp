class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> r = vector<vector<int>>(m, vector<int>(n, 0));
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int l{};
                if(j-1>=0) l = r[i][j-1];
                int u{};
                if(i-1>=0) u = r[i-1][j];
                int d{};
                if(i-1>=0&&j-1>=0) d = r[i-1][j-1];
                r[i][j] = l^(u^(d^matrix[i][j]));
                //cout<<"i = "<<i<<"; j = "<<j<<"; val = "<<r[i][j]<<endl;
                if(q.size()<k) q.push(r[i][j]);
                else{
                    auto t = q.top();
                    if(t<r[i][j]){
                        q.pop();
                        q.push(r[i][j]);
                    }
                }
            }
        }
        //for(const auto& row : r){
        //    for(const auto& v : row){
        //        cout<<v<<" ";
        //    }
        //    cout<<endl;
        //}
        //for(const auto& it : rres) cout<<it<<" "; cout<<endl;
        return q.top();
    }
};
