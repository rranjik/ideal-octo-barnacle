class Solution {
public:
    int wateringPlants(vector<int>& plants, int c) {
        int p = -1;
        int w = c;
        int res = 0;
        for(int i = 0; i<plants.size(); i++){
            int r = plants[i];
            if(r<=w){
                res++;
                w-=r;
            }else{
                res++;  res += 2*i;
                w=(c-r);
            }
        }
        return res;
    }
};
