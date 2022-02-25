int m{};
int k{};
class Solution {
public:
    int n{};
    struct unionfind{
        struct node{
            int p;
            int c;
            node(int _p, int _c): p(_p), c(_c){}
        };
        vector<node> nodes;
        unionfind(int n){
            for(int i = 0; i<n; i++){
                nodes.push_back(node(i, 1));
            }
        }
        int find(int r){
            if(nodes[r].p==r) return r;
            return nodes[r].p = find(nodes[r].p);
        }
        bool uniun(int a, int b){
            int ap = find(a);
            int bp = find(b);
            if(ap==bp) return false;
            if(nodes[ap].c>=nodes[bp].c){
                //cout<<"conneting "<<bp<<" to "<<ap<<endl;
                nodes[bp].p = ap;
                //cout<<"size of "<<ap<<" is "<<nodes[ap].c<<" already "<<" and size of "<<bp<<"is "<<nodes[bp].c<<" already";
                m+=(nodes[ap].c/k);
                m+=(nodes[bp].c/k);
                //cout<<" so adding back "<<(nodes[ap].c/k)+(nodes[bp].c/k)<<endl;
                nodes[ap].c+=nodes[bp].c;
                auto res = nodes[ap].c;
                //cout<<"removing "<<res/k<<endl;
                m-=(res/k);
                if(!m) return true;
                return false;
            }
                //cout<<"conneting "<<ap<<" to "<<bp<<endl;
            nodes[ap].p = bp;
                //cout<<"size of "<<ap<<" is "<<nodes[ap].c<<" already "<<" and size of "<<bp<<"is "<<nodes[bp].c<<" already";
            m+=(nodes[ap].c/k);
            m+=(nodes[bp].c/k);
                //cout<<" so adding back "<<(nodes[ap].c/k)+(nodes[bp].c/k)<<endl;
            nodes[bp].c+=nodes[ap].c;
            auto res = nodes[bp].c;
                //cout<<"removing "<<res/k<<endl;
            m-=(res/k);
            if(!m) return true;
            return false;
        }
    };
    int minDays(vector<int>& bloomDay, int _m, int _k) {
        int res{};
        n = bloomDay.size();
        k = _k;
        m = _m;
        if(n<m*k) return -1;
        multimap<int, int> b;
        for(int i = 0; i<bloomDay.size(); i++){
            b.insert({bloomDay[i], i});
            //b[bloomDay[i]] = i;
        }
        if(k==1){
            int i{};
            for(const auto& it : b){
                i++;
                if(i>=m) return it.first;
            }
        }
        unionfind uf(n);
        int cc = n;
        int szcc = 1;
        vector<bool> f(n, false);
        for(const auto& it : b){
            //cout<<"today is day "<<it.first<<endl;
            auto day = it.first;
            auto plant = it.second;
            f[plant] = true;
            if(plant-1>=0&&f[plant-1]){
                if(uf.uniun(plant-1, plant)) {
                    return it.first;
                }
            }
            if(plant+1<n&&f[plant+1]){
                if(uf.uniun(plant+1, plant)) {
                    return it.first;
                }
            }
            //cout<<"after day "<<it.first<<" # of bouq required = "<<m<<endl;
        }
        return -1;
    }
};
