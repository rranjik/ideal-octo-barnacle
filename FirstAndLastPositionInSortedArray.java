class Solution {
    private int[] bs(int[] nums, int target){
        int l = 0;
        int r = nums.length-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target){
                int f = m;
                while(f<nums.length){
                    if(nums[f]!=target)
                        break;
                    else f++;
                }
                //f-1 points to last;
                int k = m;
                while(k>=0){
                    if(nums[k]!=target)
                        break;
                    else k--;
                }
                //k+1 point to start
                int[] a = new int[2];
                a[0]=k+1;
                a[1]=f-1;
                return a;
            }
            else if(target<nums[m]){
                r=r-1;
            }
            else l=l+1;
        }
        int[] a = new int[2];
        a[0]=-1;
        a[1]=-1;
        return a;
    }
    public int[] searchRange(int[] nums, int target) {
        return bs(nums, target);
    }
}
