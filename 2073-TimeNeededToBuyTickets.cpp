class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        auto done = false;
        while(!done){
            for(int i = 0; !done&&i<tickets.size(); i++){
                if(tickets[i]){
                    res++;
                    tickets[i]--;
                }
                if(i==k&&tickets[i]==0){
                    done = true;
                }
            }
        }
        return res;
    }
};
