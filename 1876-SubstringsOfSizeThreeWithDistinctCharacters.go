func countGoodSubstrings(s string) int {
    if len(s) < 3 {
        return 0
    }
    res := 0
    for i := 2; i<len(s); i++ {
        if s[i-2]!=s[i-1] && s[i-1]!=s[i] && s[i-2] != s[i] {
            res++
        }
    }
    return res
}
