class Solution {
public:
    int hIndex(vector<int>& citations) {
        reverse(citations.begin(), citations.end());
        for(int i = 1; i <=citations.size(); i++){
            if(citations[i-1]<=i-1)
                return i-1;
        }
        return citations.size();
    }
};
