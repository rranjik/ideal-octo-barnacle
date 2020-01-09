
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
pair<int,int> locationOfTargetValue(int rowCount, int columnCount, 
                                    vector<vector<int> > matrix, 
									int targetValue)
{
    pair<int, int> res = pair<int, int>(-1, -1);
    // WRITE YOUR CODE HERE
    if(rowCount==0&&columnCount==0){
        return res;
    }
    if(targetValue<matrix[0][0] || 
       targetValue >matrix[rowCount-1][columnCount-1]){
           return res;
       }
    int r = 0; 
    int c = columnCount-1;
    while(r<rowCount && c>=0){
        if(matrix[r][c]==targetValue){
            res.first = r;
            res.second = c;
            return res;
        }
        else if(matrix[r][c]>targetValue){
            c--;
        }
        else 
            r++;
    }
    return res;
}
// FUNCTION SIGNATURE ENDS
