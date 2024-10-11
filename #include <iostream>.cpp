#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double* prices;
public:
    // Default constructor
    Chair() {
        prices = new double[SIZE];
        // Randomly selecting 3 or 4 legs
        legs = (rand() % 2) + 3;  // 3 or 4
        // Randomly selecting prices between $100.00 and $999.99
        for (int i = 0; i < SIZE; i++) {
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
    }

    // Parameter constructor
    Chair(int l, double p[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

    // Setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));  // Initialize random seed
    cout << fixed << setprecision(2);

    // Create a default Chair object
    Chair* chairPtr = new Chair();
    chairPtr->print();

    // Creating dynamic Chair object with the new parameter constructor
    double prices[] = { 525.25, 434.34, 252.52 };
    Chair* livingChair = new Chair(3, prices);
    livingChair->print();

    delete livingChair;
    livingChair = nullptr;

    // Creating dynamic array of Chair objects using the default constructor
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }

    return 0;
}
