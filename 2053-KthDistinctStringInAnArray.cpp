class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        unordered_map<string, int> in;
        for(int i = 0; i<arr.size(); i++){
            auto a = arr[i];
            m[a]++;
            in[a] = i;
        }
        map<int, string> u;
        for(const auto& it : m){
            if(it.second==1){
                u[in[it.first]] = it.first;
            }
        }
        if(u.size()<k) return {};
        int i = 1;
        for(const auto& it : u){
            if(i==k) return it.second;
            i++;
        }
        return {};
    }
};
