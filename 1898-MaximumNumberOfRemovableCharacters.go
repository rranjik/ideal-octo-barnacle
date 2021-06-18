func isSubSeq(s, p string) bool {
    if len(p)>len(s) {
        return false
    }
    i := 0
    j := 0
    for ;i<len(s)&&j<len(p);i++{
        if s[i]==p[j]{
            j++
        }
    }
    if j>=len(p) {
        return true
    }
    return false
}

func subseq(s string, skip []int) string {
    var b strings.Builder
    i := 0
    m := make(map[int]struct{})
    for i := range skip {
        m[skip[i]] = struct{}{}
    }
    for ;i<len(s); i++{
        if _,ok := m[i]; !ok {
            b.WriteByte(s[i])
        }
    }
    return b.String()
}
func maximumRemovals(s string, p string, removable []int) int {
    n := len(removable)
    l := 0
    r := n
    res := 0
    for l<=r {
        m:=(l+r)/2
        fmt.Println(l,r,m)
        s := subseq(s, removable[:m])
        fmt.Println(s)
        if isSubSeq(s, p) {
            fmt.Printf("is subseq\n")
            if res < m {
                res = m
            }
            l = m+1
        }else{
            fmt.Printf("is not\n")
            r = m-1
        }
    }
    return res
}
