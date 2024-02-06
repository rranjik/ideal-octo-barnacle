class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> res;
        int ma = -1;
        int nz = 0;
        int no = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]) no++;
            else nz++;
        }
        int l = 0;
        int r = no;
        //cout<<"nz = "<<nz<<" no = "<<no<<endl;
        for(int i = 0; i<nums.size(); i++){
            int s = l+r;
            //cout<<"i = "<<i<<" s = "<<s<<endl;
            if(s>ma){
                res = vector<int>();
                res.push_back(i);
                ma = s;
            }else if(s==ma){
                res.push_back(i);
            }
            if(nums[i]==0) l++;
            else r--;
            //cout<<"l = "<<l<<" r = "<<r<<endl;
        }
        int s = l+r;
        //cout<<"s = "<<s<<endl;
        if(s>ma){
            res = vector<int>();
            res.push_back(nums.size());
            s = ma;
        }else if(s==ma){
            res.push_back(nums.size());
        }
        return res;
    }
};
