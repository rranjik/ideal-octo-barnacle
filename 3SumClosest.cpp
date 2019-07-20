class Solution {
    int target;
    void find2NumsInRest(int& c,const int& n, const vector<int>& nums){
        //cout<<"c = "<<c<<"; n = "<<n<<"; size is "<<nums.size()<<endl;
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int sum = n + nums[left]+nums[right];
            //cout<<"sum ="<<sum<<"; left = "<<left<<"; right ="<<right<<endl;
            if(abs(sum-target) <= abs(c-target)){
                c = sum;
            }
            if(sum>target){
                right--;
            }   
            if(sum<target){
                left++;
            }
            if(sum==target)
                return;
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        this->target = target;
        sort(nums.begin(), nums.end());
        int c = nums[0]+nums[1]+nums[2];
        for(int i=0; i<nums.size(); i++){
            vector<int> r = vector<int>(nums.begin()+i+1, nums.end());
            find2NumsInRest(c, nums[i], r);
        }
        return c;
    }
};
