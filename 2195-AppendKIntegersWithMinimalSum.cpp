class Solution {
public:
    long long minimalKSum(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        auto res = 0ll;
        vector<int> nums;
        nums.push_back(0);
        for(const auto& n : a) nums.push_back(n);
        //for(const auto& n : nums) //cout<<n<<" "; cout<<endl;
        for(int i = 0; k&&i<nums.size()-1; i++){
            //cout<<"k = "<<k<<endl;
            auto d = nums[i+1]-nums[i]-1;
            //cout<<"d = "<<d<<endl;
            if(d<=0) continue;
            if(d<=k){
                //cout<<"d<=k"<<endl;
                long long b = nums[i+1]-1;
                long long a = nums[i]+1;
                long long sum = ((b-a+1)*(a+b))/2;
                //cout<<"a = "<<a<<" b = "<<b<<" sum = "<<sum<<endl;
                res+=sum;
                k-=d;
            }else{
                //cout<<"d>k"<<endl;
                long long b = nums[i]+k;
                long long a = nums[i]+1;
                long long sum = ((b-a+1)*(a+b))/2;
                //cout<<"a = "<<a<<" b = "<<b<<" sum = "<<sum<<endl;
                res+=sum;
                k = 0;
            }
        }
        //cout<<"out k = "<<k<<endl;
        if(k){
            //cout<<"still k"<<endl;
            long long b = nums[nums.size()-1]+k;
            long long a = nums[nums.size()-1]+1;
            long long sum = ((b-a+1)*(a+b))/2;
            //cout<<"a = "<<a<<" b = "<<b<<" sum = "<<sum<<endl;
            res+=sum;
            k = 0;
        }
        return res;
    }
};
