class Solution {
public:
    int tribonacci(int n) {
        int n0 = 0;
        int n1 = 1;
        int n2 = 1;
        int n3 = 0;
        if(!n) return 0;
        if(n<=2) return 1;
        int i = 2;
        while(i<n){
            n3 = n2+n1+n0;
            n0 = n1;
            n1 = n2;
            n2 = n3;
            i++;
        }
        return n3;
    }
};
