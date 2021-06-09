class Solution {
public:
    vector<vector<int>> r90(const vector<vector<int>>& a){
        auto n = a.size();
        vector<vector<int>> res(n);
        for(int i = n-1;i >=0; i--){
            for(int j = 0; j<n; j++){
                res[j].push_back(a[i][j]);
            }
        }
        return res;
    }
    void print(const vector<vector<int>>& a){
        for(const auto& r : a){
            for(const auto& n : r){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        auto r = r90(mat);
        print(r);
        if(r==target) return true;
        r = r90(r);
        print(r);
        if(r==target) return true;
        r = r90(r);
        print(r);
        if(r==target) return true;
        return false;
    }
};
