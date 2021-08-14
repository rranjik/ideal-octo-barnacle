class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int cl = candies;
        vector<int> res(n);
        int tg = 1;
        while(cl){
            for(int i = 0; i<n; i++){
                if(tg<=cl){
                    res[i]+=tg;
                    cl-=tg;
                    tg++;
                }else{
                    res[i]+=cl;
                    cl=0;
                    break;
                }
            }
        }
        return res;
    }
};
