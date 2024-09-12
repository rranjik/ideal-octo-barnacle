class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        //first row in [0...x] that has 1
        int top = searchRows(0, x, 0, n, true, image);
        //first row in [x+1...m] that is all 0s
        int bottom = searchRows(x+1, m, 0, n, false, image);
        //first col in [0...y] that has 1
        int left = searchCols(0, y, 0, m, true, image);
        //first col in [y+1...n] that is all 0s
        int right = searchCols(y+1, n, 0, m, false, image);
        return (right-left)*(bottom-top);
    }
    int searchRows(int i, int j, int low, int high, bool pix, 
                   const vector<vector<char>>& image){
        while(i!=j){
            int k = low;
            int m = (i+j)/2;
            while(k<high && image[m][k]=='0') k++;
            //imagine the first search:
            //first row in [0...x] that has 1.
            //if mth row does not have one then this condition
            //will be true. we passed 'true' for pix.
            //and, we can sure that the upper bound can be set to m
            
            
            //imagine the second search:
            //first row in [x+1...m] that is all 0s
            //if mth row does have a one then this condition
            //will be false. we passed 'false' for pix.
            //and, we can be sure that the lowe bound can be set to 
            //the next row m+1
            if(k<high == pix) j = m;
            
            //imagine the first search:
            //first row in [0...x] that has 1.
            //on the other hand if k > high, it means that we 
            //mth row never had a '1' in it (we went all the way from
            //fist col low to last col high but never hit a one)
            //so we set the lower limit to m + 1;
            else i = m + 1;
        }
        return j;
    }
    int searchCols(int i, int j, int low, int high, bool pix, 
                   const vector<vector<char>>& image){
        while(i!=j){
            int k = low;
            int m = (i+j)/2;
            while(k<high && image[k][m]=='0') k++;
            if(k<high == pix) j = m;
            else i = m + 1;
        }
        return i;
    }
};
