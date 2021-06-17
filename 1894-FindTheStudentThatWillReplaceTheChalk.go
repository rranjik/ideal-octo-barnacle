func chalkReplacer(chalk []int, k int) int {
    s := 0
    for _,v := range chalk {
        s+=v
    }
    fmt.Println(s)
    fmt.Println(k)
    rounds := k/s
    k-=(rounds*s)
    fmt.Println(k)
    for i,v := range chalk {
        if k<v {
            return i
        }
        k-=v
    }
    return -1
}
