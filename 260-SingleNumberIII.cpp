class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int acc = 0;
        for(const auto& n : nums)
            acc^=n;
        cout<<"acc = "<<acc<<endl;
        int a = 1;
        while(!(acc&a))
            a<<=1;
        cout<<"a = "<<a<<endl;
        vector<int> res(2,0);
        for(const auto& n :nums){
            if(a&n){
                res[0]^=n;
            }
            else{
                res[1]^=n;
            }
        }
        return res;
    }
};
