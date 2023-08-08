class Solution {
public:
    void print(const vector<int>& v)
    {for(const auto& n : v) cout<<n<<" "; cout<<endl;}
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> paths(n, 1);
        for(int j = 0; j<n; j++){
            int mh = -1e9;
            int vj = nums[j];
            unordered_map<int, int> m;
            for(int i = j-1; i>=0; i--){
                if(nums[i]<nums[j]){
                    if(mh<lis[i]){
                        lis[j] = lis[i]+1;
                        mh = lis[i];
                        paths[j] = paths[i];
                    }else if(mh==lis[i]){
                        paths[j]+=paths[i];
                    }
                }
            }
            //print(lis);
            //print(paths);
        }
        int lisp = 0;
        int rres = 0;
        for(int i = 0; i<n; i++){
            //cout<<"lis["<<i<<"] = "<<lis[i]<<endl;
            //cout<<"paths["<<i<<"] = "<<lis[i]<<endl;
            if(lisp<lis[i]){
                lisp = lis[i];
                rres = paths[i];
            }else if(lisp == lis[i]){
                rres = rres+paths[i];
            }
        }
        //cout<<endl;
        return rres;
    }
};
