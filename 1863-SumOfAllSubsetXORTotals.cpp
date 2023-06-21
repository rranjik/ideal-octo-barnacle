class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int s = nums.size();
        //cout<<"# of subsets = "<<(1<<s)<<endl;
        int sum{};
        for(int i = 0; i<(1<<s); i++){
            bitset<12> b = i;
            int xr{};
            bool count = true;
            //cout<<" i = "<<i<<endl;
            //cout<<" b = "<<b.to_string()<<endl;
            for(int j = 0; j<b.size(); j++){
            //cout<<"  j = "<<j<<endl;
                if(b[j]) {
                    //cout<<"  xoring "<<nums[j]<<endl;
                    xr^=nums[j];
                }
            }
            if(count) {
                //cout<<" count = "<<count<<endl;
                sum+=xr;
            }
        }
        return sum;
    }
};
