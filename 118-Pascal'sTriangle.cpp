class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        /*
        if(!numRows)
            return res;
        if(numRows == 1){
            vector<int> one;
            one.push_back(1);
            res.push_back(one);
            return res;
        }
        else if(numRows == 2){
            vector<int> two;
            two.push_back(1);
            two.push_back(1);
            res.push_back(two);
            return res;
        }
        else {
            vector<int> one;
            one.push_back(1);
            vector<int> two;
            two.push_back(1);
            two.push_back(1);
            res.push_back(one);
            res.push_back(two);
            vector<int> next;
            next.push_back(1);
            int row = 3;
            while(numRows <= 2){
                numberOfElements = row-2;
                while(numRows>0){
                    next.push_back(res[row-1][])
                }
                row++;
                numRows--;
        }
        */
        for(int i = 0; i< numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j<i; j++){
                row.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            if(i)
                row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};
