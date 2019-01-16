(* Enter your code here. Read input from STDIN. Print output to STDOUT *)
let except_first_char s = 
  try 
  (String.sub s 1 ((String.length s)-1)) 
  with (Invalid_argument "this cannot happen") -> "" 
  in  

let rec print_char_list arr = 
  match arr with 
  | [] -> ()
  | hd::tl -> print_char hd; print_char_list tl 
  in 

let input_string = read_line () in
let rec exclude_duplicates s arr = 
  if(String.length s == 0) 
  then arr
  else (if(List.mem s.[0] arr)
        then (exclude_duplicates (except_first_char s) arr)
        else (exclude_duplicates (except_first_char s) (arr@[s.[0]])))
in print_char_list (exclude_duplicates input_string [])
