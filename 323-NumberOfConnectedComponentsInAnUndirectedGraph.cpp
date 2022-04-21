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
    void uniun(int a, int b){
        int ap = find(a);
        int bp = find(b);
        if(ap!=bp){
            if(nodes[ap].count>nodes[bp].count){
                nodes[bp].parent = ap;
                nodes[ap].count += nodes[bp].count;
            }else{
                nodes[ap].parent = bp;
                nodes[bp].count += nodes[ap].count;
            }
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unionfind uf(n);
        for(const auto& e : edges){
            uf.uniun(e[0], e[1]);
        }
        int res = 0;
        for(int i = 0; i<n; i++){
            if(uf.find(i)==i) res++;
        }
        return res;
    }
};
