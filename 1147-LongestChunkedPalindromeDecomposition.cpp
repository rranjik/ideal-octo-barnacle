class Solution {
public:
    int longestDecomposition(string t) {
        int n = t.size();
        for(int i = 0; i<n/2; i++){
            if(t.substr(0, i+1)==t.substr(n-i-1)){
                return 2+longestDecomposition(t.substr(i+1, n-2*i-2));
            }
        }
        if(n) return 1;
        return 0;
    }
};
/*
i+1...n-i-2
(n-i-2)-i-1+1
*/
