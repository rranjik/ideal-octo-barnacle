class Solution {
public:
    int minOperations(int n) {
        int avg = (n%2)?((n/2)*2+1):( ((((n/2)*2)+1) +(((n/2)-1)*2)+1)/2 );
        cout<<"avg = "<<avg;
        int res{};
        for(int i = 0; i<n/2; i++){
            res += avg-(i*2+1);
        }
        return res;
    }
};
