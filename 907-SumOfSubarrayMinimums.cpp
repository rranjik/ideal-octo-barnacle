class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<int> ple(n, -1); vector<int> nle(n, n);
        stack<int> s;
        for(int i = 0; i<n; i++){
            while(!s.empty()&&a[s.top()]>a[i]) s.pop();
            if(!s.empty()) ple[i] = s.top();
            s.push(i);
        }
        s = stack<int>();
        for(int i = n-1; i>=0; i--){
            while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
            if(!s.empty()) nle[i] = s.top();
            s.push(i);
        }
        for(const auto& x : ple) cout<<x<<" "; cout<<endl;
        for(const auto& x : nle) cout<<x<<" "; cout<<endl;
        long long res = 0;
        for(int i = 0; i<n; i++){
            res+=((long long)(i-(ple[i]+1)+1)*(long long)(nle[i]-1-i+1)*(long long)a[i]);
            res%=((int)1e9+7);
        }
        return res;
    }
};
