class Solution {
    public int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }else{
            int pprev = 0;
            int prev = 1;
            int next = 0;
            for(int i=0; i<n; i++){
                next = pprev+prev;
                pprev = prev;
                prev = next;
            }
            return next;
        }
    }
}
