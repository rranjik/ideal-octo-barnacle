class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> f = new HashMap<Integer, Integer>();
        for(int i = 0; i< nums.length; i++){
            Integer freq = f.getOrDefault(nums[i], 0);
            if(++freq>1)
                return true;
            f.put(nums[i], freq);
        }
        return false;
    }
}
