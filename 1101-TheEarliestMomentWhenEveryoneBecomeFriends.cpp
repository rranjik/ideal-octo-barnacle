struct unionfind{
    struct node{
        int p{};
        int c{};
        node(int _p, int _c):p(_p), c(_c){}
    };
    vector<node> nodes;
    unionfind(int n){
        for(int i = 0; i<n; i++){
            nodes.push_back(node(i, 1));
        }
    }
    int find(int n){
        if(nodes[n].p==n) return n;
        nodes[n].p = find(nodes[n].p);
        return nodes[n].p;
    }
    
    bool uniun(int a, int b){
        auto ap = find(a);
        auto bp = find(b);
        if(ap!=bp){
            if(nodes[ap].c>nodes[bp].c){
                nodes[bp].p = ap;
                nodes[ap].c+=nodes[bp].c;
            }else{
                nodes[ap].p = bp;
                nodes[bp].c+=nodes[ap].c;
            }
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        int cc = N;
        unionfind uf(N);
        sort(begin(logs), end(logs), [](const auto& a, const auto& b){return a[0]<b[0];});
        for(int i = 0; i<logs.size(); i++){
            if(uf.uniun(logs[i][1], logs[i][2])){
                cc--;
                if(cc==1) return logs[i][0];
            }
        }
        return -1;
    }
};
