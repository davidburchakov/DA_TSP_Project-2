#include <iostream>
#include "CPheadquarters.h"

using namespace std;

int main() {
    CPheadquarters CP;
    string path;
    cout<<"Insert path to file to consrtuct graph (../network.csv): ";
    getline(cin, path);
    CP.read_network(path);
    cout<<"Insert path to file regarding stations (../stations.csv): ";
    getline(cin, path);
    cout<<endl;
    CP.read_stations(path);
    CP.getGraph().print();
    int n;
    cout << "\n-------------- An Analysis Tool for Railway Network Management --------------\n" << endl;
    do {
        cout << "1 - T2.1 Backtracking Algorithm\n";
        cout << "2 - T2.2 Triangular Approximation Heuristic\n";
        cout << "3 - T2.3 other heuristic algorithms\n";
        cout << "8 - Exit\n";


        bool validInput = false;

        while (!validInput) {
            cout << "Insert your option:\n";
            cin >> n;

            if (cin.fail() || n < 1 || n > 8) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            } else {
                validInput = true;
            }
        }

        switch (n) {
            case 1: {
                cin.ignore(); // ignore newline character left in the input stream
                string a, b;

                cout << "Enter station A: ";
                getline(cin, a);

                cout << "Enter station B: ";
                getline(cin, b);

                if (a.empty() || b.empty()) {
                    cerr << "Error: Station names cannot be empty." << endl;
                    break;
                }

                // ... your code here ...
                break;
            }

            case 2: {

                CP.print3();
            }

            case 3: {
                cin.ignore();

                break;
            }

            case 8: {
                cout << "Exiting program..." << endl;
                break;
            }

            default: {
                cerr << "Error: Invalid option selected." << endl;
                break;
            }
        }
    } while (n != 8);

    return 0;
}