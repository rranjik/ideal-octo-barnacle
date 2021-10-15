class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixor;
        int prev = 0;
        for(const auto& a : arr){
            prev^=a;
            prefixor.push_back(prev);
        }
        int res{};
        for(int i = 0; i<arr.size()-1; i++){
            for(int j = i+1; j<arr.size(); j++){
                for(int k = j; k<arr.size(); k++){
                    int a = prefixor[j-1]^(i-1<0?0:prefixor[i-1]);
                    int b = prefixor[k]^prefixor[j-1];
                    if(a==b) res++;
                }
            }
        }
        return res;
    }
};
