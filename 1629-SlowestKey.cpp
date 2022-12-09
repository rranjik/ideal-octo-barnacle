class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keyPress) {
        int longest = releaseTimes[0];
        char res = keyPress[0];
        for(int i = 1; i<releaseTimes.size(); i++){
            if(longest < releaseTimes[i]-releaseTimes[i-1]){
                longest = releaseTimes[i]-releaseTimes[i-1];
                res = keyPress[i];
            }else if(longest == releaseTimes[i]-releaseTimes[i-1]){
                if(res<keyPress[i]){
                    res = keyPress[i];
                }              
            }
        }
        return res;
    }
};
