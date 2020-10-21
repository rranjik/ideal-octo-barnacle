class Solution {
public:
        int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<pair<int, int>> ple;
        stack<pair<int, int>> nle;
        vector<int> rheights = heights;
        reverse(begin(rheights), end(rheights));
        ple.push({-1, -1});
        nle.push({-1, -1});
        vector<int> numTimesHopLeftToReachSentinelOrSmaller;
        vector<int> numTimesHopRightToReachSentinelOrSmaller;
        for(int i = 0; i<heights.size(); i++){
            while(ple.top().first>=heights[i]){
                ple.pop();
            }
            cout<<"i = "<<i<<"; ple.top().second = "<<
                ple.top().second<<endl;
            numTimesHopLeftToReachSentinelOrSmaller.push_back(
                i-(ple.top().second+1));
            ple.push({heights[i], i});
            while(nle.top().first>=rheights[i]){
                nle.pop();
            }
            numTimesHopRightToReachSentinelOrSmaller.push_back(
                i-(nle.top().second+1));
            nle.push({rheights[i], i});
        }
        reverse(begin(numTimesHopRightToReachSentinelOrSmaller),
               end(numTimesHopRightToReachSentinelOrSmaller));
        for(const auto& numberOfHops :
            numTimesHopLeftToReachSentinelOrSmaller ){
            cout<<numberOfHops<<" ";
        }
        cout<<endl;
        for(const auto& numberOfHops :
            numTimesHopRightToReachSentinelOrSmaller ){
            cout<<numberOfHops<<" ";
        }
        cout<<endl;
        vector<int> minSelfiHopLeftiHopRight;
        for(int i = 0; i<len; i++){
            minSelfiHopLeftiHopRight.push_back(min({heights[i], 
              heights[i-numTimesHopLeftToReachSentinelOrSmaller[i]],
              heights[i+numTimesHopRightToReachSentinelOrSmaller[i]]}));
        }
        for(const auto& minHeight :
            minSelfiHopLeftiHopRight ){
            cout<<minHeight<<" ";
        }
        cout<<endl;
        vector<int> moveWidth;
        for(int i = 0; i<len; i++){
            moveWidth.push_back(1+
                 numTimesHopLeftToReachSentinelOrSmaller[i]+
                 numTimesHopRightToReachSentinelOrSmaller[i]);
        }
        for(const auto& width :
            moveWidth ){
            cout<<width<<" ";
        }
        cout<<endl;
        vector<int> heightsByMoving;
        for(int i = 0; i<len; i++){
            heightsByMoving.push_back(
                minSelfiHopLeftiHopRight[i]*moveWidth[i]);
        }
        for(const auto& moveHeight :
            heightsByMoving ){
            cout<<moveHeight<<" ";
        }
        cout<<endl;
        int res = 0;
        for(int i = 0; i<len; i++){
            res = max({res, heights[i], heightsByMoving[i]});
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<int> histogram(matrix[0].size());
        int res = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                histogram[j] = (matrix[i][j] == '1') ? histogram[j]+1 : 0;
            }
            res = max(res, largestRectangleArea(histogram));
        }
        return res;
    }
};
