class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int choice = -1;
        int mini = numeric_limits<int>::max();
        int minii = -1;
        for(int i = n-1; (choice==-1)&&i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(nums[j]>nums[i]){
                    choice = i;
                    for(int k = i+1; k<n; k++){
                        if(nums[k]>nums[i]){
                            mini = min(mini, nums[k]);
                            minii = k;
                        }
                    }
                    break;
                }
            }
        }
        cout<<"choice @ "<<choice<<endl;
        cout<<"replace by "<<mini<<endl;
        if(choice==-1){
            sort(nums.begin(), nums.end());
        }else{
            auto temp = nums[choice];
            nums[choice] = mini;
            nums[minii] = temp;
            sort(nums.begin()+choice+1, nums.end());
        }
        return;
    }
};
