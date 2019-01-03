let number_of_inputs = read_int () in

let rec read ni = 
    if (ni > 0) then 
    ((let x = read_float () in 
    print_float (let e_power_x expon = 
    if (expon == 0.0) then 1.0 else (
        let rec sum expon n acc = 
            if (n==0) then (1.0 +. acc) else (sum expon (n-1) (acc +. ((expon**(float_of_int n)) /. (let rec fact n acc = 
                if (n == 0 || n == 1) then (float_of_int acc) else fact (n-1) (acc*n) 
                in 
                fact n 1 )
                ))) 
        in 
        sum expon 9 0.0
    )
    in
    e_power_x x)); print_newline (); read (ni-1))
    else
    ()
    in
    read number_of_inputs

