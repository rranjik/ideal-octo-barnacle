class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        //prefix sum without being grumpy the entire day
        unordered_map<int, int> pnog;
        //prefix sum knowing that the owner the grumpy on `grumpy` minutes
        unordered_map<int, int> pg;
        int res = 0;
        int gs =0;
        int s = 0;
        for(int i = 0; i<customers.size(); i++){
            gs+=(grumpy[i]?0:customers[i]);
            s+=customers[i];
            pnog.insert({i, s});
            pg.insert({i, gs});
        }
        for(int i = X-1; i<customers.size(); i++){
            //gain without being grumpy for x minutes
            int gwobgfxm = pnog[i]-pnog[i-(X-1)-1];
            //gain rest of the day
            int rotd = (pg[i-(X-1)-1]-pg[-1])+(pg[customers.size()-1]-pg[i]);
            res = max(res, (gwobgfxm+rotd));
        }
        return res;
    }
};
