class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, multiset<int>> tally;
        for(int i = 0; i<items.size(); i++){
            tally[items[i][0]].insert(items[i][1]);
            if(tally[items[i][0]].size()>5){
                tally[items[i][0]].erase(begin(tally[items[i][0]]));
            }
        }
        for(auto it = tally.begin(); it!=tally.end(); it++){
            cout<<it->first<<": ";
            for(auto it2 = it->second.begin(); it2!=it->second.end(); it2++){
                cout<<*it2<<" ";
            }
            cout<<endl;
        }
        vector<vector<int>> res;
        for(auto it = tally.begin(); it!=tally.end(); it++){
            int sum = 0;
            for(auto it2 = it->second.begin(); it2!=it->second.end(); it2++){
                sum+=(*(it2));
            }
            sum/=5;
            //auto r = vector<int>({it->first, sum})
            res.push_back(vector<int>({it->first, sum}));
        }
        return res;
    }
};
