class Solution {
public:
    double dp(int i, int k){
        if(c.find(i)!=c.end()&&c[i].find(k)!=c[i].end()) return c[i][k];
        //cout<<"i = "<<i<<" k = "<<k<<" called "<<endl;
        if(i<0) return 0;
        if(k==1){
            int sum{};
            for(int j = i; j>=0; j--){
                sum+=a[j];
            }
            auto res = sum*1.0/(i+1);
            //cout<<"i = "<<i<<" k = "<<k<<" returns "<<res<<endl;
            c[i][k] = res;
            return res;
        }
        int sum{};
        double res = numeric_limits<double>::min();
        for(int j = i; j>=0; j--){
            sum+=a[j];
            int nn = i-j+1;
            double avghere = (sum*1.0)/nn;
                res = max(res, avghere+dp(j-1, k-1));
            
        }
        //cout<<"i = "<<i<<" k = "<<k<<" returns "<<res<<endl;
        c[i][k] = res;
        return res;
    }
    vector<int> a;
    unordered_map<int, unordered_map<int, double>> c;
    double largestSumOfAverages(vector<int>& A, int K) {
        this->a = A;
        int n = A.size();
        return dp(n-1, K);
    }
};
