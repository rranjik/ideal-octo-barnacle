class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i = 0; i<stones.size(); i++){
            q.push(stones[i]);
        }
        while(q.size()>=2){
            auto largest = q.top(); q.pop();
            auto secondlargest = q.top(); q.pop();
            if(largest!=secondlargest) q.push(largest-secondlargest);
        }
        if(q.size()) return q.top();
        return 0;
    }
};
