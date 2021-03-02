class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1;
        for(int i = 0; i<list1.size(); i++){
            m1[list1[i]] = i;
        }
        vector<string> res;
        int mini = numeric_limits<int>::max();
        for(int j = 0; j<list2.size(); j++){
            if(m1.find(list2[j])!=m1.end()){
                if(mini>(m1[list2[j]]+j)){
                    mini = m1[list2[j]]+j;
                    res.clear();
                    res.push_back(list2[j]);
                }else if(mini==(m1[list2[j]]+j)){
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};
