class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                auto c = sqrt(i*i+j*j);
                if(double(int(c))==c&&c<=n) {
                    cout<<"c = "<<c<<" i = "<<i<<" j = "<<j<<endl;
                    res+=2;
                }
            }
        }
        return res;
    }
};
