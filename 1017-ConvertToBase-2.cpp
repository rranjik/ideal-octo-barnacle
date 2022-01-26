class Solution {
public:
    string baseNeg2(int N) {
        string res;
        while(N){
            cout<<"N = "<<N<<endl;
            int rem = N%(-2);
            int q = N/(-2);
            if(rem<0) {q+=1; rem+=2; rem%=(-2);}
            cout<<"rem = "<<rem<<endl;
            res+=to_string(rem);
            N = q;
        }
        reverse(res.begin(), res.end());
        return res==""?"0":res;
    }
};
