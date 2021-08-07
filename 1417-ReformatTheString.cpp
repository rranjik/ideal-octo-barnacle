class Solution {
public:
    string reformat(string s) {
        string res;
        vector<char> chs;
        vector<int> nums;
        for(const auto& c : s){
            if('a'<=c&&c<='z'){
                chs.push_back(c);
            }else{
                nums.push_back(c-'0');
            }
        }
        if(abs((int)chs.size()-((int)nums.size()))>=2) return "";
        if(chs.size()>nums.size()){
            for(int i = 0; i<chs.size(); i++){
                res+=string(1, chs[i]);
                if(i<nums.size())
                    res+=to_string(nums[i]);
            }
        }else{
            for(int i = 0; i<nums.size(); i++){
                res+=to_string(nums[i]);
                if(i<chs.size())
                    res+=string(1, chs[i]);
            }
        }
        return res;
    }
};
