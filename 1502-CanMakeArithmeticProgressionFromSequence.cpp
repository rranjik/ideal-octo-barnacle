class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = -1;
        for(int i = 0; i<arr.size()-1; i++){
            if(diff<0){
                diff = arr[i+1]-arr[i];
            }else{
                if(diff!=(arr[i+1]-arr[i])){
                    return false;
                }
            }
        }
        return true;
    }
};
