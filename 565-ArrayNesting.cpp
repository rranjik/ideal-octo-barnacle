class Solution {
public:
    int arrayNesting(vector<int>& nn) {
        int res{};
        for(int i = 0; i<nn.size(); i++){
            auto j = i;
            auto size = 0;
            while(nn[j]>=0){
                auto oldj = j;
                j = nn[j];
                nn[oldj] = -1;
                size++;
            }
            res = max(res, size);
        }
        return res;
    }
};
