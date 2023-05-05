class Solution {
public:
    double angleClock(int h, int m) {
        auto hour_angle = 0.5*(60*h + m);
        auto minute_angle = 6*m;
        auto angle = abs(hour_angle-minute_angle);
        return min(360 - angle, angle);
    }
};
