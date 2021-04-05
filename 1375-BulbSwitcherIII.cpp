class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        auto n = light.size();
        vector<bool> bulbs(n);
        int count = 0;
        int res = 0;
        for(int i = 0; i<n; i++){
            bulbs[light[i]-1] = true;
            if(light[i]-1<i) count++;
            if(bulbs[i]) count++;
            if(count==i+1) res++;
        }
        return res;
    }
};
