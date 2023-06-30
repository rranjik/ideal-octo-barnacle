class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& p) {
        int l = 0;
        int r = min_element(p.begin(), p.end(), [](const auto& a, const auto& b){return a.size()<b.size();})->size();
        long long base = 100001;
        long long mod = 100000000019;
        while(l<r){
            auto m = (l+r+1)/2;
            unordered_set<long long> hs;
            //for every path as we continue find a non-empty intersection or if this was just the first path
            for(int i = 0; i<p.size()&&(i==0||!hs.empty()); i++){
                long long hash = 0;
                long long div = 1;
                unordered_set<long long> intersect;
                for(int j = 0; j<p[i].size(); j++){
                    hash = ((hash*base)+(p[i][j]))%mod;
                    if(j>=m)
                        hash = (mod+hash-(div*p[i][j-m]%mod))%mod;
                    else 
                        div = (div*base)%mod;
                    //if this sub-path has sufficient length and if we've seen this before (or if this is just the first path - push all m length sub-paths)
                    if(j>=m-1&&(i==0||hs.count(hash))){
                        intersect.insert(hash);
                    }
                }
                swap(intersect, hs);
            }
            if(hs.empty()) r = m-1;
            else l = m;
        }
        return l;
    }
};
