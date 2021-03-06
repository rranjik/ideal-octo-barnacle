class Solution {
public:
    vector<int> closestDivisors(int num) {
        int cap = ceil(sqrt(num));
        int d1 = num+1;
        int d2 = num+2;
        vector<int> res;
        for(int i = cap; i>=1; i++){
            if(!(d1%i)){
                int j = d1/i;
                return {i, j};
            }
            if(!(d2%i)){
                int j = d2/i;
                return {i, j};
            }
        }
        return {};
    }
};
