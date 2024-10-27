#include "OpenScatterTable.h"
#include <string>

bool AddBigInt(OpenScatterTable& table, const string& number, int numNumbers, int noDigits) {
    if (number.length() != noDigits) {
        cout << "Error: Number must have " << noDigits << " digits." << endl;
        return false;
    }

    for (char c : number) {
        if (c < '0' || c > '9') {
            cout << "Error: Invalid digit found." << endl;
            return false;
        }
    }

    ScatterObject newNumber(number.c_str());
    return table.insert(newNumber);
}
