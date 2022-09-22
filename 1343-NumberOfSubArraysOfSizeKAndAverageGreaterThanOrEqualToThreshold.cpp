class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum{};
        int res{};
        for(int i = 0, j = 0; j<arr.size(); j++){
            //cout<<"i = "<<i<<" j= "<<j<<endl;
            if(j-i+1<k){
                //cout<<"less sum = "<<sum<<endl;
                sum += arr[j];
            }
            if(j-i+1==k){
                sum+=arr[j];
                //cout<<"k sum = "<<sum<<endl;
                auto a = (sum*1.0)/k;
                sum-=arr[i];
                i++;
                if(a>=threshold) res++;
            }
        }
        return res;
    }
};
