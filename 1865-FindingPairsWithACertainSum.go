type FindSumPairs struct {
    n1 []int
    n2 []int
    m map[int]int
    im map[int]int
}


func Constructor(nums1 []int, nums2 []int) FindSumPairs {
    sort.Ints(nums1);
    fsp := FindSumPairs{
        n1: nums1,
        n2: nums2,
        m: make(map[int]int),
        im: make(map[int]int),
    }
    for _,v := range nums2{
        fsp.m[v]++
    }
    return fsp
}


func (p *FindSumPairs) Add(index int, val int)  {
    oldv := p.n2[index]
    newv := oldv+val
    p.n2[index] = newv
    p.m[oldv]--
    if p.m[oldv] == 0{
        delete(p.m, oldv)
    }
    p.m[newv]++;
}


func (p *FindSumPairs) Count(tot int) int {
    res := 0 
    for _, v := range p.n1{
        req := tot-v
        //fmt.Printf("v = %d, tot = %d; req = %d, req+v = %d", v, tot, tot-v, v+req)
        f,ok := p.m[req]
        //fmt.Printf("m[%d] = %d\n", req, f)
        if ok {
            res+=f
        }
    }
    return res
}


/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */
