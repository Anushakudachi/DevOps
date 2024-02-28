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

    virtual void heatWater(int requiredTemperature) = 0;
};

class BathroomGeyser : public WaterHeater {
private:
    EnvironmentSensor environmentSensor;

public:
    void activateGeyser() {
        string season = environmentSensor.detectSeason();
        cout << "Geyser activated for " << season << " season." << endl;
    }


    int getCurrentTemperature() const {
        return environmentSensor.getTemperature();
    }

    int calculateRequiredTemperature() const {
        return 40;
    }


    void heatWater(int requiredTemperature) override {
        cout << "Water is being heated to " << requiredTemperature << " degrees." << endl;
    }
};

class HeatingSystem {
public:

    int calculateRequiredTemperature(int currentTemperature) {
        return currentTemperature + 10;
    }
};

class SmartHomeSystem {
public:
    void calculateHeatingTemperature(BathroomGeyser& geyser, HeatingSystem& heatingSystem) {
        geyser.activateGeyser();
        int currentTemperature = geyser.getCurrentTemperature();
        int requiredTemperature = heatingSystem.calculateRequiredTemperature(currentTemperature);
        geyser.heatWater(requiredTemperature);
    }
};

class HomeOwner {
public:
    void getOutOfBed() {
        cout << "Homeowner is getting out of bed." << endl;
    }
};

int main() {
    BathroomGeyser bathroomGeyser;
    HeatingSystem heatingSystem;
    SmartHomeSystem smartHomeSystem;

    HomeOwner homeowner;
    homeowner.getOutOfBed();

    smartHomeSystem.calculateHeatingTemperature(bathroomGeyser, heatingSystem);

    return 0;
}
