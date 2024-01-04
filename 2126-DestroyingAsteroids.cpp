class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mass = m;
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i]<=mass){
                mass+=asteroids[i];
            }else return false;
        }
        return true;
    }
};
