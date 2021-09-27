class Solution {
public:
    void add_range(int start, int end, vector<string>& res){
        if(start+1==end){
            res.push_back(to_string(start));
        }else{
            res.push_back(to_string(start)+"->"+to_string(end-1));
        }
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size()==0){
            if(lower!=upper){
                res.push_back(to_string(lower)+"->"+to_string(upper));
            }else{
                res.push_back(to_string(lower));
            }
            return res;
        }
        int last = nums[0];
        if(last>lower){
                add_range(lower, last, res);
        }
        for(int i = 1; i<nums.size(); i++){
            cout<<"last = "<<last<<" now = "<<nums[i]<<endl;
            if(nums[i]!=last+1){
                add_range(last+1, nums[i], res);
            }
            last = nums[i];
        }
        if(last<upper){
            add_range(last+1, upper+1, res);
        }
        return res;
    }
};
