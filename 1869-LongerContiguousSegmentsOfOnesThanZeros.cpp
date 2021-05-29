func checkZeroOnes(s string) bool {
    zerolen := 0
    onelen := 0
    var l rune
    lastcount := 0
    for _, c:= range s {
        if c==l{
            lastcount++
        }else {
            if l=='0'{
                if zerolen<lastcount {
                    zerolen = lastcount 
                }
            }else{
                if onelen<lastcount {
                    onelen = lastcount
                }
            }
            lastcount = 1;
            l = c;
        }
    }
    if l=='0'{
        if zerolen<lastcount {
            zerolen = lastcount 
        }
    }else{
        if onelen<lastcount {
            onelen = lastcount
        }
    }
    if onelen>zerolen {
        return true
    }else {
        return false;
    }
}
