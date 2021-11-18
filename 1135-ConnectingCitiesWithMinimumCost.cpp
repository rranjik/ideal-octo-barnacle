class Solution {
public:
    struct unionfind{
        struct node{
            int p{};
            int c{};
        };
        vector<node> nodes;
        unionfind(int n){
            nodes = vector<node>(n+1);
            for(int i = 0; i<n+1; i++){
                nodes[i].p = i;
            }
        }
        int find(int n){
            
            if(nodes[n].p!=n) nodes[n].p = find(nodes[n].p);
            return nodes[n].p;
        }
        void uniun(int a, int b){
            int ap = find(a);
            int bp = find(b);
            if(ap!=bp){
                if(nodes[ap].c>nodes[bp].c){
                    nodes[bp].p = ap;
                    nodes[ap].c+=nodes[bp].c;
                }else{
                    nodes[ap].p = bp;
                    nodes[bp].c+=nodes[ap].c;
                }
            }
        }
    };
    int minimumCost(int N, vector<vector<int>>& connections) {
        unionfind uf(N);
        sort(connections.begin(), connections.end(), 
             [](const vector<int>& a, const vector<int>& b){return a[2]<b[2];});
        int res{};
        int added{};
        for(const auto& c : connections){
            //cout<<"looking at "<<c[0]<<" -> "<<c[1]<<" : "<<c[2]<<endl;
            //c0 set and c1 set
            auto c0s = uf.find(c[0]);
            auto c1s = uf.find(c[1]);
            //cout<<c[0]<<"'s parent is "<<c0s<<" "<<c[1]<<"'s parent is "<<c1s<<endl;
            if(c0s!=c1s){
                uf.uniun(c0s, c1s);
                added++;
                res+=c[2];
            }
        }
        if(added==N-1) return res;
        return -1;
    }
};
