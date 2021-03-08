class Solution {
public:
    vector<bool> v;
    vector<int> l;
    vector<int> r;
    bool res = true;
    void dfs(int n){
        if(n==-1) return;
        cout<<"dfs@ "<<n<<"; l = "<<l[n]<<"; r = "<<r[n]<<endl;
        v[n] = true;
        if(l[n]!=-1&&v[l[n]]){
            res = false;
            return;
        }else if(l[n]!=-1) dfs(l[n]);
        
        if(r[n]!=-1&&v[r[n]]){
            res = false;
            return;
        }else if(r[n]!=-1) dfs(r[n]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        v = vector<bool>(n, false);
        l = leftChild;
        r = rightChild;
        for(int i =0; i<l.size(); i++){
            if(l[i]!=-1)
                v[l[i]] = true;
        }
        for(int i =0; i<r.size(); i++){
            if(r[i]!=-1)
                v[r[i]] = true;
        }
        int nr = 0;
        bool fr = false;
        int r = -1;
        for(int i =0; i<n; i++){
            if(!v[i]&&!fr) {
                cout<<"i = "<<i<<" could be a root"<<endl;
                r = i;
                fr = true;
                nr++;
            }else if(!v[i]&&fr) {
                cout<<"too many roots "<<endl;
                return false;
            }
        }
        if(!fr) return false;
        v = vector<bool>(n, false);
        cout<<"r = "<<r<<endl;
        dfs(r);
        for(int i = 0; i<n; i++){
            if(!v[i]) return false;
        }
        return res;
    }
};
