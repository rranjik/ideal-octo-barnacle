type item struct {
    v int
    l int
}
func largestValsFromLabels(values []int, labels []int, num_wanted int, use_limit int) int {
    items := []item{}
    for i,val:= range values{
        items = append(items, item{v:val, l:labels[i]})
    }
    sort.Slice(items, func(i,j int)bool{
        return items[i].v>items[j].v
    })
    for _,v := range items {
        fmt.Println(v)
    }
    use := make(map[int]int)
    used := 0
    res := 0
    for _,it := range items{
        if used >= num_wanted {
            break
        }
        v,ok := use[it.l]
        if !ok {
            res+=it.v
            use[it.l]++
            used++
        }else {
            if v<use_limit{
                res+=it.v
                use[it.l]++
                used++
            }
        }
    }
    return res
}
