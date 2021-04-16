class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        //everything is next to each other
        if(s[2]-s[0] == 2) return {0, 0};
        auto closest = min(s[1]-s[0], s[2]-s[1]);
        //always try to move extreme next to mid, and the other extreme near 
        //the first two
        //a.......b.....c
        //.......ab.....c || a......cb...... || ac......b......
        //.......abc....c || ......acb...... || acb............
        auto mini = 2;
        if(closest<=2) mini = 1;
        //max will use all the spots between s2 and s0
        //there are s2-s0-1 usually but s1 takes up one more 
        //so s2-s0-2
        return {mini, s[2]-s[0]-2};
    }
};
