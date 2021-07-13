class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> w(nums.begin(), nums.begin()+k);
        auto mid = next(w.begin(), k/2);
        vector<double> res;
        for(int i = k; i<nums.size(); i++){
            auto prv = *mid;
            if(!(k%2)){
                prv = *(prev(mid));
            }
            res.push_back(((double)prv+(double)*mid)/2.0);
            
            w.insert(nums[i]);
            if(nums[i]<*mid)mid--;
            
            if(nums[i-k]<=*mid) mid++;
            w.erase(w.lower_bound(nums[i-k]));
        }
        auto prv = *mid;
        if(!(k%2)){
            prv = *(prev(mid));
        }
        res.push_back(((double)prv+(double)*mid)/2.0);
        return res;
    }
};
