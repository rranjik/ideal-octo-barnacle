func minPairSum(nums []int) int {
    sort.Ints(nums)
    res := 0
    n := len(nums)
    for i:=0; i<n/2; i++{
        if res < nums[i]+nums[n-i-1] {
            res = nums[i]+nums[n-i-1]
        }
    }
    return res
}
