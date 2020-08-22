class Solution {
public:
    unordered_set<int> s;
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
        for(const auto& n : nums){
            s.insert(n);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> copy = original;
        int n = original.size();
        random_device dev;
        mt19937 rng(dev());
        for(int i = 0; i<n; i++){
            uniform_int_distribution<mt19937::result_type> dist(i,n-1);
            swap(copy[i], copy[dist(rng)]);
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
