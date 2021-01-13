class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        bool stamped = true;
        auto total_stamps = 0;
        while(stamped){
            stamped = false;
            for(int sz = stamp.size(); sz>0; sz--){
                for(int i = 0; i<=stamp.size()-sz; i++){
                    auto new_stamp = string(i, '?')+stamp.substr(i, sz)+string(stamp.size()-sz-i, '?');
                    auto pos = target.find(new_stamp);
                    while(pos!=string::npos){
                        res.push_back(pos);
                        total_stamps += sz;
                        stamped = true;
                        fill(begin(target)+pos, begin(target)+pos+stamp.size(), '?');
                        pos = target.find(new_stamp);
                    }
                }
            }
        }
        reverse(begin(res), end(res));
        return total_stamps == target.size() ? res: vector<int>();
    }
};
