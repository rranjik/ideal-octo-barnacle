class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res{};
        for(int i = 0; i<arr.size(); i++){
            for(int j = i; j<arr.size(); j++){
                if((j-i+1)%2){
                    auto here = 0;
                    for(int k = i; k<=j; k++){
                        here += arr[k];
                    }
                    cout<<"here = "<<here<<endl;
                    res+=here;
                }
            }
        }
        return res;
    }
};
