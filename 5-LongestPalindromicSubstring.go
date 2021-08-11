func longestPalindrome(s string) string {
    n := len(s)
    if n<= 1 {
        return s
    }
    d1 := make([]int, n)
    d2 := make([]int, n)
    l:=0
    r:=-1
    res := ""
    for i,_ := range s {
        var k int
        if i>r {
            k = 1
        }else{
            if d1[l+r-i]>r-i+1 {
                k = r-i+1
            }else{
                k = d1[l+r-i]
            }
        }
        for 0<=i-k && i+k<n && s[i-k] == s[i+k] {
            k++
        }
        d1[i] = k
        if len(res) < 2*d1[i]-1{
            res = s[i-k+1:i+k]
        }
        k--
        if i+k>r{
            l = i-k
            r = i+k
        }
    }
        
    l = 0
    r = -1
    for i,_ := range s {
        var k int
        if i>r{
            k = 0
        }else{
            if d2[l+r-i+1]>r-i+1{
                k = r-i+1
            }else{
                k = d2[l+r-i+1]
            }
        }
        for 0<= i-k-1 && i+k<n && s[i-k-1] == s[i+k] {
            k++
        }
        d2[i] = k
        if len(res) < 2*d2[i]{
            res = s[i-k:i+k]
        }
        k--
        if i+k>r{
            l = i-k-1
            r = i+k
        }
    }
    //fmt.Println(d1)
    //fmt.Println(d2)
    return res 
}
