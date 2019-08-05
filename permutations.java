class Solution {
    public void swap (int[] a, int i, int j) {

  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

    List<List<Integer>> ans;
    void print(String s){
        System.out.println(s);
    }
    int[] a;
    private void permall(int i){
        if(i==0){
            List<Integer> t = IntStream.of(a).boxed().collect(Collectors.toList());
            ans.add(t);

        }
        else{

            for(int j = 0; j<i; j++){
                swap(a, j, i-1);
                permall(i-1);
                swap(a, i-1, j);
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        ans = new ArrayList<> ();
        a = nums.clone();
        permall(nums.length);
        return ans;
    }
}
