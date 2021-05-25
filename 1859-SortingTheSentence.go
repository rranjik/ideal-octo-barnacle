func sortSentence(s string) string {
    w := []string{}
    cw := ""
    for _, c := range s {
        if c ==' '{
            w = append(w, cw)
            cw = ""
        }else{
            cw += string(c)
        }
    }
    w = append(w, cw)
    fmt.Println(w)
    m := make(map[int]string)
    indices := []int{}
    for _, d := range w {
        l := len(d)
        n := int(d[l-1] - '0')
        indices = append(indices, n)
        m[n] = d[:l-1]
    }
    res := ""
    sep := ""
    for i,_ := range indices {
        res += sep
        res += m[i+1]
        sep = " "
    }
    fmt.Println(m)
    return res 
}
