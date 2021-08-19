class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int d = 0;
        if(!nums.size()) return {};
        vector<int> res;
        map<int, int, greater<int>> to_print;
        map<int, int, greater<int>> to_print_n;
        to_print.insert({0, 0});
        while(to_print.size()){
            to_print_n = to_print;
            for(auto& it: to_print){
                //cout<<"inserting row "<<it.first<<" element "<<it.second<<endl;
                res.push_back(nums[it.first][it.second]);
                if(!it.second){
                    if(it.first+1<nums.size()) {
                        //cout<<"adding new row "<<it.first+1<<endl;
                        to_print_n.insert({it.first+1, 0});
                    }
                }
                to_print_n[it.first]++;
                it.second++;
                if(it.second>=nums[it.first].size()) {
                    //cout<<"removing old row "<<it.first<<endl;
                    to_print_n.erase(to_print_n.find(it.first));
                }
            }
            swap(to_print, to_print_n);
        }
        return res;
    }
};
