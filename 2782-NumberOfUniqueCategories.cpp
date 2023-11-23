/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    void dfs(int i){
        v[i] = true;
        for(const auto& c : adjl[i]){
            if(!v[c]) dfs(c);
        }
    }
    vector<vector<int>> adjl;
    vector<bool> v;
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        int res = 0;
        adjl = vector<vector<int>>(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(categoryHandler->haveSameCategory(i, j)){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        v = vector<bool>(n);
        for(int i = 0; i<n; i++){
            if(!v[i]){
                res++;
                dfs(i);
            }
        }
        return res;
    }
};
