#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

// NOTE: This might be too big and will take
//  too long before the buffer is cleared
// I suggest using a smaller number
const auto IGNORE_SIZE = numeric_limits<streamsize>::max();

int main() {
    // Marital Status
    char maritalStatus;

    cout << "Enter marital status (S-single/M-married): ";
    cin >> maritalStatus;

    // Invalid Input Exception Handler
    if (cin.fail()) {

        cin.clear();
        cin.ignore(::IGNORE_SIZE, -1);

        return 1;
    }

    char status = tolower(maritalStatus);
    float taxRate = 0, salaryTax = 0;

    if (status == 's' || status == 'm') {

        // Monthly Salary
        float monthlySalary = 0;

        cout << "Enter monthly salary (non-negative): ";
        cin >> monthlySalary;

        // Invalid Input Exception Handler
        if (cin.fail() || monthlySalary < 0) {

            cout << "Error: The salary must be non-negative only!";

            cin.clear();
            cin.ignore(::IGNORE_SIZE, -1);

            return 1;
        }

        // Conditional Operator-Based Tax Rate Definition

        // As stated in the problem, the only difference in tax
        // of a 'Single' person to a 'Married' person is 5%.
        // Therefore, we can simply subtract 5% from the tax if
        // the person is not single

        taxRate = (monthlySalary < 50'000 ? 0.10 : monthlySalary > 100'000 ? 0.30 : 0.20) - (status == 's' ? 0.0 : 0.05);
        salaryTax = monthlySalary * taxRate;

        cout << fixed << setprecision(2) << "\n";

        cout << "Employee Monthly Salary: " << monthlySalary << endl;
        cout << "Marital Status: " << (status == 's' ? "Single" : "Married") << endl;
        cout << "Tax Rate: " << (taxRate * 100.0) << "%" << endl;
        cout << "Salary Tax: " << salaryTax << endl;

    } else {
        cout << "Error: Invalid marital status.\nUse 'Single' or 'Married' only!\n";
        return 1;
    }
}