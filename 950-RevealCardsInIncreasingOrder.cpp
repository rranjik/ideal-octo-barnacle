class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck));
        vector<int> res(deck.size(), -1);
        auto skipped = true;
        auto done = false;
        int i = 0;
        int next = 0;
        int m = deck.size();
        while(!done){
            if(skipped&&res[next]==-1){
                res[next] = deck[i];
                i++;
                if(i==deck.size()) done = true;
                next = (next+1)%m;
                skipped = false;
            }else if(!skipped&&res[next]==-1){
                skipped=true;
                next = (next+1)%m;
            }else next = (next+1)%m;
        }
        return res;
    }
};
