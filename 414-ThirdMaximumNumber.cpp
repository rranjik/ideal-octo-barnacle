class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for(int i = 0; i<nums.size(); i++){
            top3.insert(nums[i]);
            if(top3.size()>3){
                top3.erase(top3.begin());
            }
        }
        for(auto it = top3.begin(); it!= top3.end(); it++)
            cout<<*it<<" ";
        cout<<endl;
        if(top3.size()==3){
            return *top3.begin();
        }else return *top3.rbegin();
    }
};
