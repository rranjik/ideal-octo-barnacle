namespace std{
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p)const{
            return (hash<int>()(p.first)^0x94720283)^
            (hash<int>()(p.second)^0x759372D7);
        }
    };
}
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<pair<int, int>> rres;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        for(int i = 0; i<nums.size(); i++){
            auto n = nums[i];
            //auto t1 = (-1*k) + n;
            auto t2 = k+n;
            //cout<<"n = "<<n<<" looking for "<<t1<<" and "<<t2<<endl;
            if(m.find(t2)!=m.end()){
                for(const auto& j : m[t2]){
                    if(i!=j){
                        //if(n<t2)-
                        //t2 is always greater. given k>=0
                        //only look for numbers higher now.
                        //a smaller number will it selected,
                        //when it has its turn to be 'n'
                            rres.insert({n, t2});
                        //else
                            //rres.insert({t2, n});
                    }
                }
                //for(const auto& j : m[t1]){
                //    if(i!=j){
                //        if(i<j)
                //            rres.insert({i, j});
                //        else
                //            rres.insert({j, i});
                //    }
                //}
            }
            //if(m.find(t2)!=m.end()){
            //    for(const auto& j : m[t2]){
            //        if(i!=j){
            //            if(n<t2)
            //                rres.insert({n, t2});
            //            else
            //                rres.insert({t2, n});
            //        }
            //    }
            //}
        }
        return rres.size();
    }
};
