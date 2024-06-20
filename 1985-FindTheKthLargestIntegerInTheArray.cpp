class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        std::sort(nums.begin(), nums.end(), [](const string& a, const string& b){
            if(a.size()!=b.size()) return a.size()<b.size();
            for(int i = 0; i<a.size(); i++){
                int lda = a[i]-'0';
                int ldb = b[i]-'0';
                //cout<<"lda = "<<lda<<" ldb = "<<ldb<<endl;
                if(lda!=ldb) return lda<ldb;
            }
            return false;
        });
        
        //for(const auto& s : nums) cout<<s<<" "; cout<<endl;
        int n = nums.size();
        cout<<"n = "<<n<<endl;
        return nums[n-k];
    }
};
