class FT {
    vector<int> ft;
    public: 
    FT(vector<int>& nums){
        ft = vector<int>(nums.size()+1);
        ft[0] = 0;
        for(int i = 1; i<=nums.size(); i++){
            ft[i] = ft[i-1]+nums[i-1];
        }
        for(int i = nums.size(); i>=0; i--){
            int p = i - (i & -i);
            if(p>=0)
                ft[i]-=ft[p];
        }
    }
    void show(){
        for(int i =0 ; i<ft.size(); i++){
            cout<<ft[i]<<" ";
        }
        cout<<endl;
    }
    int sum(int x){
        x++;
        //cout<<"index = "<<x<<"; ft["<<x<<"] = "<<ft[x]<<endl;
        int res = 0;
        while(x>0){
            res+=ft[x];
            x=x-(x&-x);
            //cout<<"index = "<<x<<"; ft["<<x<<"] = "<<ft[x]<<endl;
        }
        return res;
    }
    
    void inc(int x, int val){
        x++;
        while(x<=ft.size()-1){
            ft[x] +=val;
            x = x+(x&-x);   
        }
    }
};

class NumArray {
    FT ft;
    vector<int> arr;
public:
    NumArray(vector<int>& nums): ft(nums) {
        arr = nums;
        ft.show();
    }
    
    void update(int i, int val) {
        int diff = val - arr[i];
        arr[i] = val;
        ft.inc(i, diff);
    }
    
    int sumRange(int i, int j) {
        return ft.sum(j) - ft.sum(i-1);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
