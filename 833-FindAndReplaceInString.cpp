class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int, pair<int, string>, greater<int>> replaceMap;
        for(int i = 0; i< indexes.size(); i++){
            if(!S.compare(indexes[i], sources[i].size(), sources[i])){
                replaceMap[indexes[i]] = 
                {sources[i].size(), targets[i]};
            }
        }
        for(auto it : replaceMap){
            S.replace(it.first, it.second.first, it.second.second);
        }
        return S;
    }
};
