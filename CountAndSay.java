class Solution {
    public String countAndSay(int n) {
        if(n==1){
            return "1";
        }
        String prev = countAndSay(n-1);
        int p = 0;
        String res = new String();
        while(p<prev.length()){
            int count = 1;
            int num = prev.charAt(p)-'0';
            while(p+1<prev.length()&&(num==(prev.charAt(p+1)-'0'))){
                count++;
                p++;
            }
            p++;
            res+=count;
            res+=num;
        }
        return res;
    }
}
