class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int, unordered_set<int>> seen;
        seen[0].insert(0);
        pair<int, int> c{0, 0};
        for(const auto& p : path){
            switch(p){
                case 'N':
                    c.first+=1;
                break;
                case 'S':
                    c.first-=1;
                break;
                case 'E':
                    c.second+=1;
                break;
                case 'W':
                    c.second-=1;
                break;
            }
            if(seen.find(c.first)!=seen.end()
               &&seen[c.first].find(c.second)!=seen[c.first].end()) 
                return true;
            seen[c.first].insert(c.second);
        }
        return false;
    }
};
