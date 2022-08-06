class Solution {
public:
    double average(vector<int>& salary) {
        auto mini = *min_element(salary.begin(), salary.end());
        auto maxi = *max_element(salary.begin(), salary.end());
        int sum{};
        for(const auto& s : salary) sum+=s;
        sum-=mini;
        sum-=maxi;
        return (sum*1.0)/(salary.size()-2);
    }
};
