class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int llx1 = rec1[0];
        int lly1 = rec1[1];
        int urx1 = rec1[2];
        int ury1 = rec1[3];
        
        int llx2 = rec2[0];
        int lly2 = rec2[1];
        int urx2 = rec2[2];
        int ury2 = rec2[3];
        
        return !((llx2>=urx1) || (lly2>=ury1) || (urx2<=llx1) || (ury2<=lly1));
    }
};
