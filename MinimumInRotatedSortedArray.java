class Solution {
    public int bs(int[] nums){
        int lo = 0;
        int hi = nums.length-1;
        while(lo<hi){
            int m = (lo+hi)/2;
            if(m-1>=0
               &&m+1<nums.length
               &&((nums[m]>nums[m+1]
                   &&nums[m]>nums[m-1])
                  ||(nums[m]<nums[m+1]
                   &&nums[m]<nums[m-1]))){
                return Math.min(nums[m], Math.min(nums[m-1], nums[m+1]));
            }
            else if(m-1<0){
                return Math.min(nums[m], nums[m+1]);
            }
            else if(m+1>=nums.length){
                return Math.min(nums[m], nums[m-1]);
            }
            else{
                if(nums[m]>nums[lo]){
                    lo=m+1;
                }
                else {
                    hi = m-1;
                }
            }
        }
        return nums[0];
    }
    public int findMin(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        else if(nums.length==2){
            return Math.min(nums[1], nums[0]);
        }
        else return bs(nums);
    }
}
