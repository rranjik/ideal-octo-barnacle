class Solution {
    int l;
    int r;
    int u;
    int d;
    int dir;
    void print(String s){
        System.out.println((s));
    }
    List<Integer> so(int[][]matrix, int dir, int a, int b, List<Integer> res){
        print("a = "+a+"; b = "+b+"; r = "+r+"; l = "+l+"; u = "+u+"; d = "+d);
        if(dir==0){
            int i=0;
            for(; i<r; i++){
                res.add(matrix[a][b+i]);
                print(""+matrix[a][b+i]);
            }
            l--;
            r--;
            if(d>0)
                so(matrix, 1, a+1, b+i-1, res);
        }
        else if (dir == 1){
            int i = 0;
            for(; i<d; i++){
                res.add(matrix[a+i][b]);
                print(""+matrix[a+i][b]);
            }
            u--;
            d--;
            if(l>0)
                so(matrix, 2, a+i-1, b-1, res);
        }
        else if(dir==2){
            int i = l;
            for(; i>0; i--){
                int dummy = matrix[a][b--];
                res.add(dummy);
                print(""+dummy);
            }
            r--;
            l--;
            if(u>0)
                so(matrix, 3, a-1, b+1, res);
        }
        else if(dir==3){
            int i = u;
            for(; i>0; i--){
                int dummy = matrix[a--][b];
                res.add(dummy);
                print(""+dummy);
            }
            d--;
            u--;
            if(r>0)
                so(matrix, 0, a+1, b+1, res);
        }
        return res;
    }
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        if(matrix.length==0)
            return res;
        r=matrix[0].length;
        d=matrix.length-1;
        l=r;
        u=d;
        return so(matrix, 0, 0, 0, res);
    }
}
