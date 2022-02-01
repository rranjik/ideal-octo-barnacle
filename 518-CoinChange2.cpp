class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> t(amount+1);
        t[0] = 1;
        //auto rng = default_random_engine{};
        //shuffle(begin(coins), end(coins), rng);
        for(const auto& c : coins){
            int i = 0;
            while((c+i)<=amount){
                t[c+i] += t[i];
                i++;
            }
            //int i = c;
            //while(i<=amount){
            //        t[i] = t[i-c]+t[i];
            //    i++;
            //}
        }
        return t[amount];
    }
};
