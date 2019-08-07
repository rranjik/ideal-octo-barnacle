class Solution {
    int l;
    int r;
    int u;
    int d;
    int dir;
    void print(String s){
        System.out.println((s));
    }
    int n;
    int[][] matrix;
    void so(int dir, int a, int b){
        print("a = "+a+"; b = "+b+"; r = "+r+"; l = "+l+"; u = "+u+"; d = "+d);
        if(dir==0){
            int i=0;
            for(; i<r; i++){
                matrix[a][b+i] = n;
                n = n+1;
                print(""+matrix[a][b+i]);
            }
            l--;
            r--;
            if(d>0)
                so(1, a+1, b+i-1);
        }
        else if (dir == 1){
            int i = 0;
            for(; i<d; i++){
                matrix[a+i][b]=n;
                n = n+1;
                print(""+matrix[a+i][b]);
            }
            u--;
            d--;
            if(l>0)
                so(2, a+i-1, b-1);
        }
        else if(dir==2){
            int i = l;
            for(; i>0; i--){
                matrix[a][b--] = n;
                n = n+1;
            }
            r--;
            l--;
            if(u>0)
                so(3, a-1, b+1);
        }
        else if(dir==3){
            int i = u;
            for(; i>0; i--){
                matrix[a--][b] = n;
                n = n+1;
            }
            d--;
            u--;
            if(r>0)
                so(0, a+1, b+1);
        }
    }
    public int[][] generateMatrix(int s) {
        if(s==0)
            return matrix;
        n=1;
        matrix = new int[s][s];
        r=s;
        d=s-1;
        l=r;
        u=d;
        so(0, 0, 0);
        return matrix;
    }
}
