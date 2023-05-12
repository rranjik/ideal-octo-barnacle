class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> p;
        vector<int> op;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            p.push_back(i);
        }
        op = p;
        int res{};
        bool first = true;
        while(first||p!=op){
            for(int i = 0; i<n; i++){
                if(i%2){
                    arr[i] = p[n/2+(i-1)/2];
                }else{
                    arr[i] = p[i/2];
                }
            }
            p = arr;
            first = false;
            res++;
        }
        return res;
    }
};
