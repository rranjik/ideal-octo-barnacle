class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ne = 0;
        int no = 0;
        int sum = 0;
        long long res = 0;
        int mod = 1e9+7;
        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];
            if(sum%2){
                res+=ne;
                res%=mod;
                res++;
                no++;
            }else{
                res+=no;
                res%=mod;
                ne++;
            }
        }
        return res;
    }
};
