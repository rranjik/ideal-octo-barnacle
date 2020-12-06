class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        if(!m) return 0;
        int n = mat[0].size();
        int count = 0;
        int res = numeric_limits<int>::max();
        for(int i = 0; i<pow(2, m*n); i++){
            cout<<"i = "<<i<<endl;
            bitset<9> possibility = i;
            vector<vector<int>> matt = mat;
            int curr = 0;
            for(int j = 0; j<m*n; j++){
                if(possibility[j]){
                    curr++;
                    int x = j/n;
                    int y = j - (x*n);
                    cout<<"x = "<<x<<"; y = "<<y<<endl;
                    matt[x][y] = matt[x][y]?0:1;
                    if(x-1>=0) matt[x-1][y] = matt[x-1][y]?0:1;
                    if(y-1>=0) matt[x][y-1] = matt[x][y-1]?0:1;
                    if(x+1<m) matt[x+1][y] = matt[x+1][y]?0:1;
                    if(y+1<n) matt[x][y+1] = matt[x][y+1]?0:1;
                    count++;
                }
            }
            bool nz = true;
            for(const auto r : matt){
                for(const auto c : r){
                    cout<<c<<" ";
                    if(c) nz = false;
                }
                cout<<endl;
            }
            if(nz) res = min(res, curr);
        }
        return res==numeric_limits<int>::max()?-1:res;
    }
};
