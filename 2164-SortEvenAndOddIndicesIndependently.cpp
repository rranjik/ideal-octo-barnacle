class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> e, o;
        for(int i = 0; i<nums.size(); i++){
            if(i%2){
                o.push_back(nums[i]);
            }else{
                e.push_back(nums[i]);
            }
        }
        sort(e.begin(), e.end());
        //reverse(e.begin(), e.end());
        sort(o.begin(), o.end());
        reverse(o.begin(), o.end());
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i<e.size()||j<o.size()){
            if(i<e.size()) res.push_back(e[i]);
            if(j<o.size()) res.push_back(o[j]);
            i++; j++;
        }
        return res;
    }
};
