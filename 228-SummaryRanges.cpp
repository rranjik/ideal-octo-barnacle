class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for(int i = 0; i<nums.size();){
            //cout<<"i = "<<i<<endl;
            long long s = nums[i];
            long long n = s+1;
            long long end = s;
            int  c = 1;
            while(++i<nums.size() && nums[i]==n){
                c++;
                end = n;
                n++;
            }
            if(i>=nums.size()){
                if(c>1){
                   string inter = string(to_string(s))+"->"+to_string(end);
                   res.push_back(inter);
                }
                else{
                   res.push_back(to_string(s));
                }
            }
            else {
                if(c>1){
                   //cout<<"addding "<<inter<<endl;
                   string inter = string(to_string(s))+"->"+to_string(end);
                   res.push_back(inter);
                }
                else{
                   //cout<<"addding "<<to_string(s)<<endl;
                   res.push_back(to_string(s));
                }
            }
        }
        return res;
    }
};
