class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3) return 0;
        if(grid[0].size()<3) return 0;
        int res = 0;
        for(int i = 0; i<=grid.size()-3; i++){
            for(int j = 0; j<=grid[0].size()-3; j++){
                set<int> nums;
                for(int m = i; m<i+3; m++){
                    for(int n = j; n<j+3; n++){
                        nums.insert(grid[m][n]);
                    }
                }
                if(nums.size()==9&&(*nums.begin())==1&&((*nums.rbegin()))==9){
                    auto r1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                    auto r2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                    auto r3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                    auto c1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                    auto c2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                    auto c3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                    auto d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                    auto d2 = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                    cout<<"i = "<<i<<"; j = "<<j<<endl;
                    cout<<"r1 = "<<r1<<"; r2 = "<<r2<<"; r3 = "<<r3<<endl;
                    cout<<"c1 = "<<c1<<"; c2 = "<<c2<<"; c3 = "<<c3<<endl;
                    cout<<"d1 = "<<d1<<"; d2 = "<<d2<<endl;
                    set<int> sums = {r1, r2, r3, c1, c2, c3, d1, d2};
                    if(sums.size()==1) 
                        res++;
                }
                nums.clear();
            }
        }
        return res;
    }
};
