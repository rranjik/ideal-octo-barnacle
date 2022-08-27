class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ps(n);
        long long sum = nums[0];
        ps[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            sum+=nums[i];
            ps[i]+=(nums[i]+ps[i-1]);
        }
        int ri = 1;
        int m = 1e9+7;
        for(int i = 0; i<n; i++){
            auto asi = ps[i]/(i+1);
            auto afsi = (n-i-1==0?0:(sum-ps[i])/(n-i-1));
            //cout<<"i = "<<i<<" "<<ps[i]<<" "<<sum-ps[i]<<" "<<asi<<" "<<afsi<<endl;
            auto ab = abs(asi-afsi);
            //cout<<"i = "<<i<<" ab = "<<ab<<endl;
            if(m>ab){
                ri = i;
                m = ab;
            }
        }
        return ri;
    }
};
