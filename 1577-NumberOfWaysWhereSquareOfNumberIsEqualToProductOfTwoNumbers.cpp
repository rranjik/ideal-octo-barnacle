class Solution {
public:
    int nt(vector<int>& a, vector<int>& b){
        unordered_map<int, vector<int>> am;
        unordered_map<int, vector<int>> bm;
        int res{};
        for(int i = 0; i<a.size(); i++) am[a[i]].push_back(i);
        for(int i = 0; i<b.size(); i++) bm[b[i]].push_back(i);
        for(int i = 0; i<a.size(); i++){
            long long n1s = ((long long)a[i])*((long long)a[i]);
            for(int j = 0; j<b.size(); j++){
                if(!(n1s%b[j])){
                    auto req = n1s/b[j];
                    //cout<<"n1s = "<<n1s<<" bj = "<<b[j]<<" req = "<<req<<endl;
                    if(bm.find(req)!=bm.end()){
                        auto u = upper_bound(bm[req].begin(), bm[req].end(), j);
                        auto ui = u-bm[req].begin();
                        if(ui<bm[req].size()){
                            //cout<<"found req from "<<ui<<" size = "<<bm[req].size()-1<<" j = "<<j<<endl;
                            res+=(bm[req].size()-ui);
                        }
                        //for(const auto& k : bm[req]){
                        //    if(j<k){
                        //        res++;
                        //    }
                        //}
                    }
                }
            }
        }
        return res;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return nt(nums1, nums2)+nt(nums2, nums1);
    }
};
