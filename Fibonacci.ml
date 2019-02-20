(* Enter your code here. Read input from STDIN. Print output to STDOUT *)

let modulo = ref (int_of_float ((10.**8.) +. 7.)) in 
let test_cases = read_int () in
let rec read_all_inputs tc arr = 
    if(tc > 0) then 
    (let n = read_int () in read_all_inputs (tc-1) (arr@[n]))
    else arr 
in 
let fib input=
    (*base cases*)
    (*print_string "modulo is: "; print_int (!modulo); print_newline();
    print_string "input is: "; print_int input; print_newline();*)
    if (input == 0) then (print_int 0; print_newline ();) else (if (input==1) then (print_int 1; print_newline ();) else (
    let n1 = ref (0 mod !modulo) in (*initial value*)
    let n2 = ref (1 mod !modulo) in (*initial value*)
    let answer = ref (2 mod !modulo) in (*let the answer be 0 initially*)
    let count = ref 2 in
    while (!count <= input) do (*until count equals input*)
        answer := ((!n1 + !n2) mod !modulo); (*compute next fibnonacci number*)
        n1 := (!n2) mod !modulo; (*update old values*)
        n2 := (!answer) mod !modulo;
        count := !count + 1; (*increment count*)
    done;
    print_int (!answer); (*return the answer*)
    print_newline ();
    ))
in 
let rec do_all_test_cases arr = 
    match arr with 
    | hd::tl -> fib hd; do_all_test_cases tl 
    | [] -> ()
    in 
do_all_test_cases (read_all_inputs test_cases [])