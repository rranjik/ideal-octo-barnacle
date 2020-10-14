class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //prefix sum occurances 
        //given a prefix sum -> list of indices where the sum
        //happened
        unordered_map<int, vector<int>> psumocc;
        psumocc.insert({0, {-1}});
        int prevsum = 0;
        vector<int> psum(nums.size(), 0);
        for(int i = 0; i<nums.size(); i++){
            auto newsum = prevsum+(nums[i]?nums[i]:-1);
            psumocc[newsum].push_back(i);
            psum[i] = newsum;
            prevsum = newsum;
        }
        //for(const auto& ps : psum) cout<<ps<<" "; cout<<endl;
        //for(const auto& it : psumocc){
        //    cout<<it.first<<": ";
        //    for(const auto& i : it.second) cout<<i<<" ";
        //    cout<<endl;
        //}
        int res = 0;
        for(int i = 0; i<psum.size(); i++){
            auto sumhere = psum[i];
            auto target = sumhere;
            if(psumocc.find(target)!=psumocc.end()){
                res = max(res, i-(*(begin(psumocc[target]))));
            }
        }
        return res;
    }
};
