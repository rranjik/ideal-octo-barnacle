(* Enter your code here. Read input from STDIN. Print output to STDOUT *)
let test_cases = read_int () in
let do_test_case = 
let n = read_int () in 
let rec read_nodes n arr = 
    if (n == 0) then arr else (let i = Scanf.scanf "%d " (fun i -> i) in read_nodes (n-1) (arr @ [i]))
    in
    let nds = read_nodes n [] in
    let rec valid_bst nodes root stk = 
        match nodes with 
        | [] -> (print_string "YES"; print_newline ();)
        | hd::tl -> if (hd < root) then (print_string "NO"; print_newline ();) else (let rec fit stk e rt = 
            match stk with 
            |[] -> ((*print_string "stack empty appending"; print_newline (); *)
            (rt, ([hd] @ stk)))
            |shd::stl -> (if (shd<hd) then ((*print_string "stack not empty still fitting"; print_newline (); *)
            fit stl hd shd) else ((*print_string "stack not empty recursing"; print_newline ();*)
            (rt, ([hd] @ stk))))
            in valid_bst tl (fst (fit stk hd root)) (snd (fit stk hd root)))
        in valid_bst nds 0 []
        in
        let rec validate tc = (if (tc > 0) then (print_string "tc: "; print_int tc; print_string " calling do_test_case"; print_newline (); do_test_case; validate (tc-1)) else ())
         in validate test_cases
