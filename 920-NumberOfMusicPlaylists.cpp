class Solution {
public:
    long dp(int i, int j){
        //playlist = {}
        if(i==0&&j==0) return 1;
        //no valid list with 0 slots 
        //but non-zero unique songs
        //or with any number slots but 
        //zero unique songs
        if(i==0||j==0) return 0;
        if(c[i][j]!=-1) return c[i][j];
        long res = 0;
        //play a uniqe song
        //#of unique songs left = n-j+1
        //increases # of slots and # of unique 
        //songs 
        //how n-j+1 ? you have a total of 
        //n unique songs (note: n and goal 
        //are different), but you are leaving
        //j-1 unique songs to the subproblem
        //by choosing one unique song here
        //so we have n-(j-1) = n-j+1 unique songs
        //to choose from
        res += (dp(i-1, j-1)*(n-j+1))%mod;
        res %= mod;
        if(j>k){
            //if you have played more than k
            //then you can choose some song that
            //was played already. #of slots increase
            //but unique songs remain the same
            res += (dp(i-1, j)*(j-k))%mod;
            res %= mod;
        }
        return c[i][j] = res;
    }
    int k;
    int n;
    int mod = 1e9+7;
    vector<vector<int>> c;
    int numMusicPlaylists(int n, int goal, int k) {
        c = vector<vector<int>>(goal+1, vector<int>(n+1, -1));
        this->k = k;
        this->n = n;
        return dp(goal, n);
    }
};
