class Solution {
    public boolean canJump(int[] nums) {
        int f = nums[0];
        int i = 0;
        while(i<nums.length){
            if(f<i)
                break;
            f = Math.max(f, nums[i]+i);
            i++;
        }
        if(f>=nums.length-1)
            return true;
        else 
            return false;
        
    }
}
