using pairint = pair<int, int>;
class Solution {
    bool twoSum(int t, const vector<int>& a, pairint& p){
        cout<<"target: "<<t<<endl;
        int i=0;
        int j=a.size()-1;
        while(i<j){
            cout<<"a[i] = "<<a[i]<<"; a[j] = "<<a[j]<<endl;
            if(a[i]+a[j]>t){
                j--;
            }
            else if(a[i]+a[j]<t){
                i++;
            }
            else{
                p.first = a[i];
                p.second = a[j];
                return true;
            }
        }
        return false;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> res;
       sort(nums.begin(), nums.end());
       for(int i =0; i<nums.size();i++){
           int t = -nums[i];
           vector<int> r = vector(nums.begin()+i+1, nums.end());
           pairint p = pair<int, int>();
           if(twoSum(t, r, p)){
               cout<<"twoSum("<<t<<")"<<"returned true";
               vector<int> a = {-t, p.first, p.second};
               res.push_back(a);
           }
           else
               cout<<"twoSum("<<t<<")"<<"returned false";
       } 
       return res;
    }
};
