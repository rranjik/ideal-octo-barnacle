class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int t = 0;
        int h = 0;
        int s = 0;
        for(int i = 0; i< gas.length; i++){
            System.out.println("t = "+t+"; h = "+h+"; s = "+ s);
            t += (gas[i]-cost[i]);
            h += (gas[i]-cost[i]);
            if(h<0){
                s = i+1;
                h = 0;
            }
        }
        return t<0?-1:s;
    }
}
