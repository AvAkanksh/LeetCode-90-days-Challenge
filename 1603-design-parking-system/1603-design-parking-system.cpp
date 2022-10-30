class ParkingSystem {
    int size[3];
public:
    ParkingSystem(int big, int medium, int small) {
        size[0] = big;
        size[1] = medium;
        size[2] = small;
    }
    
    bool addCar(int carType) {
        if(size[carType-1]>0){
            size[carType-1]--;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */