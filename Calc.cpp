
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ScientificCalculator {
private:
    const double PI = acos(-1.0);
    const double E = exp(1.0);

public:
    void displayMenu() {
        cout << "\n========================================\n";
        cout << "       ADVANCED SCIENTIFIC CALCULATOR\n";
        cout << "========================================\n";
        cout << " 1. Addition (+)\n";
        cout << " 2. Subtraction (-)\n";
        cout << " 3. Multiplication (*)\n";
        cout << " 4. Division (/)\n";
        cout << " 5. Power (x^y)\n";
        cout << " 6. Square Root\n";
        cout << " 7. Cube Root\n";
        cout << " 8. Factorial\n";
        cout << " 9. Sine (sin)\n";
        cout << "10. Cosine (cos)\n";
        cout << "11. Tangent (tan)\n";
        cout << "12. Logarithm (log10)\n";
        cout << "13. Natural Log (ln)\n";
        cout << "14. Percentage\n";
        cout << "15. Modulus\n";
        cout << "16. Absolute Value\n";
        cout << "17. Exponential (e^x)\n";
        cout << "18. Minimum & Maximum\n";
        cout << "19. Display Constants\n";
        cout << " 0. Exit Calculator\n";
        cout << "========================================\n";
    }

    double getNumber(string message) {
        double num;
        while (true) {
            cout << message;
            if (cin >> num && isfinite(num))
                return num;

            cout << "Invalid input! Enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    long long factorial(int n) {
        long long result = 1;

        for (int i = 1; i <= n; i++)
            result *= i;

        return result;
    }

    void calculate(int choice) {
        double a, b, result;

        switch (choice) {

        case 1:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            result = a + b;
            break;

        case 2:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            result = a - b;
            break;

        case 3:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            result = a * b;
            break;

        case 4:
            a = getNumber("Enter numerator: ");
            b = getNumber("Enter denominator: ");
            if (b == 0) {
                cout << "Error: Division by zero!\n";
                return;
            }
            result = a / b;
            break;

        case 5:
            a = getNumber("Enter base: ");
            b = getNumber("Enter exponent: ");
            result = pow(a, b);
            break;

        case 6:
            a = getNumber("Enter number: ");
            if (a < 0) {
                cout << "Error: Negative square root!\n";
                return;
            }
            result = sqrt(a);
            break;

        case 7:
            a = getNumber("Enter number: ");
            result = cbrt(a);
            break;

        case 8: {
            int n;
            cout << "Enter integer (0-20): ";
            cin >> n;

            if (cin.fail()) {
                cout << "Invalid input!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }

            if (n < 0 || n > 20) {
                cout << "Enter a number between 0 and 20.\n";
                return;
            }

            cout << n << "! = " << factorial(n) << "\n";
            return;
        }

        case 9:
            a = getNumber("Enter angle in degrees: ");
            result = sin(a * PI / 180);
            break;

        case 10:
            a = getNumber("Enter angle in degrees: ");
            result = cos(a * PI / 180);
            break;

        case 11:
            a = getNumber("Enter angle in degrees: ");
            if (abs(cos(a * PI / 180)) < 1e-12) {
                cout << "Error: Tangent is undefined.\n";
                return;
            }
            result = tan(a * PI / 180);
            break;

        case 12:
            a = getNumber("Enter number: ");
            if (a <= 0) {
                cout << "Error: Log requires positive input.\n";
                return;
            }
            result = log10(a);
            break;

        case 13:
            a = getNumber("Enter number: ");
            if (a <= 0) {
                cout << "Error: Log requires positive input.\n";
                return;
            }
            result = log(a);
            break;

        case 14:
            a = getNumber("Enter total: ");
            b = getNumber("Enter percentage: ");
            result = (a * b) / 100;
            break;

        case 15:
            a = getNumber("Enter first integer: ");
            b = getNumber("Enter second integer: ");

            if (floor(a) != a || floor(b) != b ||
                abs(a) > 9007199254740991.0 ||
                abs(b) > 9007199254740991.0) {
                cout << "Error: Enter safe integers only.\n";
                return;
            }

            if (b == 0) {
                cout << "Error: Modulus by zero!\n";
                return;
            }

            result = fmod(a, b);
            break;

        case 16:
            a = getNumber("Enter number: ");
            result = fabs(a);
            break;

        case 17:
            a = getNumber("Enter exponent: ");
            result = exp(a);
            break;

        case 18:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            cout << "Minimum: " << min(a, b) << "\n";
            cout << "Maximum: " << max(a, b) << "\n";
            return;

        case 19:
            cout << "PI = " << PI << "\n";
            cout << "E  = " << E << "\n";
            return;

        default:
            cout << "Invalid operation!\n";
            return;
        }

        if (!isfinite(result)) {
            cout << "Error: Result is outside the supported range.\n";
            return;
        }

        cout << fixed << setprecision(8);
        cout << "\n----------------------------------------\n";
        cout << "             RESULT: " << result << "\n";
        cout << "----------------------------------------\n";
    }
};

int main() {
    ScientificCalculator calc;
    int choice;

    cout << "\nWELCOME TO THE ADVANCED CALCULATOR!\n";

    while (true) {
        calc.displayMenu();

        cout << "Select operation: ";

        if (!(cin >> choice)) {
            cout << "Invalid menu input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0) {
            cout << "\nThank you for using the calculator!\n";
            break;
        }

        calc.calculate(choice);
    }

    return 0;
}
