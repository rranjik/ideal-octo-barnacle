class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        unordered_map<char, vector<int>> dir = {
            {'U', {-1, 0}},
            {'D', {1, 0}},
            {'L', {0, -1}},
            {'R', {0, 1}}
        };
        vector<int> res;
        for(int i = 0; i<s.size(); i++){
            int r = startPos[0];
            int c = startPos[1];
            int count = 0;
            for(int j = i; j<s.size(); j++){
                r+=dir[s[j]][0];
                c+=dir[s[j]][1];
                if(r<0||r>=n||c<0||c>=n) break;
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
