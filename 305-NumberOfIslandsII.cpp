class unionfind{
public:
    class Node{
    public:
        bool lw;
        int parent;
        int count;
    };
    vector<Node> nodes;
    unionfind(int n){
        nodes = vector<Node>(n);
        for(int i = 0; i<n; i++){
            nodes[i].parent = i;
            nodes[i].count = 1;
            nodes[i].lw = false;
        }
    }
    int find(int n){
        if(nodes[n].parent!=n){
            nodes[n].parent = find(nodes[n].parent);
        }
        return nodes[n].parent;
    }
    void addLand(int n){
        nodes[n].lw = true;
    }
    bool isLand(int n){
        return nodes[n].lw;
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
    int n;
    int m;
    int flatAddress(pair<int, int> c){
        return (c.first*n)+c.second;
    }
    bool isValidCoor(pair<int, int> c){
        return c.first>=0&&c.first<m&&c.second>=0&&c.second<n;
    }
    unordered_set<int> knownIslands;
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        this->m = m;
        this->n = n;
        unionfind uf(m*n);
        vector<int> res;
        int prev = 0;
        for(const auto& p : positions){
            auto c = make_pair(p[0], p[1]);
            auto fac = flatAddress(c);
            if(uf.isLand(fac)) 
            {
                res.push_back(prev);
                continue;
            }
            auto l = make_pair(p[0], p[1]-1);
            auto r = make_pair(p[0], p[1]+1);
            auto b = make_pair(p[0]+1, p[1]);
            auto u = make_pair(p[0]-1, p[1]);
            uf.addLand(fac);
            auto left = false; auto right = false;
            auto up = false; auto bottom = false;
            if(isValidCoor(l)&&uf.isLand(flatAddress(l))){
                left = uf.uniun(fac, flatAddress(l));
            }
            if(isValidCoor(r)&&uf.isLand(flatAddress(r))){
                right = uf.uniun(fac, flatAddress(r));
            }
            if(isValidCoor(b)&&uf.isLand(flatAddress(b))){
                bottom = uf.uniun(fac, flatAddress(b));
            }
            if(isValidCoor(u)&&uf.isLand(flatAddress(u))){
                up = uf.uniun(fac, flatAddress(u));
            }
            int numberOfNewUnions = 0;
             numberOfNewUnions+=
                 ((left?1:0)+(right?1:0)+(up?1:0)+(bottom?1:0));
            
            if(!numberOfNewUnions){
                prev++;
            }else{
                //auto nni = prev - numberOfNewUnions - 1;
                prev-=(numberOfNewUnions-1);
            }
            //auto ni = uf.find(fac);
            //if(knownIslands.find(ni)==knownIslands.end()){
            //    knownIslands.insert(ni);
            //}else{
            //    unordered_set<int> nKI;
            //    nKI.insert(ni);
            //    for(const auto& i : knownIslands){
            //        nKI.insert(uf.find(i));
            //    }
            //    knownIslands = nKI;
            //}
            res.push_back(prev);
        }
        return res;
    }
};
