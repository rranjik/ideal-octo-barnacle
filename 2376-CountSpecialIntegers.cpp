class Solution {
public:
    vector<int> a;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> m;
    int dp(int j = 0, int tight = 1, int mask = 0, string s = ""){
        //cout<<"j = "<<j<<" tight = "<<tight<<" mask = "<<mask<<" s = "<<s<<endl;
        if(j==a.size()){
            return mask!=0;
        }
        if(m.find(j)!=m.end()&&m[j].find(tight)!=m[j].end()&&m[j][tight].find(mask)!=m[j][tight].end())
            return m[j][tight][mask];
        int res = 0;
        if(tight){
            for(int i = 0; i<=a[j]; i++){
                //rejects if i is used
                //INCLUDING i=0
                if(mask&(1<<i)) continue;
                
                //if mask was 0, it means we have not used 
                //any digit before, including 0
                
                //and if i==0 now, it means we want to 0 use now
                //A zero is really 'used' only if there was some 
                //non-zero digit used before it 
                //(0012, 0024, 0043, do not count as use)
                
                //if everything before was zero choices and this
                //was also a zero choice then just use the old mask
                //we are not using anything here really
                
                //cound this i as 'used' in all other cases, 
                //INCLUDING i=0
                int nmask = (mask==0&&i==0?mask:(mask|(1<<i)));
                
                s[j] = '0'+i;
                if(i==a[j]){
                    res+=dp(j+1, 1, nmask, s);
                }else{
                    res+=dp(j+1, 0, nmask, s);
                }
            }
        }else{
            for(int i =0; i<=9; i++){
                //rejects if i is used
                //INCLUDING i=0
                if(mask&(1<<i)) continue;
                
                //if mask was 0, it means we have not used 
                //any digit before, including 0
                
                //and if i==0 now, it means we want to 0 use now
                //A zero is really 'used' only if there was some 
                //non-zero digit used before it 
                //(0012, 0024, 0043, do not count as use)
                
                //if everything before was zero choices and this
                //was also a zero choice then just use the old mask
                //we are not using anything here really
                
                //cound this i as 'used' in all other cases, 
                //INCLUDING i=0
                int nmask = (mask==0&&i==0?mask:(mask|(1<<i)));
                s[j] = '0'+i;
                res+=dp(j+1, 0, nmask, s);
            }
        }
        return m[j][tight][mask] = res;
    }
    void digits(int n){
        while(n){
            a.push_back(n%10);
            n/=10;
        }
        reverse(a.begin(), a.end());
    }
    int countSpecialNumbers(int n) {
        digits(n);
        string s(a.size(), 'x');
        return dp(0, 1, 0, s);
    }
};
