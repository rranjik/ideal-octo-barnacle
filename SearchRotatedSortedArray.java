class Solution {
    private void print(String s){
        System.out.println(s);
    }
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length-1;
        while(l<=r){
            int i = (l+r)/2;
            print("l= "+l+"; r = " +r+"; i = " + i);
            print("nums[l]= "+nums[l]+"; nums[r] = " +nums[r]+"; nums[i] = " + nums[i]);
            if(nums[i]==target){
                return i;
            }
            else{
                if(nums[i]<nums[r]){
                    print("right half is sorted");
                    if(nums[i]<=target&&target<=nums[r]){
                        print("element is towards the right");
                        l=i+1;
                    }
                    else {
                        print("element is not toward the right for sure");
                        r = i-1;
                    }
                }
                else{
                    print("left half is sorted");
                    if(nums[i]>=target&&target>=nums[l]){
                        print("element is towards the left");
                        r=i-1;
                    }
                    else {
                        print("element is not toward the left for sure");
                        l = i+1;
                    }
                }
            }
        }
        return -1;
    }
}
