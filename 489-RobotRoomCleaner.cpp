/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    using pii = pair<int, int>;
    set<pii> cleaned;
    vector<pii> dirs;
    int dfs(int x, int y, int i, Robot& r){
        if(cleaned.find({x, y})!=cleaned.end()) return i; 
        r.clean();
        cleaned.insert({x, y});
        int n = 0;
        do{
            int d = i;
            if(r.move()){
                d = dfs(x+dirs[i].first, y+dirs[i].second, i, r);
                r.turnRight();
                r.turnRight();
                r.move();
                r.turnRight();
                r.turnRight();
            }
            n++;
            r.turnRight();
            i = (i+1)%4;
        }while(n<4);
        return i;
    }
    void cleanRoom(Robot& robot) {
        dirs.push_back({-1, 0});
        dirs.push_back({0, 1});
        dirs.push_back({1, 0});
        dirs.push_back({0, -1});
        int i = 0;
        dfs(0, 0, i, robot);
    }
};
