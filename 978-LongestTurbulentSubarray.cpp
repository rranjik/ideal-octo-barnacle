enum class comp{N, G, L, E};
class Solution {
public:
    int n;
    vector<int> a;
    vector<int> res;
    vector<comp> s;
    int maxTurbulenceSize(vector<int>& A) {
        a = A;
        n = a.size();
        s = vector<comp>(n);
        res = vector<int>(n, 1);
        s[0] = comp::N;
        for(int i = 1; i<n; i++){
            if(a[i]<a[i-1]){
                s[i] = comp::L;
            } else if(a[i]>a[i-1]){
                s[i] = comp::G;
            } else {
                s[i] = comp::E;
            }
        }
        for(const comp& c : s){
            switch (c){
                case comp::E:
                    cout<<"E ";
                    break;
                case comp::N:
                    cout<<"N ";
                    break;
                case comp::L:
                    cout<<"L ";
                    break;
                case comp::G:
                    cout<<"G ";
                    break;
            }
        }
        cout<<endl;
        int r = 1;
        for(int i = 1; i<n; i++){
            if(s[i-1]==comp::L&&s[i]==comp::G){
                res[i] = res[i-1]+1;
            } else if(s[i-1]==comp::G&&s[i]==comp::L){
                res[i] = res[i-1]+1;
            } else if(s[i]!=comp::E){
                res[i] = 2;
            }
        }
        for(const int& g : res){
            r = max(r, g);
            cout<<g<<" ";
        }
        cout<<endl;
        return r;
    }
};
