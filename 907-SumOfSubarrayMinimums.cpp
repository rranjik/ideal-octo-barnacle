class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        vector<int> left(A.size());
        vector<int> right(A.size());
        stack<int> ple;
        stack<int> nle;
        for(int i = 0; i<A.size(); i++) left[i]=(i+1);
        for(int i = 0; i<A.size(); i++) right[i] = A.size()-i;
        for(int i = 0; i<A.size(); i++){
            while(!ple.empty()&&A[ple.top()]>A[i]){
                ple.pop();
            }
            left[i]=(ple.empty())?i+1:i-ple.top();
            ple.push(i);
            while(!nle.empty()&&A[nle.top()]>A[i]){
                right[nle.top()] = i-nle.top();
                nle.pop();
            }
            nle.push(i);
        }
        int res = 0; 
        int mod = 1e9+7;
        for(int i = 0; i<A.size(); i++){
            res = (res + A[i]*left[i]*right[i])%mod;
        }
        return res;
    }
};
