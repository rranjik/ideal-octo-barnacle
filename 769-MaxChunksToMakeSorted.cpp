class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> c(arr.size());
        int cum = 0;
        int res = 0;
        for(int i = 0; i<arr.size(); i++){
            c[arr[i]] = 1;
            cum = 0;
            for(int j = 0; j<=i; j++)
                cum+=c[j];
            if(cum==i+1){
                res++;
            }
        }
        return res;
    }
};
