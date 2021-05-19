class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        int t = 1;
        while(m1>=t||m2>=t){
            if(m1>=m2&&m1>=t){
                m1-=t;
            }else{
                m2-=t;
            }
            t++;
        }
        return {t, m1, m2};
    }
};
