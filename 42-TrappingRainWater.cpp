class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size()==0){
            return 0;
        }
        int res = 0;
        int size = h.size();
        vector<int> lm(size), rm(size);
        lm[0] = h[0];
        for(int i = 1; i<size; i++){
            lm[i] = max(h[i], lm[i-1]);
        }
        rm[size-1] = h[size-1];
        for(int i = size-2; i>=0; i--){
            rm[i] = max(h[i], rm[i+1]);
        }
        for(int i = 1; i<size-1; i++){
            res+=min(lm[i], rm[i])-h[i];
        }
        return res;
    }
};
