class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int sum{};
        int i = 0; 
        int res{};
        int j = 0;
        while(j<A.size()){
            //cout<<"i = "<<i<<" j = "<<j<<" sum = "<<sum<<endl;
            if(A[j]) sum++;
            while(sum>S&&i<j){
                if(A[i]) sum--;
                i++;
            }
            if(sum==S)res++;
            for(int left = i; sum==S&&left<j&&A[left]==0; left++) res++;
            j++;
        }
        return res;
    }
};
