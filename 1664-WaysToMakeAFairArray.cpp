class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> fe(n, 0);
        vector<int> fo(n, 0);
        vector<int> be(n, 0);
        vector<int> bo(n, 0);
        int re{}; int ro{};
        for(int i = 0; i<n; i++){
            if(i%2){
                ro+=nums[i];
                fo[i] = ro;
                fe[i] = re;
            }else{
                re+=nums[i];
                fe[i] = re;
                fo[i] = ro;
            }
        }
        int rbe{}; int rbo{};
        for(int i = n-1; i>=0; i--){
            if(i%2){
                rbe+=nums[i];
                be[i] = rbe;
                bo[i] = rbo;
            }else{
                rbo+=nums[i];
                be[i] = rbe;
                bo[i] = rbo;
            }
        }
        //cout<<"fe: ";
        //for(int i = 0; i<n; i++){
        //    cout<<fe[i]<<" ";
        //}
        //cout<<endl;
        //cout<<"fo: ";
        //for(int i = 0; i<n; i++){
        //    cout<<fo[i]<<" ";
        //}
        //cout<<endl;
        //cout<<"be: ";
        //for(int i = 0; i<n; i++){
        //    cout<<be[i]<<" ";
        //}
        //cout<<endl;
        //cout<<"bo: ";
        //for(int i = 0; i<n; i++){
        //    cout<<bo[i]<<" ";
        //}
        //cout<<endl;
        int res{};
        for(int i = 0; i<n; i++){
            auto pe = 0;
            auto po = 0;
            auto ae = 0;
            auto ao = 0;
            if(i-1>=0) pe = fe[i-1];
            if(i-1>=0) po = fo[i-1];
            if(i+1<n) ae = be[i+1];
            if(i+1<n) ao = bo[i+1];
            if(pe+ae==po+ao) res++;
        }
        return res;
    }
};
