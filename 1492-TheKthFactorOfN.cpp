class Solution {
public:
    int kthFactor(int n, int k) {
        int s{};
        for(int i = 1; i<=n; i++){
            if(!(n%i)){
                s++;
                if(s==k) return i;
            }
        }
        return -1;
    }
};
