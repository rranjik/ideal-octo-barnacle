class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        unordered_map<int, int> m;
        for(int i = 0; i<edges.size(); i++){
            m[edges[i][0]]++;
            m[edges[i][1]]++;
            if(m[edges[i][0]]>1) return edges[i][0];
            if(m[edges[i][1]]>1) return edges[i][1];
        }
        return -1;
    }
};
