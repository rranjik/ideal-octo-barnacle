class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int c) {
        switch(c){
            case 1: 
                if(b){
                    b--;
                    return true;
                }else return false;
                case 2: 
                if(m){
                    m--;
                    return true;
                }else return false;
                case 3: 
                if(s){
                    s--;
                    return true;
                }else return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
