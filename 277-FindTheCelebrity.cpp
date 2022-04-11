// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        //proposed celebrity
        int pc = -1;
        for(int i = 0; i<n; i++){
            bool knowsAnyone = false;
            for(int j = 0; !knowsAnyone&&j<n; j++){
                if(i!=j){
                    if(knows(i, j)){
                        knowsAnyone = true;
                    }
                }
            }
            if(!knowsAnyone){
                bool everyoneElseKnows = true;
                for(int k = 0; everyoneElseKnows&&k<n; k++){
                    if(i!=k){
                        if(!knows(k, i)){
                            everyoneElseKnows = false;
                        }
                    }
                }
                if(everyoneElseKnows) {
                    pc = i;
                    break;
                }
            }
        }
        return pc;
    }
};
