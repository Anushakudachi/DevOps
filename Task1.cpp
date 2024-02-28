#include <iostream>
using namespace std;
class EnvironmentSensor {
private:
    int temperature;

public:
    int getTemperature() const {
        return temperature;
    }

    void setTemperature(int temp) {
        temperature = temp;
    }
    string detectSeason() const {
        if (temperature >= 25) {
            return "Summer";
        } else if (temperature >= 10) {
            return "Spring";
        } else {
            return "Winter";
        }
    }
};

class WaterHeater {
public:
    void heatWater() {
        cout << "Water is being heated." << endl;
    }
};

class SmartGeyser : public WaterHeater {
private:
    EnvironmentSensor environmentSensor;

public:
    void activateGeyser() {
        string season = environmentSensor.detectSeason();
        cout << "Geyser activated for " << season << " season." << endl;
        heatWater();
    }
};

class SmartBed {
public:
    bool isHomeownerOutOfBed() const {
        return true;  // For the sake of example, assuming the homeowner is always out of bed
    }
};

class HomeOwner {
private:
    SmartBed smartBed;
    SmartGeyser smartGeyser;

public:
    void getOutOfBed() {
        cout << "Homeowner is getting out of bed." << endl;
    }

    void activateGeyser() {
        if (smartBed.isHomeownerOutOfBed()) {
            smartGeyser.activateGeyser();
        }
    }
};

int main() {
    HomeOwner homeowner;
    homeowner.getOutOfBed();
    homeowner.activateGeyser();
    return 0;
}
