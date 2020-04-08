#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle{
    public:
        Vehicle();
        ~Vehicle();
        int getFuelAmount();
        int getCapacity();

        void applyGas(); // method that increases acceleration value in 1 unit
        void applyBreaks(); // method that decreases the acceleration value in 1 unit

        void setPassengers(int x);

    protected:
        int fuel;
        int nPassengers;
        int acceleration;
};

#endif // VEHICLE_H