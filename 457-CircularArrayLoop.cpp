class Solution {
public:
    int next(int i){
        //cout<<i<<" goes to "<<(i+nums[i]+n)%n<<endl;
        return ((i+nums[i])%n+n)%n;
    }
    int n;
    vector<int> nums;
    bool circularArrayLoop(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        for(auto& num : nums) num%=n;
        for(int i = 0; i<nums.size(); i++){
            int slow = i;
            int fast = i;
            while(nums[slow]*nums[next(fast)]>0&&nums[slow]*nums[next(next(fast))]>0){
                slow = next(slow);
                fast = next(next(fast));
                if(slow==fast){
                    if(slow==next(slow)) break;
                    return true;
                }
            }
            int j = i;
            int val = nums[j];
            //we know that we wouldn't have stepped on a cell
            //if nums[j]*val was negative
            //so zero out everything that reachable from here
            //that won't be a cycle
            while(nums[j]*val>0){
                auto nex = next(j);
                nums[j] = 0;
                j = nex;
            }
        }
        return false;
    }
};
