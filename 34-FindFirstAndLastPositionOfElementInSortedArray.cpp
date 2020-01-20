class Solution {
public:
    int bsl(const vector<int>& v, int t){
        int l = 0;
        int h = v.size()-1;
        int res = -1;
        while(l<=h){
            //cout<<"l = "<<l<<"; h = "<<h;
            int m = (l+h)/2;
            //cout<<"; v[m] = "<<v[m]<<endl;
            if(v[m] == t){
                res = m;
                h = m-1;
            }
            else if(v[m]>t){
                h = m-1;
            }
            else {
                l = m+1;
            }
        }
        //cout<<"returning "<<res<<endl;
        return res;
    }
    int bsh(const vector<int>& v, int t){
        int l = 0;
        int h = v.size()-1;
        int res = -1;
        while(l<=h){
            //cout<<"l = "<<l<<"; h = "<<h;
            int m = (l+h)/2;
            //cout<<"; v[m] = "<<v[m]<<endl;
            if(v[m] == t){
                res = m;
                l = m+1;
            }
            else if(v[m]>t){
                h = m-1;
            }
            else {
                l = m+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        auto l = bsl(nums, target);
        //cout<<"exit l"<<endl;
        if(l == -1){
            res.push_back(-1);
            res.push_back(-1);
        }
        else {
            res.push_back(l);
            res.push_back(bsh(nums, target));
        }
        return res;
    }
};
