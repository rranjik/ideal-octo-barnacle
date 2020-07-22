class Solution {
public:
    bool collide(int a, int b){
        if(a>0&&b<0) return true;
        else return false;
    }
    int sim(int a, int b){
        if(abs(a)==abs(b)) return 0;
        if(abs(a)>abs(b)) return a;
        else return b;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> a;
        for(const auto& as : asteroids){
            //new asteroid to put in
            int nas = as;
            //is it in yet ?
            bool in = false;
            while(!a.empty()&&!in&&nas){
                //top asteroid
                int tas = a.top();
                if(collide(tas, nas)){
                    a.pop();
                    nas = sim(tas, nas);
                }else {
                    a.push(nas);
                    in = true;
                }
            }
            if(a.empty()&&!in&&nas){
                a.push(nas);
            }
        }
        vector<int> res;
        while(!a.empty()){
            res.push_back(a.top());
            a.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
