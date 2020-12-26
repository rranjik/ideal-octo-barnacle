// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row = rand7()-1;
        int col = rand7()-1;
        int idx = (col+(row*7));
        while(idx>=40){
            row = rand7()-1;
            col = rand7()-1;
            idx = (col+(row*7));
        }
        return (idx%10)+1;
    }
};
