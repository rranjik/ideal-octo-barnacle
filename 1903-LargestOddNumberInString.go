func largestOddNumber(num string) string {
    for i:=len(num)-1; i>=0; i--{
        v:=num[i]
        n:=int(v-'0')
        fmt.Println(v,n)
        if n%2!=0 {
            return num[:i+1]
        }
    }
    return ""
}
