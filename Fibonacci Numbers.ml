(* Enter your code here. Read input from STDIN. Print output to STDOUT *)
let n = read_int () in 
let fib input=
    (*base cases*)
    if (input == 0) then (print_int 0) else (if (input==1) then (print_int 1) else (
    let n1 = ref 0 in (*initial value*)
    let n2 = ref 1 in (*initial value*)
    let answer = ref 0 in (*let the answer be 0 initially*)
    let count = ref 2 in
    while (!count < input) do (*until count equals input*)
        answer := !n1 + !n2; (*compute next fibnonacci number*)
        n1 := !n2; (*update old values*)
        n2 := !answer;
        count := !count + 1; (*increment count*)
    done;
    print_int (!answer); (*return the answer*)
    ))
in 
fib n

