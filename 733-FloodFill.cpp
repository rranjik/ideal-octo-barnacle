class Solution {
public:
    vector<vector<bool>> v;
    int m;
    int n;
    void dfs(int x, int y){
        if(x<0||y<0||x>=m||y>=n||v[x][y]||im[x][y]!=t) return;
        v[x][y] = true;
        im[x][y] = newColor;
        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y+1);
        dfs(x, y-1);
    }
    int newColor;
    int t;
    vector<vector<int>> im;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        if(!m) return image;
        n = image[0].size();
        im = image;
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        this->t = image[sr][sc];
        this->newColor = newColor;
        dfs(sr, sc);
        return im;
    }
};
