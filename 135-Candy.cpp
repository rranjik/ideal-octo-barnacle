class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left2right(ratings.size(), 1);
        vector<int> right2left(ratings.size(), 1);
        for(int i = 1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]&&left2right[i]<=left2right[i-1]){
                left2right[i] = left2right[i-1]+1;
            }
        }
        for(int i = ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]&&right2left[i]<=right2left[i+1]){
                right2left[i] = right2left[i+1]+1;
            }
        }
        int res = 0;
        for(int i = 0; i<ratings.size(); i++){
            res+=max(left2right[i], right2left[i]);
        }
        return res;
    }
};
