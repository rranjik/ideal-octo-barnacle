func monotoneIncreasingDigits(n int) int {
    s := strconv.Itoa(n)
    b := []byte(s)
    m := len(s)
    for i:=len(s)-1; i>0; i--{
        if b[i-1] > b[i] {
            b[i-1] = b[i-1]-1
            m = i
        }
    }
    for i:=m; i<len(s); i++ {
        b[i] = '9'
    }
    res,_ := strconv.Atoi(string(b))
    return res
}
