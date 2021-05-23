func restoreString(s string, indices []int) string {
    res := make([]byte, len(s))
    for i, v := range indices {
        res[v] = s[i]
    }
    return string(res)
}
