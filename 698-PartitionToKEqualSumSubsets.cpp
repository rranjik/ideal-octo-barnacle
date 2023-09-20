class Solution {
public:
    //ith subset's sum
    vector<int> s;
    //used
    vector<bool> u;
    int ss = 0;
    int n = 0;
    int k = 0;
    vector<int> a;
    void print(const vector<int>& v) {for(const auto& n : v) cout<<n<<" "; cout<<endl;}
    void print(const vector<bool>& v) {for(const auto& n : v) cout<<n<<" "; cout<<endl;}
    bool dfs(int i, int ssi){
        //cout<<"i = "<<i<<" ssi = "<<ssi<<endl;
        //print(s); print(u);
        if(i>=n) return false;
        if(ssi>=k) return false;
        if(s[ssi]==ss){
            if(ssi==k-2) return true;
            return dfs(0, ssi+1);
        }else if(s[ssi]>ss) return false;
        for(int j = i; j<n; j++){
            if(u[j]) continue;
            auto tmp = s[ssi]+a[j];
            if(tmp<=ss){
                u[j] = true;
                s[ssi] += a[j];
                bool res = dfs(j+1, ssi);
                if(res) return true;
                u[j] = false;
                s[ssi] -= a[j];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        a = nums;
        n = nums.size();
        this->k = k;
        if(k==1) return true;
        if(n<k) return false;
        
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%k) return false;
        
        ss = sum/k;
        //cout<<"ss = "<<ss<<endl;
        //cout<<"k = "<<k<<endl;
        s = vector<int>(k, 0);
        //cout<<"s.size() = "<<s.size()<<endl;
        u = vector<bool>(n, 0);
        
        return dfs(0, 0);
    }
};
