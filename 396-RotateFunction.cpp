class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sum{}; 
        long long iteration{};
        for(int i = 0; i<A.size(); i++){
            sum+=A[i];
            iteration+=(A[i]*i);
        }
        long long res {iteration};//init with 0*A[0]+1*A[1]+2*A[2]+...+(n-1)*A[n-1]
        int n = A.size();
        for(int j = n-1; j>=0; j--){
            iteration = iteration + sum - (A[j]*(A.size()));
            res = max(res, iteration);
        }
        return res;
    }
};
