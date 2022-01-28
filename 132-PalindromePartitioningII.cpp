class Solution {
public:
    int minCut(string s) {
        if(s.size()<=1) return 0;
        int len = s.length();
        vector<int> dp(s.length(), numeric_limits<int>::max());
        for(int mid = 0; mid<s.length(); mid++){
            for(int start = mid, end = mid; start>=0&&end<len&&s[start]==s[end]; start--, end++){
                int newCutAtEnd = (start==0) ? 0 : dp[start-1] +1;
                dp[end] = min(dp[end], newCutAtEnd);
            }
            for(int start = mid-1, end = mid; 
                start>=0&&end<len&&s[start]==s[end]; start--, end++){
                int newCutAtEnd = (start==0) ? 0 : dp[start-1] +1;
                dp[end] = min(dp[end], newCutAtEnd);
            }
        }
        return dp[len-1];
    }
    //public int minCut(String s) {
    //    // validate input
    //    if (s == null || s.length() <= 1) {
    //        return 0;
    //    }
    //    // dp
    //    int N = s.length();
    //    int[] dp = IntStream.range(0, N).toArray(); // initial value: dp[i] = i
//
    //    for (int mid = 1; mid <  N; mid++) { // iterate through all chars as mid point of palindrome
    //        // CASE 1. odd len: center is at index mid, expand on both sides
    //        for (int start = mid, end = mid; start >= 0 && end < N && s.charAt(start) == s.charAt(end); start--, end++) {
    //            int newCutAtEnd = (start == 0) ? 0 : dp[start - 1] + 1;
    //            dp[end] = Math.min(dp[end], newCutAtEnd);
    //        }
    //        // CASE 2: even len: center is between [mid-1,mid], expand on both sides
    //        for (int start = mid - 1, end = mid; start >= 0 && end < N && s.charAt(start) == s.charAt(end); start--, end++) {
    //            int newCutAtEnd = (start == 0) ? 0 : dp[start - 1] + 1;
    //            dp[end] = Math.min(dp[end], newCutAtEnd);
    //        }
    //    }
    //    return dp[N - 1];
    //}
};
