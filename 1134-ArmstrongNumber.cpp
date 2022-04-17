class Solution {
public:
    bool isArmstrong(int N) {
        int n = N;
        int nd = 0;
        vector<int> ds;
        while(n){
            int d = n%10;
            n/=10;
            ds.push_back(d);
        }
        int k = ds.size();
        int p = 0;
        for(int i = 0; i<k; i++){
            p+=(pow(ds[i], k));
        }
        cout<<"p = "<<p<<endl;
        return p==N;
    }
};
