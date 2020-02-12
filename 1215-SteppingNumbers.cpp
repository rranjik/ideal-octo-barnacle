class Solution {
public:
    unordered_map<int, vector<int>> ch = {
        {0, {1}},
        {1, {0, 2}},
        {2, {1, 3}},
        {3, {2, 4}},
        {4, {3, 5}},
        {5, {4, 6}},
        {6, {5, 7}},
        {7, {6, 8}},
        {8, {7, 9}},
        {9, {8}}
    };
    
    void csn(string& curr, const int& w, vector<int>& res, vector<int> choices){
        if(curr.length()==w){
            int n = stol(curr);
            res.push_back(n);
            return;
        }
        else{
            for(const auto& c : choices){
                curr+=to_string(c);
                csn(curr, w, res, ch[c]);
                curr.pop_back();
            }
        }
    }
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        string c;
        if(low==0){
            res.push_back(0);
        }
        if(high==0)
            return res;    
        //cout<<"(int)log10(20)+1 = "<<(int)log10(20)+1<<endl;
        int ub = (int)log10(high)+1;
        cout<<"ub = "<<ub<<endl;
        bool todo = false;
        if(ub>=10){
            todo = true;
            ub = 9;
        }
        for(int i = (low?(int)log10(low)+1:1); i<= ub; i++)
            csn(c, i, res, {1, 2, 3, 4, 5, 6, 7, 8, 9});
        if(todo)
            csn(c, 10, res, {1, 2});
        cout<<"out"<<endl;
        res.erase(std::remove_if(
            res.begin(), res.end(),
            [low, high](const int& x) { 
                return x<low||x>high;
            }), res.end());
        //for(const auto& i : res){
        //    cout<<i<<endl;
        //}
        return res;
    }
};
