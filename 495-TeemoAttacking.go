func findPoisonedDuration(t []int, d int) int {
    res := d
    le := t[0]+d-1
    //fmt.Printf("le = %d; res = %d\n", le, res)
    for i := 1; i<len(t); i++{
        v:=t[i]
        if le>=v{
            ole := le
            le = v+d-1;
            res += le-ole
            //fmt.Printf("ole = %d; le = %d; res = %d\n", ole, le, res)
        }else{
            le = v+d-1
            res += d
        }
        //fmt.Printf("poison end at %ds\n", le)
    }
    return res
}
