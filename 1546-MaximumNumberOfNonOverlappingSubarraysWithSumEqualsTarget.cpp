class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        auto here = 0;
        m[0].push_back(-1);
        vector<int> p(nums.size());
        for(int i = 0; i<nums.size(); i++){
            auto n = nums[i];
            here+=n;
            p[i] = here;
            m[here].push_back(i);
        }
        //vector<pair<int, int>> invs;
        int le = -1;
        vector<pair<int, int>> res;
        for(int i = 0; i<p.size(); i++){
            auto req = p[i]-target;
            for(const auto& j : m[req]){
                if(j<=i&&j+1<nums.size()&&j+1<=i){
                    //invs.push_back({j+1, i});
                    pair<int, int> h({j+1, i});
                        if(h.first>le){
                            res.push_back(h);
                            le = h.second;
                        }
                }else if(j>i) break;
            }
        }
        return res.size();
        //sort(invs.begin(), invs.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.second<b.second;});
        ////for(const auto& i : invs){
        ////    cout<<"("<<i.first<<", "<<i.second<<")"<<" ";
        ////}
        //cout<<endl;
        //auto le = -1;
        //for(int i = 0; i<invs.size(); i++){
        //    if(invs[i].first>le){
        //        res.push_back(invs[i]);
        //        le = invs[i].second;
        //    }
        //}
        //return res.size();
    }
};
