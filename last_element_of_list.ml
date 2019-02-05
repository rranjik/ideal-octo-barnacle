type 'a option =
  | None
  | Some of 'a

let last arr =
 let last_elem ar = function
  |hd::tl -> Some hd
  |[] -> None
 in last_elem (List.rev arr)

 ((λx.(x y))(λz.z))

