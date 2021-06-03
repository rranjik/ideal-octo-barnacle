func numberify(s string) string {
    res := ""
    for _,c := range s{
        fmt.Printf("%c = %d\n", c, int(c-'a'))
        res = res + strconv.Itoa(int(c-'a'))
    }
    fmt.Println(res)
    return res
}

func isSumEqual(f string, s string, t string) bool {
    fn,_ := strconv.Atoi(numberify(f))
    sn,_ := strconv.Atoi(numberify(s))
    tn,_ := strconv.Atoi(numberify(t))
    return fn+sn == tn
}
