class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
                for(int i = 0; i < V; i++) {
            int cur = K;
            // Move left
            while(cur > 0 && heights[cur] >= heights[cur - 1]) {
                cur--;
            }
            // Move right
            while(cur < heights.size() - 1 && heights[cur] >= heights[cur + 1]) {
                cur++;
            }
            // Move left to K
            while(cur > K && heights[cur] >= heights[cur - 1]) {
                cur--;
            }
            heights[cur]++;
        }

        return heights;
    }
};
