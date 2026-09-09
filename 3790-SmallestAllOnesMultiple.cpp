
class Solution {
public:
    vector<int> c = {
        1, 11, 111, 1111, 11111,
        111111, 1111111, 11111111,
        111111111, 1111111111
    };
    int minAllOneMultiple(int k) {
        long long x = 1;
        int times = 1e6;
        int len = 1;
        while(times>=0){
            if(x%k==0) return len;
            len++;
            x = x*10+1;
            x%=k;
            times--;
        }
        return -1;
    }
};
