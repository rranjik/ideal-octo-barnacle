struct unionfind{
    vector<int> p;
    vector<int> c;
    unionfind(){
        p = vector<int>(26);
        c = vector<int>(26, 1);
        for(int i = 0; i<26; i++){
            p[i] = i;
        }
    }
    int find(int n){
        cout<<"parent of "<<n<<" is "<<p[n]<<endl;
        if(p[n] != n){
            p[n] = find(p[n]);
        }
        return p[n];
    }
    void uniun(int a, int b){
        if(find(a)!=find(b)){
            auto ap = find(a);
            auto bp = find(b);
            if(c[ap]>c[bp]){
                p[bp] = ap;
                c[ap]+=c[bp];
            }
            else{
                p[ap] = bp;
                c[bp]+=c[ap];
            }
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unionfind uf;
        for(const auto& e : equations){
            auto v1 = e[0]-'a';
            auto v2 = e[3]-'a';
            auto q = e[1];
            if(q=='=')
            cout<<e[0]<<"=="<<e[3]<<endl;
            switch(q){
                case '=':
                    {
                        uf.uniun(v1, v2);
                    }
                    break;
            }
        }
        cout<<"here "<<endl;
        for(const auto& e : equations){
            auto v1 = e[0]-'a';
            auto v2 = e[3]-'a';
            auto q = e[1];
            if(q=='!')
            cout<<e[0]<<"!="<<e[3]<<endl;
            switch(q){
                case '!':
                    {
                        if(uf.find(v1)==uf.find(v2)) return false;
                    }
                    break;
            }
        }
        return true;
    }
};
