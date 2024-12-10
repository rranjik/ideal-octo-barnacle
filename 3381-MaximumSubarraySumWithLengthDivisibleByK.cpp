class Solution {
public:
    long long maxSubarraySum(vector<int>& A, int k) {
        vector<int> a = {0};
        a.insert(a.end(), A.begin(), A.end());
        //auto a= A;
        int n = a.size();
        vector<long long> ps(n+2);
        unordered_map<int, long long> m;
        long long res = numeric_limits<long long>::min();
        ps[0] = a[0];
        m[0] = min<long long>(0, ps[0]);
        for(int i = 1; i<n; i++){
            ps[i] = ps[i-1]+a[i];
            //cout<<ps[i]<<" ";
            auto km = i%k;
            if(m.find(km)!=m.end()){
                res = max({res, ps[i]-m[km]});
            }
            //cout<<"i = "<<i<<" km = "<<km<<endl;
            if(m.find(km)==m.end()){
                m[km] = ps[i];
            }else{
                m[km] = min<long long>(m[km], ps[i]);
            }
            //for(const auto& [k, v]: m) cout<<k<<"->"<<v<<"; "; cout<<endl;
        }
        return res;
    }
};
