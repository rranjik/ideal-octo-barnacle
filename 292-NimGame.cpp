class Solution {
    //public Map<Integer, Boolean> m = new HashMap<>();
    public boolean canWinNim(int n) {
        if(n%4==0)return false;
        else return true;
        /*
        if(m.containsKey(n)){
            return m.get(n);
        }
        if(n==1||n==2||n==3){
            m.put(n, true);
            return true;
        }
        else {
            if(canWinNim(n-1)&&canWinNim(n-2)&&canWinNim(n-3)){
                m.put(n, false);
                return false;
            }
            else {
                m.put(n, true);
                return true;
            }
        }
        */
    }
}
