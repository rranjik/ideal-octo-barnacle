class Solution {
public:
    int arrangeCoins(int nn) {
        long long n = nn;
        if(!n) return 0;
        long long s = 1;
        long long e = n;
        if(n==1) return 1;
        int res{};
        while(s<=e){
            int m = (e-s)/2+s;
            cout<<"s = "<<s<<" e = "<<e<<" m = "<<m<<endl;
            //long long stairs = (m*(m+1))/2;
            //cout<<"stairs = "<<stairs<<endl;
            if((m+1)%2){
                if((m+1)<=((2*n)/(m))){
                    res = max(res, m);
                    s = m+1;
                }else{
                    e = m-1;
                }
            }else {
                if((m)<=((2*n)/(m+1))){
                    res = max(res, m);
                    s = m+1;
                }else{
                    e = m-1;
                }
            }
        }
        return res;
    }
};
