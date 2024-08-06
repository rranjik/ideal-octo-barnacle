class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        unordered_map<int, int> of;
        unordered_map<int, int> ef;
        map<int, int, greater<int>> oif;
        map<int, int, greater<int>> eif;
        int om = 0;
        int em = 0;
        int odds = 0;
        int evens = 0;
        for(int i =0; i<nums.size(); i++){
            auto k = nums[i];
            if(i%2){
                of[k]++;
                om = max(om, of[k]);
                odds++;
            }else{
                ef[k]++;
                em = max(em, ef[k]);
                evens++;
            }
        }
        for(const auto& it : of){
            oif[it.second] = it.first;
        }
        for(const auto& it : ef){
            eif[it.second] = it.first;
        }
        cout<<oif.begin()->second<<" "<<eif.begin()->second<<endl;
        if(oif.begin()->second==eif.begin()->second){
            cout<<"same "<<endl;
            int res = nums.size();
            //if(oif.begin()->first>eif.begin()->first){
            //if((odds-om)<(evens-em)){
                cout<<"odds>evens"<<endl;
                auto nx = next(eif.begin());
                if(nx==eif.end()){
                    res = min(res, (odds-om)+(evens));
                }else
                res = min(res, (odds-om)+(evens-nx->first));
            //}else{
                cout<<"odds<=evens"<<endl;
                nx = next(oif.begin());
                if(nx==oif.end()){
                    res = min(res,(evens-em)+(odds));
                }else
                    res = min(res, (evens-em)+(odds-nx->first));
                return res;
            //}
        }
        return (odds-om)+(evens-em);
    }
};
