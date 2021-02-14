class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        auto ires = rec2[0]>=rec1[2] || //rec2 is to the right
            rec2[2]<=rec1[0] || //rec2 is to the left
            rec2[3]<=rec1[1] || //rec2 is at the bottom
            rec2[1]>=rec1[3]; //rec2 is at the top
        return !ires;
    }
};
