class Solution {
public:
    vector<int> accum;
    int r;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i = 0;i<w.size(); i++){
            sum+=w[i];
            accum.push_back(sum);
        }
        r = sum;
    }
    
    int pickIndex() {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(1,r); 
        int n = dist(rng);
        auto it = lower_bound(begin(accum), end(accum), n);
        int res = it-begin(accum);
        cout<<"n = "<<n<<"; res = "<<res<<endl;
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
