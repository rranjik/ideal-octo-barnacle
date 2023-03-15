class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int h = 0;
        for(int i = 0; i<gain.size(); i++){
            h +=gain[i];
            res = max(h, res);
        }
        return res;
    }
};
