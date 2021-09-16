class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(int i = 0; i<data.size(); i++){
            if(data[i]) ones++;
        }
        int l = 0;
        int r = ones-1;
        int mini = 0;
        for(int i = 0; i<=r; i++){
            if(!data[i]) mini++;
        }
        if(!mini) return 0;
        int last = mini;
        while(r<data.size()-1){
            int here = last;
            if(!data[l]) here--;
            if(!data[r+1]) here++;
            l++; 
            r++;
            mini = min(mini, here);
            last = here;
        }
        return  mini;
    }
};
