class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res{};
        for(int i = 0; i<s.length();){
            auto c = s[i];
            auto si = i;
            i++;
            while(i<s.length()&&s[i]==c){
               i++; 
            }
            auto ei = i-1;
            if(ei-si+1>1){
                auto m = *max_element(cost.begin()+si, cost.begin()+i);
                bool ms = false;
                for(int j = si; j<=ei; j++){
                    if(m!=cost[j]){
                        res+=cost[j];
                    }else {
                        if(!ms) ms = true;
                        else{
                            res+=cost[j];
                        }
                    }
                }
            }
        }
        return res;
    }
};
