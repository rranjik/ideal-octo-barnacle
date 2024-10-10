class Solution {
public:
    bool poss(const vector<int>& ps, int t, int m){
        int np = 1;
        bool go = true;
        vector<int>::const_iterator last = ps.begin();
        int ot = t;
        while(np<m&&go){
            cout<< "looking for "<<t<<endl;
            last = upper_bound(last, ps.end(), t);
            if(*last>t) last = prev(last);
            if(last==ps.end()){
                go = false;
            }else{
                cout<<"found "<<t<<endl;
                cout<<"lower bound of "<<t<<" found at "<<*last<<endl;
                t+=*last;
                np++;
            }
        }
        cout<<"*"<<endl;
        if(last!=ps.end()){
            if(ps[ps.size()-1]-*last<ot) {
                cout<<"upto end = "<<ps[ps.size()-1]-*last<<endl;
                return false;
            }
            else return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0;
        int l = 0;
        for(int i = 0; i<nums.size(); i++){
            l = max(l, nums[i]);
            sum+=nums[i];
        }
        int h = sum;
        cout<<"sum = "<<sum<<endl;
        while(l<h){
            int v = (l+h)/2;
            int sum = 0;
            int np = 1;
            for(const auto& b : nums){
                if(sum+b<=v){
                    sum+=b;
                }else{
                    sum = b;
                    np++;
                }
            }
            if(np>m){
                l = v+1;
            }else{
                h = v;
            }
        }
        return h;
    }
};
