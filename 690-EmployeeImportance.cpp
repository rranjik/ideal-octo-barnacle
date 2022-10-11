/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> e, int id) {
        unordered_map<int, bool> v;
        unordered_map<int, int> imp;
        unordered_map<int, vector<int>> g;
        for(int i = 0; i<e.size(); i++){
            v[e[i]->id] = false;
            imp[e[i]->id] = e[i]->importance;
            for(int j = 0; j<e[i]->subordinates.size(); j++){
                g[e[i]->id].push_back(e[i]->subordinates[j]);
            }
        }
        
        queue<int> q;
        q.push(id);
        int res{};
        while(!q.empty()){
            auto emp = q.front();
            q.pop();
            res+=imp[emp];
            for(const auto& s : g[emp]){
                if(!v[s]){
                    q.push(s);
                    v[s] = true;
                }
            }
        }
        return res;
    }
};
