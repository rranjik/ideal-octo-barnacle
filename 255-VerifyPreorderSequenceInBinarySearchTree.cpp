class Solution {
public:
    bool ver(int i, int j, pair<int, int> r){
        //cout<<"i = "<<i<<"; j = "<<j<<"; min "<<r.first<<"; max = "<<r.second<<endl;
        if(i>p.size()) return true;
        if(i>j) return true;
        if(i==j){
            return p[i]>=r.first&&p[i]<=r.second;
        }
        if(!(p[i]>=r.first&&p[i]<=r.second))
            return false;
        bool children = true;
        for(int k = i+1; k<=j; k++){
            if(p[k]>p[i]){
                children &= ver(k, j, {p[i], r.second});
                children &= ver(i+1, k-1, {r.first, p[i]});
                return children;
            }
        }
        children &= ver(i+1, j, {r.first, p[i]});
        return children;
    }
    vector<int> p;
    bool verifyPreorder(vector<int>& preorder) {
        p = preorder;
        return ver(0, p.size()-1, {numeric_limits<int>::min(), numeric_limits<int>::max()});
    }
};
