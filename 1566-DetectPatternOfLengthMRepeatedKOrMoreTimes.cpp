class Solution {
public:
    bool match(int ps, int pe, int j, int k){
        cout<<"matching from "<<ps<<" to "<<pe<<"; to: from "<<j<<" to "<<j+m-1<<endl;
        if(j+m>n) return false;
        for(int i = j; i<j+m; i++){
            if(arr[ps]!=arr[i]) return false;
            ps++;
        }
        return true;
    }
    int n;
    int m;
    vector<int> arr;
    bool containsPattern(vector<int>& arr, int m, int k) {
        n = arr.size();
        this->arr = arr;
        this->m = m;
        for(int i = 0; i<n-m; i++){
            int nm = 0;
            int ps = i;
            int pe = i+m-1;
            for(int j = i+m; j<n;){
                auto m = match(ps, pe, j, k);
                if(m){
                    nm++;
                    j+=m;
                    if(nm>=k-1) return true;
                }else{
                    break;
                }
            }
        }
        return false;
    }
};
