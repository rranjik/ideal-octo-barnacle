class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(const auto& a : asteroids){
            if(s.empty()){
                s.push_back(a);
                continue;
            }
            if(a>0){
                s.push_back(a);
                continue;
            }
            bool dead = false;
            while(!s.empty()&&s.back()>0&&s.back()<=abs(a)){
                if(s.back()==abs(a)) {dead = true; s.pop_back(); break;}
                s.pop_back();
            }
            if(dead) continue;
            if(s.empty()||s.back()<0){
                s.push_back(a);
            }
        }
        return s;
    }
};
