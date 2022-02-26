class Solution {
public:
    bool dfs(int i){
        if(i>=b.size()) return false;
        if(i==b.size()-1){
            return true;
        }
        if(b[i]){
            return dfs(i+2);
        }else return dfs(i+1);
    }
    vector<int> b;
    bool isOneBitCharacter(vector<int>& bits) {
        b = bits;
        return dfs(0);
    }
};
