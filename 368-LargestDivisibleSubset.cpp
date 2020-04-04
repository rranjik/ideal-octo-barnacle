class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)return vector<int>();
        sort(nums.begin(), nums.end());
        vector<int> iofmz(nums.size());
        vector<int> count(nums.size(), 1);
        for(int j = 0; j<nums.size(); j++){
            iofmz[j] = j;
        }
        for(int j = nums.size()-2; j >=0; j--){
            //bool iofmzdone = false;
            for(int i = j+1; i<nums.size(); i++){
                if(nums[i]%nums[j]==0){
                    if(count[i]+1>count[j]){
                        count[j] = count[i]+1;
                        //if(!iofmzdone){
                            iofmz[j] = i;
                            //iofmzdone = true;
                        //}
                    }
                }
            }
            //bool found = false;
            //int s = j+1;
            //while(!found&&s<nums.size()){
            //    if(nums[s]%nums[j]==0){
            //        found = true;
            //        iofmz[j]=s;
            //    }else s++;
            //}
        }
        cout<<"finished finding first mod 0 for each num "<<endl;
        cout<<"iofmz: ";
        for(int i = 0; i<iofmz.size(); i++){
            cout<<iofmz[i]<<" ";
        }
        cout<<endl;
        vector<vector<int>> mz(iofmz.size());
        for(int i = 0; i<iofmz.size(); i++){
            int c = i;
            while(c!=iofmz[c]||c==nums.size()){
                mz[i].push_back(iofmz[c]);
                c = iofmz[c];
            }
        }
        int ress = 0;
        int resi = 0;
        cout<<"mz: ";
        for(int i = 0; i<mz.size(); i++){
            cout<<mz[i].size()<<" ";
            if(ress<mz[i].size()) {ress = mz[i].size(); resi=i;}
        }
        cout<<endl;
        vector<int> res;
        res.push_back(nums[resi]);
        for(const auto& i : mz[resi]){
            res.push_back(nums[i]);
        }
        cout<<"ress = "<<ress<<endl;
        return res;
    }
};
