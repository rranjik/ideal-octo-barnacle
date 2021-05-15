class Solution {
public:
    //void print(const vector<int>& n){
    //    for(const auto& a : n) cout<<a<<" "; cout<<endl;
    //}
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        auto n = nums.size();
        vector<int> ps(n);
        vector<int> ss(n);
        for(int i = 1; i<n; i++){
            ps[i]=ps[i-1]+nums[i-1];
        }
        //print(ps);
        //cout<<"ps done"<<endl;
        for(int i = n-2; i>=0; i--){
            ss[i]=ss[i+1]+nums[i+1];
        }
        //print(ss);
        //cout<<"ss done"<<endl;
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            res[i] = ss[i]+(i*nums[i])-ps[i]-(nums[i]*(n-i-1));
        }
        return res;
    }
};
