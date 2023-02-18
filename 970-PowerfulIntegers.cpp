namespace std{
    template <>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p)const {
            return (hash<int>()(p.first)<<1)^(hash<int>()(p.second));
        }
    };
}
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>> seen;
        q.push({0, 0});
        seen.insert({0, 0});
        if(x==1&&y==1){
            if(bound>=2) return {2};
            return {};
        }else if(x==1){
            vector<int> r;
            for(int i = 0; pow(y, i)+1<=bound; i++){
                r.push_back(pow(y, i)+1);
            }
            return r;
        }else if(y==1){
            vector<int> r;
            for(int i = 0; pow(x, i)+1<=bound; i++){
                r.push_back(pow(x, i)+1);
            }
            return r;
        }
        while(!q.empty()){
            auto t = q.front();
            cout<<"t = "<<t.first<<", "<<t.second<<endl;
            q.pop();
            auto i = t.first;
            auto j = t.second;
            auto r = pow(x, i)+pow(y, j);
            res.insert(r);
            if(seen.find({i+1, j})==seen.end()){
                if(pow(x, i+1)+pow(y, j)<=bound){
                    q.push({i+1, j});
                }
            }
            if(seen.find({i, j+1})==seen.end()){
                if(pow(x, i)+pow(y, j+1)<=bound){
                    q.push({i, j+1});
                }
            }
            seen.insert({i+1, j});
            seen.insert({i, j+1});
        }
        return vector<int>({res.begin(), res.end()});
    }
};
