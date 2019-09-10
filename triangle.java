class Solution {
    public List<List<Integer>> tri = new ArrayList<>();
    public class Coor{
        int index;
        int level;
        Coor(int index, int level){
            this.index = index;
            this.level = level;
        }
    }
    Map<Coor, Integer> mp = new HashMap<>();
    public int help(int i, int l){
        if(mp.get(new Coor(i, l))!=null){
            return mp.get(new Coor(i, l));
        }
        //System.out.println("i = "+i+"; l = "+l);
        //if(l==tri.size()){
        //    int res = Math.min(res, rs);
        //    mp.get(new coor(i, l, rs));
        //    return;
        //}
        Coor c = new Coor(i,l);
        if(l<tri.size() && i>=0 && i<tri.get(l).size()){
            int curr = tri.get(l).get(i);
            int left = curr+help(i, l+1);
            int right = curr+help(i+1, l+1);
            mp.put(c, Math.min(left , right));
        }
        else{
            mp.put(c, 0); 
        }
        int cached = mp.get(c);
        return cached;
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        tri = triangle;
        return help(0, 0);
    }
}
