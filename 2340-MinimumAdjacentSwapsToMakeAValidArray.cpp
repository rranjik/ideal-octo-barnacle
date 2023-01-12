class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int minn = 1e9;
        int minj = -1;
        int n = nums.size();
        //it is advantages to use the 
        //first min and the last max
        for(int i = 0; i<n; i++){
            if(minn>nums[i]){
                minj = i;
                minn = nums[i];
            }
        }
        int maxx = -1e9;
        int maxj = -1;
        for(int i = n-1; i>=0; i--){
            if(maxx<nums[i]){
                maxj = i;
                maxx = nums[i];
            }
        }
        cout<<"minj = "<<minj<<" maxj = "<<maxj<<endl;
        //if max appears after min
        //move them independently
        //max need to go to n-1
        //so (n-1-maxj) (skip the +1 in j-i+1, as 
        //we just need to count the positions
        //after maxj up to n-1)
        //min needs to go to 0
        //this is exactly the number of elements 
        //before it (in zero indexing the index of 
        //an element is defined as the number
        //of elements before it)
        if(maxj>minj){
            return minj+(n-1-maxj);
        }
        //.....max....min....
        //.....max...min.....
        //.....max..min......
        //.....max.min.......
        //.....maxmin........
        //.....minmax........
        //if max appears before min
        //we can get on swap back when min
        //gets past max when going to left
        //(max will be displaced one position
        //to the right automatically by the swap)
        //so it's the same previous result 
        //minus a one (for the free swap)
        return minj+(n-1-maxj)-1;
    }
};
