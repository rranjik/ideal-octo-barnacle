class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        auto mini = abs(target[0])+abs(target[1]);
        //cout<<"mini = "<<maxi<<endl;
        for(const auto& g : ghosts){
            auto reach = abs(target[0]-g[0])+abs(target[1]-g[1]);
            //cout<<"reach = "<<reach<<endl;
            if(mini>=reach) return false;
        }
        return true;
    }
};
