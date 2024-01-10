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
    void conn(int a, int b){
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
        }
    }
    bool isconn(int a, int b){
        return find(a)==find(b);
    }
    void reset(int a){
        nodes[a].p = a;
        nodes[a].c = 1;
    }
};
class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int firstPerson) {
        sort(m.begin(), m.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2]<b[2];
        });
        unionfind uf(n);
        uf.conn(0, firstPerson);
        //This Time
        vector<int> ttime;
        for(int i = 0; i<m.size();){
            ttime.clear();
            int time = m[i][2];
            while(i<m.size()&&m[i][2]==time){
                uf.conn(m[i][0], m[i][1]);
                ttime.push_back(m[i][0]);
                ttime.push_back(m[i][1]);
                i++;
            }
            for(const auto p : ttime){
                if(!uf.isconn(0, p)) uf.reset(p);
            }
        }
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(uf.isconn(0, i)) res.push_back(i);
        }
        return res;
    }
};
