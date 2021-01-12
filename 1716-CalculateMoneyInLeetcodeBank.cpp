class Solution {
public:
    int totalMoney(int n) {
        int res{};
        int w = 1;
        for(int i = 0; i<n;){
            int a = w;
            for(int j = 0; j<7; j++){
                if(i<n) res+=a;
                else break;
                i++;
                a++;
            }
            w++;
        }
        return res;
    }
};
