class Solution {
public:
    int cnt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //original number n, curr, left digits
    long long dfs(long long n, long long v, int l){
        if(l==0){
            //0 cannot be in the answer
            //0 cannot occur even '1' time
            //so start from 1
            for(int i = 1; i<=9; i++){
                //did I use i ? but, did I
                //not use it fully ?
                if(cnt[i]!=i&&cnt[i]!=0)
                    return 0;
            }
            //must be greater than original
            return v>n?v:0;
        }
        long long res = 0;
        //the iteration order ensures that 
        //we treat we smaller numbers first 
        //we will have looked at 1333 before
        //4444; so exit the first time you 
        //a non-zero return value; you have no
        //buisiness looking for higher value 
        for(int i = 1; res==0&&i<=9; i++){
            //can I use i ? && is there 
            //enough of it left to use ?
            if(cnt[i]>0 && cnt[i]<=l){
                cnt[i]--;
                res = dfs(n, v*10+i, l-1);
                cnt[i]++;
            }
        }
        return res;
    }
    int nextBeautifulNumber(int n) {
        int sz = to_string(n).size();
        return dfs(n, 0, sz)?:dfs(n, 0, sz+1);
    }
};
