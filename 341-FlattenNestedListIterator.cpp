/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> l;
    using vni = vector<NestedInteger>;
    using ni = NestedInteger;
    void dfs(const vni& nl, vector<int>& res){
        if(nl.size()==0) return;
        for(const auto& i : nl){
            if(i.isInteger()){
                res.push_back(i.getInteger());
            }else{
                dfs(i.getList(), res);
            }
        }
    }
    int curr = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList, l);
        //for(const auto& n : l){
        //    cout<<n;
        //}
        cout<<endl;
    }

    int next() {
        return l[curr++];
    }

    bool hasNext() {
        return curr<l.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
