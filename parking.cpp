#include <iostream>
using namespace std;

class ParkingLot {
private:
    int twoWheelerCount;
    int fourWheelerCount;
    int maxTwoWheelers;
    int maxFourWheelers;
    int totalEarnings;

    const int twoWheelerFee = 20;
    const int fourWheelerFee = 50;

public:
    ParkingLot(int max2W, int max4W) {
        twoWheelerCount = 0;
        fourWheelerCount = 0;
        totalEarnings = 0;
        maxTwoWheelers = max2W;
        maxFourWheelers = max4W;
    }

    void parkVehicle(int type) {
        if (type == 2) {
            if (twoWheelerCount < maxTwoWheelers) {
                twoWheelerCount++;
                totalEarnings += twoWheelerFee;
                cout << "2-wheeler parked. Fee: Rs " << twoWheelerFee << endl;
            } else {
                cout << "No space for 2-wheelers!" << endl;
            }
        } else if (type == 4) {
            if (fourWheelerCount < maxFourWheelers) {
                fourWheelerCount++;
                totalEarnings += fourWheelerFee;
                cout << "4-wheeler parked. Fee: Rs " << fourWheelerFee << endl;
            } else {
                cout << "No space for 4-wheelers!" << endl;
            }
        } else {
            cout << "Invalid vehicle type!" << endl;
        }
    }

    void removeVehicle(int type) {
        if (type == 2) {
            if (twoWheelerCount > 0) {
                twoWheelerCount--;
                cout << "2-wheeler removed." << endl;
            } else {
                cout << "No 2-wheelers to remove!" << endl;
            }
        } else if (type == 4) {
            if (fourWheelerCount > 0) {
                fourWheelerCount--;
                cout << "4-wheeler removed." << endl;
            } else {
                cout << "No 4-wheelers to remove!" << endl;
            }
        } else {
            cout << "Invalid vehicle type!" << endl;
        }
    }

    void showStatus() {
        cout << "---- Parking Status ----" << endl;
        cout << "2-Wheelers Parked: " << twoWheelerCount << "/" << maxTwoWheelers << endl;
        cout << "4-Wheelers Parked: " << fourWheelerCount << "/" << maxFourWheelers << endl;
        cout << "Total Earnings: Rs " << totalEarnings << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    ParkingLot lot(10, 5); // 10 two-wheeler and 5 four-wheeler slots

    int choice, type;

    while (true) {
        cout << "\n--- Parking Management Menu ---" << endl;
        cout << "1. Park Vehicle" << endl;
        cout << "2. Remove Vehicle" << endl;
        cout << "3. Show Status" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter vehicle type (2 for Two-wheeler, 4 for Four-wheeler): ";
            cin >> type;
            lot.parkVehicle(type);
            break;
        case 2:
            cout << "Enter vehicle type to remove (2 or 4): ";
            cin >> type;
            lot.removeVehicle(type);
            break;
        case 3:
            lot.showStatus();
            break;
        case 4:
            cout << "Exiting... Thanks for using the Parking System." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    }
}