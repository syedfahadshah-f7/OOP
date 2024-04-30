#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Drone {
protected:
    float latitude, longitude, altitude, speed;
public:
    Drone(float lat, float lon, float alt, float spd) : latitude(lat), longitude(lon), altitude(alt), speed(spd) {}

    void adjustAltitude(float meter) {
        this->altitude = meter;
    }

    void setSpeed(float spd) {
        this->speed = spd;
    }
};

class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigate(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
    float cameraResolution, maxFlightTime;
public:
    ReconDrone(float lat, float lon, float alt, float spd, float camRes, float maxTime)
        : Drone(lat, lon, alt, spd), cameraResolution(camRes), maxFlightTime(maxTime) {}

    void takeoff() override {
        cout << "Taking off" << endl;
    }

    void land() override {
        cout << "Landing" << endl;
    }

    void navigate(float lat, float lon, float alt) override {
        // Handle potential GPS signal loss or communication errors here
        try {
            float x = (lat - longitude) * cos((latitude + lat) / 2);
            float y = lat - latitude;
            float distance = sqrt(x * x + y * y) * 111.0f;
            float time = distance / speed;

            cout << "Estimated time to destination: " << time << " hours" << endl;

            latitude = lat;
            longitude = lon;
            altitude = alt;
        } catch (const exception& e) {
            cerr << "Error during navigation: " << e.what() << endl;
            // Handle the error accordingly, maybe retry or abort mission
        }
    }

    void scanArea(float radius) override {
        // Handle potential communication errors with scanning equipment
        try {
            // Simulate scanning the environment
            int objectsDetected = rand() % 10; // Random number of objects detected
            cout << "Detected " << objectsDetected << " objects:" << endl;

            for (int i = 0; i < objectsDetected; ++i) {
                float objectLat = latitude + static_cast<float>(rand() % 100) / 1000.0f;
                float objectLon = longitude + static_cast<float>(rand() % 100) / 1000.0f;
                cout << "Object " << i + 1 << " at (" << objectLat << ", " << objectLon << ")" << endl;
            }
        } catch (const exception& e) {
            cerr << "Error during scanning: " << e.what() << endl;
            // Handle the error accordingly, maybe retry or skip scanning
        }
    }
};

int main() {
    ReconDrone drone(0, 0, 100, 50, 4, 8);
    drone.takeoff();
    drone.navigate(1, 1, 150);
    drone.scanArea(500);
    drone.land();
    return 0;
}
