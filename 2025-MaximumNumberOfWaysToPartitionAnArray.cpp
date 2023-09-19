class Solution {
public:
    int waysToPartition(vector<int>& A, int k) {
        int n = A.size();
        long long s = 0;
        int res = 0;
        vector<int> ps;
        unordered_map<int, int> pre, suf;
        for(const auto& a : A){
            s+=a;
            ps.push_back(s);
            suf[s]++;
        }
        suf[s]--;
        if(s%2==0){
            res = suf[s/2];
        }
        for(int i = 0; i<n; i++){
            int cur = 0;
            if(A[i]!=k){
                int news = s+k-A[i];
                if(news%2==0){
                    if(pre.find(news/2)!=pre.end())
                        cur+=pre[news/2];
                    if(i<n-1&&suf.find(news/2+A[i]-k)!=suf.end())
                        //cur+=suf[(news-k+A[i])/2];
                        cur+=suf[news/2+A[i]-k];
                }
            }
            res = max(res, cur);
            suf[ps[i]]--;
            pre[ps[i]]++;
        }
        return res;
    }
};
