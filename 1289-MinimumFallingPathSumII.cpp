class Solution {
public:
    //. . . . . . . . . . 
    //. . . . . x . . . . 
    //efficient way of reaching x is
    //reach the min possible way to get to the 
    //previous row and then add x - we are there!
    
    //so in this way we can compute every cell
    //in the second row
    
    //we do not process the first row like this
    
    //what if there are two first minimums or two second
    //minimums ? 
    
    //12 43 18 1 42 19 1 3 10 39 3 98
    //more the merrier we can just the other first min
    
    //what about accumulating values ?
    //aren't we supposed to solve it on the origial grid ?
    //yes but the numbers on the previous row is valid 
    //and the only way to get to this row is to 
    //compute the min for the previous row; also we don't 
    //care about the position choice made two rows 
    //above current row - just the previous row matters
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i = 1; i<n; i++){
            int fmin = 1e9;
            int smin = 1e9;
            for(int j = 0; j<n; j++){
                if(arr[i-1][j]<fmin){
                    smin = fmin;
                    fmin = arr[i-1][j];
                }
                else if(arr[i-1][j]<smin){
                    smin = arr[i-1][j];
                }
            }
            for(int j = 0; j<n; j++){
                arr[i][j] += (arr[i-1][j]==fmin?smin:fmin);
            }
        }
        return *min_element(arr[n-1].begin(), arr[n-1].end());
        //for(const auto& it : fm){
        //    cout<<it.first<<" "<<it.second<<endl;
        //}
        //for(const auto& it : sm){
        //    cout<<it.first<<" "<<it.second<<endl;
        //}
        //auto fmin = fm[0];
        //auto smin = sm[0];
        //int res = /*min(*/dfs(1, fmin, arr[0][fmin], fm, sm, arr);/*, dfs(1, smin, arr[0][smin], fm, sm, arr));*/
        //return res;
    }
};
