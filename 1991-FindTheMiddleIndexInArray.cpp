class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> s(nums.size());
        s[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2; i>=0; i--){
            s[i] = s[i+1]+nums[i];
        }
        for(const auto& a : s) cout<<a<<" "; cout<<endl;
        if(s[1]==0) return 0;
        int sum = 0;
        cout<<"nums.size()-2 = "<<(int)nums.size()-2<<endl;
        for(int i = 0; i<=(int)nums.size()-2; i++){
            cout<<" i = "<<i<<endl;
            if(s[i+1]==sum) return i;
            sum+=nums[i];
            cout<<sum<<" ";
        }
        cout<<"here" <<endl;
        if(!sum) return nums.size()-1;
        return -1;
    }
};
