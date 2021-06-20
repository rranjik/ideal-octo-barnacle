func dfs(p int, adjl map[int][]int) int {
    if _,ok := c[p]; ok {
        return c[p]
    }
    res := p
    if _,ok := adjl[p]; ok {
        for _,v := range adjl[p]{
            if k[res] > k[v] {
                res = v
            }
            a := dfs(v, adjl)
            if k[res] > k[a] {
                res = a
            }
        }
    }
    c[p] = res
    return res
}
var n int
var k []int
var c map[int]int
func loudAndRich(r [][]int, q []int) []int {
    c = make(map[int]int)
    k = q
    adjl := make (map[int][]int)
    n = len(q)
    for _,v :=range r{
        adjl[v[1]] = append(adjl[v[1]], v[0])
    }
    res := []int{}
    for i := range q{
        res = append(res, dfs(i, adjl))
    }
    return res
}
