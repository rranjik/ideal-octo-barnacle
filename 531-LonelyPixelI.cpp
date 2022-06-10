class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> cols(n, 0);
        vector<int> rows(m, 0);
        for(int i = 0; i<m; i++){
            int c = 0;
            for(int j = 0; j<n; j++){
                if(picture[i][j]=='B') c++;
            }
            rows[i]=c;
        }
        for(int j = 0; j<n; j++){
            int c = 0;
            for(int i = 0; i<m; i++){
                if(picture[i][j]=='B') c++;
            }
            cols[j] = c;
        }
        int res = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(picture[i][j]=='B'){
                    if(rows[i]==1&&cols[j]==1) res++;
                }
            }
        }
        return res;
    }
};
