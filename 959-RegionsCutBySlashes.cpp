//template <typename T>
class unionfind{
public:
    using node = pair<int, int>;
    vector<node> nodes;
    unionfind(int n){
        nodes = vector<node>(n);
        for(int i = 0; i<n ; i++){
            nodes[i].first = i;
            nodes[i].second = 1;
        }
    }
    int find(int v){
        if(nodes[v].first!=v)
            nodes[v].first = find(nodes[v].first);
        else return v;
        return nodes[v].first;
    }
    void uniun(int a, int b){
        int ap = find(a);
        int bp = find(b);
        if(ap!=bp){
            if(nodes[ap].second>=nodes[bp].second){
                nodes[bp].first = ap;
                nodes[ap].second = nodes[ap].second + nodes[bp].second;
            }else{
                nodes[ap].first = bp;
                nodes[bp].second = nodes[ap].second + nodes[bp].second;
            }
        }
    }
    void print(){
        for(int i = 0; i<nodes.size(); i++){
            cout<<i<<"'s parent = "<<
                nodes[i].first<<"; i's count = "<<nodes[i].second<<endl;
        }
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        unionfind uf(n*n*4);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                //uf.print();
                char c = grid[i][j];
                int cell = ((i*n)+j)*4;
                if(c=='\\'){
                   uf.uniun(cell+1, cell+2);
                   uf.uniun(cell+0, cell+3);
                }
                else if(c=='/'){
                   uf.uniun(cell+0, cell+1);
                   uf.uniun(cell+2, cell+3);
                }else {
                   uf.uniun(cell+1, cell+2);
                   uf.uniun(cell+0, cell+3);
                   uf.uniun(cell+1, cell+0);
                }
                if(i-1>=0){
                    int topcell = ((i-1)*n+j)*4;
                    uf.uniun(cell+0, topcell+2);
                }
                if(j-1>=0){
                    int leftcell = ((i)*n+j-1)*4;
                    uf.uniun(cell+1, leftcell+3);
                }
                if(j+1<n){
                    int rightcell = ((i)*n+j+1)*4;
                    uf.uniun(cell+3, rightcell+1);
                }
                if(i+1<n){
                    int botcell = ((i+1)*n+j)*4;
                    uf.uniun(cell+2, botcell+0);
                }
            }
        }
        int res = 0;
        for(int i = 0; i<n*n*4; i++){
            if(i==uf.find(i)){
                res++;
            }
        }
        //uf.print();
        return res;
    }
};
