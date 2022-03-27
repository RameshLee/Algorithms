// Link: https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
    int B,M,S;
    ParkingSystem(int big, int medium, int small) {
        B = big; M = medium; S=small;
    }

    bool addCar(int carType) {

        switch(carType){
            case 1: B--; if (B<0) return false; break;
            case 2: M--; if (M<0) return false; break;
            case 3: S--; if (S<0) return false; break;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */