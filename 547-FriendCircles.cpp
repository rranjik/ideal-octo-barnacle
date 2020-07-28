class unionfind{
public:
    class Node{
    public:
        int parent;
        int count;
    };
    vector<Node> nodes;
    unionfind(int n){
        nodes = vector<Node>(n);
        for(int i = 0; i<n; i++){
            nodes[i].parent = i;
            nodes[i].count = 1;
        }
    }
    int find(int n){
        if(nodes[n].parent!=n){
            nodes[n].parent = find(nodes[n].parent);
        }
        return nodes[n].parent;
    }
    
    bool uniun(int a, int b){
        int ap = find(a);
        int bp = find(b);
        if(ap!=bp){
            if(nodes[ap].count>nodes[bp].count){
                nodes[bp].parent = ap;
                nodes[ap].count+=nodes[bp].count;
            }else{
                nodes[ap].parent = bp;
                nodes[bp].count+=nodes[ap].count;
            }
            return true;
        }else return false;
    }
    
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        unionfind uf(M.size());
        for(int i = 0; i<M.size(); i++){
            for(int j = i+1; j<M.size(); j++){
                if(M[i][j]){
                    uf.uniun(i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i<M.size(); i++){
            if(uf.find(i)==i)res++;
        }
        return res;
    }
};
