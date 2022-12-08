class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int fivepercent = arr.size()*0.05;
        double res{};
        int n{};
        for(int i = fivepercent; i<arr.size()-fivepercent; i++){
            n++;
            res+=arr[i];
        }
        return res/n;
    }
};
