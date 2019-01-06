(* Enter your code here. Read input from STDIN. Print output to STDOUT *)
let (n,k) = Scanf.scanf "%s %d" (fun n k -> (n, k)) in 
let explode s =
  let rec exp i l =
    if i < 0 then l else exp (i - 1) (s.[i] :: l) in
  exp (String.length s - 1) [] in
let rec get_sum_of_digits number acc = 
    match number with
    | [] -> acc
    | hd::tl -> get_sum_of_digits tl ((acc + ((Char.code hd) - (Char.code '0'))) mod 9) in
let get_super_digit ni ki = ((ki * (get_sum_of_digits (explode ni) 0)) mod 9) in
let res = if ((get_super_digit n k) == 0) then 9 else (get_super_digit n k) in 
print_int res


 
