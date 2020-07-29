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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unionfind uf(edges.size());
        for(const auto& e :edges){
            if(uf.find(e[0]-1)!=uf.find(e[1]-1)){
                uf.uniun(e[0]-1, e[1]-1);
            }else{
                return e;
                //return edges.back();
            }
        }
        return vector<int>();
    }
};
