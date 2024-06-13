class Solution {
public:
    //int minDeletion(vector<int>& nums) {
    //    int ei = 0;
    //    int oi = 0;
    //    int n = nums.size();
    //    for(int i = 0; i<nums.size()-1; i++){
    //        if(nums[i]==nums[i+1]){
    //            i%2?oi++:ei++;
    //        }
    //    }
    //    if(n%2==0&&ei==0) return 0;
    //    int res = 0;
    //    while(ei!=0 || n%2!=0){
    //        if(ei){
    //            res++;
    //            ei--;
    //            swap(ei, oi);
    //            n--;
    //        }else{
    //            res++;
    //            break;
    //        }
    //    }
    //    return res;
    //}
    int minDeletion(vector<int>& nums) {
        vector<int> ei;
        vector<int> oi;
        int n = nums.size();
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                i%2?oi.push_back(i):ei.push_back(i);
            }
        }
        reverse(ei.begin(), ei.end());
        reverse(oi.begin(), oi.end());
        int res = 0;
        while(!ei.empty() || n%2!=0){
            if(!ei.empty()){
                auto fe = ei.back(); ei.pop_back();
                n--;
                //cout<<"fe = "<<fe<<endl;
                res++;
                while(!oi.empty()&&oi.back()<fe){
                    //cout<<" throw away "<<oi.back()<<endl;
                    oi.pop_back();
                }
                swap(oi, ei);
            }else{
                res++;
                break;
            }
        }
        return res;
    }
};
