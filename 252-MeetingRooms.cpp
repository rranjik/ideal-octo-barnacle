class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& i) {
        sort(i.begin(), i.end());
        int last_end = -1;
        for(int j = 0; j<i.size(); j++){
            if(last_end>i[j][0]) return false;
            last_end = i[j][1];
        }
        return true;
    }
};
