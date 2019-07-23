class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size()-1;
        int prev = -1;
        int next = nums[l];
        while(l>=0){
           cout<<"prev "<<prev<<"; next"<<next<<endl;
           cout<<"l="<<l<<endl;
           if(prev<=next){
               l--;
               prev=next;
               next=nums[l];
           }
           else{
               
               break;
           }
        }
        if(l==-1){
           reverse(nums.begin(), nums.end());
           return;
        }
        else{
           int to_swap_from = l+1;
           int b = nums[l];
           cout<<"to_swap_from "<<to_swap_from<<endl;
           cout<<"b "<<b<<endl;
           while(l<nums.size()){
               cout<<"nums[l+1]"<<nums[l+1]<<endl;
               if(nums[l+1]<b)
                   break;
               l++;
           }
           //l+1 contains element to swap
           cout<<"nums[l+1]"<<nums[l+1]<<"; nums[to_swap_from-1]"<<nums[to_swap_from-1]<<endl;
           swap(nums[l], nums[to_swap_from-1]);
           int l = to_swap_from;
           int r= nums.size()-1;
           while(l<r){
               cout<<"nums[l]"<<nums[l]<<"nums[r]"<<nums[r]<<endl;
               swap(nums[l], nums[r]);
               l++;
               r--;
           }
        }
    }
};
