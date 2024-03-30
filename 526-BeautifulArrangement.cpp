class Solution {
public:
    int res{};
    //p is the position we are truing till 
    //used[i] = 1 means that i planted/placed/used before 
    int n{};
    void dfs(int p, vector<int>& used){
        //cout<<"p = "<<p<<endl;
        if(p>n) {
            res++;
            return;
        }
        for(int i = 1; i<=n ;i++){
            if(!used[i]&&(i%p==0||p%i==0)){
                used[i] = 1;
                dfs(p+1, used);
                used[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        this->n = n;
        vector<int> used(n+1);
        dfs(1, used);
        return res;
    }
};
