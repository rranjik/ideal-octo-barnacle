class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int max = 1;
        while(label>max){ 
        //when label is equal or less 
        //than max we've found max in 
        //level
            max = max*2 +1;
        }
        vector<int> res;
        int revl = (max/2+1)+max-label;
        while(label!=0&&revl!=0){
            res.push_back(label);
            label/=2;
            revl/=2;
            swap(revl, label);
        }
        reverse(begin(res), end(res));
        return res;
    }
};
