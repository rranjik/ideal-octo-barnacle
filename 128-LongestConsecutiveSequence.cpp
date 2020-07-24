class unionfind{
public:
    class Node{
    public:
        int val;
        Node* parent; 
        int count;
        Node(int n):val(n), parent(nullptr), count(1) {}
    };
    unordered_map<int, Node*> sets;
    unionfind(vector<int> nums){
        for(const auto& n : nums){
            if(sets.find(n)==sets.end()){
                Node* nn = new Node(n);
                nn->parent = nn;
                sets[n] = nn;
            }
        }
    }
    Node* findn(Node* n){
        if(!n) return nullptr;
        if(n->parent!=n){
            n->parent = findn(n->parent);
        }
        return n->parent;
    }
    Node* find(int a){
        if(sets.find(a)==sets.end()) return nullptr;
        return findn(sets[a]);
    }
    void uniunn(Node* a, Node * b){
        auto ap = findn(a);
        auto bp = findn(b);
        if(ap&&bp){
            if(ap!=bp){
                if(ap->count>bp->count){
                    bp->parent = ap;
                    ap->count+=bp->count;
                }else{
                    ap->parent = bp;
                    bp->count+=ap->count;
                }
            }
        }
    }
    void uniun(int a, int b){
        uniunn(sets[a], sets[b]);
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unionfind uf(nums);
        for(const auto& n : nums){
            uf.uniun(n, n+1);
            uf.uniun(n, n-1);
        }
        int res = 0;
        for(const auto& n : nums){
            res = max(res, uf.findn(uf.find(n))->count); 
        }
        return res;
    }
};
