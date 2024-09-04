class unionfind{
public:
    vector<int> n;
    unionfind(int s){
        n = vector<int>(s);
        for(int i = 0; i<s; i++){
            n[i] = i;
        }
    }
    int find(int e){
        if(n[e]!=e){
            n[e] = find(n[e]);
        }
        return n[e];
    }
    void uniun(int a, int b){
        int ap = find(a);
        int bp = find(b);
        n[ap] = bp;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& A) {
        //copied from 1102. Path With Maximum Minimum Value
        int m = A.size();
        if(!m) return 0;
        int n = A[0].size();
        unionfind uf(m*n);
        vector<pair<int, int>> ids;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ids.push_back(make_pair(i, j));
            }
        }
        vector<bool> v(m*n, false);
        sort(begin(ids), end(ids), [&]
             (const pair<int, int>& a, const pair<int, int>&b)
             {return A[a.first][a.second]<A[b.first][b.second];});
        vector<pair<int, int>> dirs{{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(auto id : ids){
            //start with the square that has the least height
            int x = id.first; int y = id.second; int k = x*n+y;
            //mark it as visited
            v[k] = true;
            //consider the four-directiionally adjacent squares
            for(auto d : dirs){
                //locate the adjacent cells
                int xx = x+d.first; int yy = y+d.second; int kk =xx*n+yy;
                //if it's present, and it was also visited
                //union it together
                if(xx>=0&&yy>=0&&xx<m&&yy<n&&A[xx][yy]<A[x][y]){
                    //visited cell here, is an indication
                    //that it has value that is definitely 
                    //higher than everthing we've already 
                    //visited
                    uf.uniun(k, kk);
                    //an unvisited cell may be adjacent to 
                    //you (x, y) but it might have a very 
                    //high value that you don't want to use yet.
                    //consider the example below
                }
            }
            if(uf.find(0) == uf.find(m*n-1)) return A[x][y];
        }
        return 0;
    }
};

/*
1  3
10 2

v  -
-  -

v  -
-  v

v  v
-  v

path formed, done.
*/
