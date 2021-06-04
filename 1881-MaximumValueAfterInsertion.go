func firstSmall(n string, x int) int {
    for i,v:=range n{
        d := int(v-'0')
        if(d<x) {
            return i
        }
    }
    return len(n)
}
func firstLarge(n string, x int) int {
    for i,v:=range n{
        d := int(v-'0')
        if(d>x) {
            return i
        }
    }
    return len(n)
}
func maxValue(n string, x int) string {
    neg := n[0]=='-'
    fs := firstSmall(n,x)
    fl := firstLarge(n,x)
    fmt.Println(fs, fl)
    if(neg){
        bsn := []byte(n)
        bsv := make([]byte, len(bsn))
        copy(bsv, bsn)
        res := append(bsn[:fl], []byte(strconv.Itoa(x))...)
        res = append(res, bsv[fl:]...)
        return string(res)
    }
    bsn := []byte(n)
    bsv := make([]byte, len(bsn))
    copy(bsv, bsn)
    res := append(bsn[:fs], []byte(strconv.Itoa(x))...)
    res = append(res, bsv[fs:]...)
    return string(res)
}
