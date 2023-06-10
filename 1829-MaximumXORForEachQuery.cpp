class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        unsigned int x{};
        for(int i = 0; i<nums.size(); i++){
            x^=nums[i];
        }
        //cout<<"x = "<<x<<endl;
        unsigned int req = (1<<maximumBit)-1;
        //cout<<"req = "<<req<<endl;
        unsigned int ireq = ~req; 
        //cout<<"ireq = "<<ireq<<endl;
        vector<unsigned int> res;
        for(int i = nums.size()-1; i>=0; i--){
            res.push_back((~x)&req);
            x^=nums[i];
            //cout<<"added "<<res.back()<<endl;
            //cout<<"x = "<<x<<endl;
        }
        vector<int> rres;
        for(const auto& r : res){
            rres.push_back((int)r);
        }
        reverse(res.begin(), res.end());
        return rres;
    }
};
