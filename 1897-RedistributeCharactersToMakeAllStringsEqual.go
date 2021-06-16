func makeEqual(words []string) bool {
    f := [26]int{}
    l := len(words)
    for _,w:=range words{
        for _,c := range w {
            n := c-'a'
            f[n]++
        }
    }
    for _,v := range(f){
        if v%l!=0 {
            return false
        }
    }
    return true
}
