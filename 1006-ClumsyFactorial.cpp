class Solution {
public:
    struct node{
        int v{};
        char c{};
        node(int _v):v(_v), c{'&'}{}
        node(char _c):c(_c), v(0){}
    };
    void print(const vector<node>& n){
        for(const auto& t : n){
            if(t.v) cout<<t.v<<" ";
            else cout<<t.c<<" ";
        }
        cout<<endl;
    }
    int clumsy(int N) {
        vector<node> n;
        vector<char> ops = {'*', '/', '+', '-'};
        int opsp = 0;
        for(int i = N; i>=1; i--){
            n.push_back(node(i));
            if(i-1)
                n.push_back(node(ops[opsp]));
            opsp++;
            opsp%=4;
        }
        //print(n);
        vector<node> nn;
        for(int i = 0; i<n.size(); i++){
            if(!n[i].v&&n[i].c=='*'){
                nn.pop_back();
                nn.push_back(node(n[i-1].v*n[i+1].v));
                i++;
            }else{
                nn.push_back(n[i]);
            }
        }
        //print(nn);
        vector<node> nnn;
        for(int i = 0; i<nn.size(); i++){
            if(!nn[i].v&&nn[i].c=='/'){
                nnn.pop_back();
                nnn.push_back(node(nn[i-1].v/nn[i+1].v));
                i++;
            }else{
                nnn.push_back(nn[i]);
            }
        }
        //print(nnn);
        vector<node> nnnn;
        for(int i = 0; i<nnn.size(); i++){
            if(!nnn[i].v&&nnn[i].c=='-'){
                nnnn.push_back(nnn[i+1].v*-1);
                i++;
            }else {
                nnnn.push_back(nnn[i]);
            }
        }
        //print(nnnn);
        int res{};
        for(int i = 0; i<nnnn.size(); i++){
            res+=nnnn[i].v;
        }
        return res;
    }
};
