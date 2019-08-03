class Solution {
    public int divide(int dividend, int divisor) {
        System.out.println(Integer.MAX_VALUE);
        int q=0;
        int n = Math.abs(dividend);
        final int d = Math.abs(divisor);
        while(n>=d){
            q++;
            if(q==0){
                return Integer.MAX_VALUE;
            }
            n-=d;
        }
        if((dividend<0&&divisor>0)||(dividend>0&&(divisor<0)))
            return -q;
        else return q;
    }
}
