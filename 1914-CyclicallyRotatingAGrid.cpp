class Solution {
public:
    struct loc{
        int i; int j; int v;
        loc(int _i, int _j, int _v):i(_i), j(_j), v(_v){}
        loc(){}
        bool operator==(const loc& l){
            return l.i==i&&l.j==j;
        }
    };
    void rotate(vector<loc>& v, int k){
        auto n = v.size();
        k%=n;
        if(!k) return;
        vector<loc> temp;
        //cout<<"n = "<<n<<endl;
        for(int i = k; i<n; i++){
            temp.push_back(v[i]);
        }
        for(int i =0; i<k; i++){
            temp.push_back(v[i]);
        }
        for(int i = 0; i<temp.size(); i++){
            v[i].v = temp[i].v;
        }
    }
    vector<loc> getlayer(int up, int bo, int le, int ri, const vector<vector<int>>& g){
        //cout<<"up = "<<up<<" bo = "<<bo <<" le = "<<le<<" ri = "<<ri<<endl;
        loc last_add(up, le, g[up][le]);
        vector<loc> res;
        res.push_back(last_add);
        int right = le+1;
        while(right<=ri){
            res.push_back({up, right, g[up][right]});
            right++;
        }
        int down = up+1;
        while(down<=bo){
            res.push_back({down, ri, g[down][ri]});
            down++;
        }
        int left = ri-1;
        while(left>=le){
            res.push_back({bo, left, g[bo][left]});
            left--;
        }
        int above = bo-1;
        while(above>up){
            res.push_back({above, le, g[above][le]});
            above--;
        }
        return res;
    }
    void print(vector<loc> l){
        for(int i =0; i<l.size(); i++){
            cout<<"i = "<<l[i].i<<" j = "<<l[i].j<<" v = "<<l[i].v<<endl;
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(); 
        int n = grid[0].size();
        for(int i = 0, j = 0; i<m/2&&j<n/2; i++, j++){
            auto l = getlayer(i, m-i-1, j, n-j-1, grid);
            auto cl = l;
            cout<<"before rot "<<endl;
            print(l);
            cout<<"rot "<<endl;
            rotate(l, k);
            cout<<"after rotate "<<endl;
            print(l);
            for(int m = 0; m<l.size(); m++){
                grid[cl[m].i][cl[m].j] = l[m].v;
            }
        }
        return grid;
    }
};
