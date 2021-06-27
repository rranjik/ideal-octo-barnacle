class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i<numbers.size()-1; i++){
            auto a = numbers[i];
            auto it = lower_bound(begin(numbers)+i+1, end(numbers), target-a);
            if(it!=numbers.end()){
                if(*it == target-a){
                    return {i+1, static_cast<int>(it-numbers.begin()+1)};
                }
            }
        }
        return {};
    }
};
