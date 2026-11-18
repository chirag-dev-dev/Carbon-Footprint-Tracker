#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. Abstract base class (demonstrates abstraction & polymorphism)
class CarbonFootprint {
public:
    // Pure virtual function: forces derived classes to implement calculation logic
    virtual double getCarbonFootprint() const = 0; 
    virtual string getName() const = 0;
    virtual ~CarbonFootprint() {} // Virtual destructor, good practice
};

// 2. Derived class: Building (demonstrates inheritance & encapsulation)
class Building : public CarbonFootprint {
private:
    double area; // square meters
    double energyIntensity; // energy consumption per square meter
public:
    Building(double a, double ei) : area(a), energyIntensity(ei) {}
    double getCarbonFootprint() const override {
        // Simplified algorithm: area * intensity * emission factor
        return area * energyIntensity * 0.5; 
    }
    string getName() const override { return "Building"; }
};

// 3. Derived class: Car (demonstrates inheritance)
class Car : public CarbonFootprint {
private:
    double fuelConsumed; // liters
public:
    Car(double fuel) : fuelConsumed(fuel) {}
    double getCarbonFootprint() const override {
        // About 2.3 kg CO2 per liter of gasoline
        return fuelConsumed * 2.3; 
    }
    string getName() const override { return "Car"; }
};

// 4. Derived class: Bicycle (zero emissions, demonstrates that different classes can have vastly different behaviors)
class Bicycle : public CarbonFootprint {
public:
    double getCarbonFootprint() const override { return 0.0; }
    string getName() const override { return "Bicycle"; }
};

int main() {
    vector<CarbonFootprint*> tracker;
    
    // Instantiate different objects (users can input or hardcode)
    tracker.push_back(new Building(100, 50)); // 100 square meters, high energy consumption
    tracker.push_back(new Car(40));           // consumed 40 liters of gasoline
    tracker.push_back(new Bicycle());

    cout << "=== Sustainable Development Carbon Footprint Report ===" << endl;
    for (const auto& item : tracker) {
        cout << item->getName() << " emits: " 
             << item->getCarbonFootprint() << " kg CO2" << endl;
    }

    // Free memory
    for (auto& item : tracker) delete item;
    
    return 0;
}
