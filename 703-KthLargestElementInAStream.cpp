class ValU{
    public:
    //actual value
    int v;
    //uniq id with value
    int u;
    ValU(int _v, int _u):v(_v), u(_u) {}
};
class CompValU{
    public:
    bool operator()(const ValU& a, const ValU& b){
        if(a.v==b.v) return a.u>b.u;
        return a.v>b.v;
        //if(a.v>b.v) return true;
        //else if(a.v<b.v) return false;
        //else return a.u>b.u;
    }
};
class KthLargest {
public:
    int u = 0;
    priority_queue<ValU, vector<ValU>, CompValU> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i<nums.size(); i++){
            u++;
            q.push(ValU(nums[i], u));
            if(q.size()>k){
                q.pop();
            }
        }
    }
    
    int add(int val) {
        u++;
        q.push(ValU(val, u));
        if(q.size()>k){
            q.pop();
        }
        return q.top().v;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
