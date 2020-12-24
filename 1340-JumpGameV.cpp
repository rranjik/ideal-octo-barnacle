class Solution {
public:
    unordered_map<int, int> c;
    int dp(int i){
        if(c.find(i)!=c.end()) return c[i];
        v[i] = true;
        //cout<<"i = "<<i<<endl;
        int x = 1;
        int res = 0;
        while(x<=d){
            if(i+x<N&&a[i+x]<a[i]){
                //cout<<"from  i = "<<i<<" to j = "<<i+x<<endl;
                res = max(res, dp(i+x) +1);
            }else break;
            x++;
        }
        x = 1;
        while(x<=d){
            if(i-x>=0&&a[i-x]<a[i]){
                //cout<<"from  i = "<<i<<" to j = "<<i-x<<endl;
                res = max(res, dp(i-x)+1);
            }else break;
            x++;
        }
        //cout<<"i = "<<i<<" returns "<<res<<endl;
        c[i] = res;
        return res;
    }
    vector<int> a;
    vector<bool> v;
    int N = 0;
    int d;
    int maxJumps(vector<int>& arr, int d) {
        this->d = d;
        N = arr.size();
        if(!N) return 0;
        if(!d) return 0;
        a = arr;
        v = vector<bool>(N, false);
        int res = 0;
        //res = dp(10);
        for(int i = 0; i<N; i++){
            if(!v[i]){
               res = max(res, dp(i)+1);
            }
        }
        return res;
    }
};
