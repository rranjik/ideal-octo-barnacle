class Solution {
public:
    vector<int> transformArray(vector<int>& res) {
        bool changed = false;
        do {
            vector<int> r = res;
            changed = false;
            for(int i = 1; i<res.size()-1; i++){
                if(res[i]<res[i-1]&&res[i]<res[i+1]) {
                    cout<<"i="<<i<<endl;
                    r[i] = res[i]+1;
                    changed = true;
                }else if(res[i]>res[i-1]&&res[i]>res[i+1]){
                    cout<<"i="<<i<<endl;
                    r[i] = res[i]-1;
                    changed = true;
                }
            }
            swap(r, res);
        }while(changed);
        return res;
    }
};
