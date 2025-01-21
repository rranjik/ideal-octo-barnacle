class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
       vector<int>pf(n,0);
       int p= 0;
       
       for(int i = 0;i<nums.size();i++)
       {
            if(nums[i]%2!=0)
            {
               pf[i]=p+1;
               p= pf[i];
            }
            else
            {
               pf[i]= p; 
            }
            
       }
       for(auto x: pf)
       {
         cout<< x <<" ";
       }
       cout<<endl;
       map<int,int>mp;
       mp[0]++;
       int count=0;
       for(int i=0;i<pf.size();i++)
       {
            int to_find = pf[i]-k;
            cout<<to_find<<endl;
            if(mp.find(to_find)!=mp.end())
            {
                count+= mp[to_find];
                
            }
            
                mp[pf[i]]++;
            
       }
       
       return count;


    }
};
