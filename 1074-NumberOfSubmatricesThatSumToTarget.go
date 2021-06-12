func numSubmatrixSumTarget(matrix [][]int, target int) int {
    m := len(matrix)
    n:=len(matrix[0])
    //fmt.Printf("m = %d; n = %d\n", m, n)
    for i := range matrix {
        for j := range matrix[i] {
            if j > 0 {
                matrix[i][j] += matrix[i][j-1]
            }
        }
    }  
    //fmt.Printf("%v\n", matrix)
    
    /*
        i    j
    *************
    *************
    *************
    *************
    *************
    cnt is 'made' for every pair of i and j
    subarr is the sum of elements in the kth
    row from col i through j
        i    j
    *************
    *************
   k****++++++*** = subarr
    *************
    *************
    adds to earlier subarrs
        i    j
    ****++++++***
    ****++++++***
   k****++++++*** = curr
    *************
    *************
    we want to find any x that was seen previously
    such that c-x = t; i,e x = c-t
        i    j
    ****xxxxxx***
    ****tttttt***
   k****tttttt*** 
    *************
    *************
    please note that this can form any sub matrix within
    the entire matrix as we consider every pair of 
    columns
    */
    res := 0
    for j := 0; j<n; j++ {
        for i:=j; i>=0; i--{
            cnt := make(map[int]int)
            cnt[0] = 1       
            cur := 0
            for k:= 0; k<m; k++{
                pre := 0
                if i-1 >= 0 {
                    pre = matrix[k][i-1]
                }
                subarr := (matrix[k][j] - pre)
                //fmt.Printf("i = %d; j = %d; subarr = %d\n", i, j, subarr)
                cur += subarr
                //fmt.Printf("cur = %d\n", cur)
                if _,ok := cnt[cur-target]; ok{
                    res+=cnt[cur-target]
                }
                cnt[cur]++
            }
        }
    }
    return res
}
