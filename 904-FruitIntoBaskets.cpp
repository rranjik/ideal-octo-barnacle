class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i = 0;
        int j = 0;
        map<int, int> last_seen;
        set<int> collected;
        int res = 0;
        while(j<tree.size()){
            if(collected.size()<3){
                last_seen[tree[j]] = j;
                collected.insert(tree[j]);
            }
            if(collected.size()==3){
                int mini = numeric_limits<int>::max();
                int to_rem = -1;
                for(auto it : last_seen){
                    if(it.second<mini) {
                        mini = it.second;
                        to_rem = it.first;
                    }
                }
                i = mini+1;
                last_seen.erase(last_seen.find(to_rem));
                collected.erase(collected.find(to_rem));
            }
            res = max(res, (j-i+1));
            j++;
        }
        return res;
    }
};
