class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0; int one = 0; int two = 0;
        for(const auto& x : nums){
            if(x==0) zero++;
            else if(x==1) one++;
            else if(x==2) two++;
        }
        cout<<"zero = "<<zero<<" one = "<<one<<" two = "<<two<<endl;
        int j = 0;
        while(zero) {nums[j++] = 0; zero--;}
        while(one) {nums[j++] = 1; one--;}
        while(two) {nums[j++] = 2; two--;}
    }
}
