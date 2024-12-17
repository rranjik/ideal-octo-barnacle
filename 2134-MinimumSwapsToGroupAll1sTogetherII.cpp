class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //window size
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        vector<int>n = nums;
        n.insert(n.end(),nums.begin(),nums.end());
        
        int cs=0;
        int ans = 1e9;
        for(int i=0;i<sum;i++)
        {
            cs+=n[i];
        }
        int cswap = sum-cs;
        ans = min(ans,cswap);
        for(int i=sum;i<nums.size()-1+sum;i++)
        {
            //cout<< " ith index " << i <<endl;
            int j = i-sum;
            cout<<j<<endl;
            cs = cs - n[j];
            cs+= n[i];
           // cout<< "current sum " << cs<<endl;
            cswap = sum-cs;
            ans = min(ans,cswap);
        }
        return ans;


    }
};
