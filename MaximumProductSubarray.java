class Solution {
    public int maxProduct(int[] nums) {
        int[] ans = new int[nums.length];
        int res = nums[0];
        ans[0] = nums[0];
        int hi = nums[0];
        int lo = nums[0];
        int curr = ans[0];
        for(int i = 1;i<nums.length; i++){
            int high = Math.max(hi*nums[i], Math.max(nums[i], lo*nums[i]));
            int low = Math.min(hi*nums[i], Math.min(nums[i], lo*nums[i]));
            hi = high;
            lo = low;
            ans[i] = Math.max(hi, Math.max(lo, nums[i]));
            res = Math.max(res, ans[i]);
        }
        return res;
    }
}
