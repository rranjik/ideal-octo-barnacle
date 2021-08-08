class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> tables;
        set<string> dishes;
        for(const auto& order : orders){
            auto tbl = stoi(order[1]);
            tables[tbl][order[2]]++;
            dishes.insert(order[2]);
        }
        vector<vector<string>> res;
        vector<string> header;
        header.push_back("Table");
        for(const auto& dish : dishes){
            header.push_back(dish);
        }
        res.push_back(header);
        for(auto& it:tables){
            vector<string> tableo;
            tableo.push_back(to_string(it.first));
            for(const auto& dish : dishes){
                tableo.push_back(to_string(it.second[dish]));
            }
            res.push_back(tableo);
        }
        return res;
    }
};
