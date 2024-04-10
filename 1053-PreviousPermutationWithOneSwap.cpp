class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        bool found = false;
        int l = -1;
        int n = arr.size();
        for(int i = n-1; i>0; i--){
            if(arr[i]<arr[i-1]){
                l = i-1;
                found = true;
                break;
            }
        }
        if(!found) return arr;
        cout<<"l = "<<l<<endl;
        int lbs = -1;
        int lbsi = -1;
        cout<<"n = "<<n<<endl;
        for(int i = l+1; i<n; i++){
            //if(arr[i]<arr[l]) continue;
            if(arr[i]<arr[l]&&arr[i]>lbs){
                lbs = arr[i];
                lbsi = i;
            }
        }
        cout<<"lbsi = "<<lbsi<<endl;
        if(lbsi==-1) return arr;
        swap(arr[l], arr[lbsi]);
        return arr;
    }
    
};
