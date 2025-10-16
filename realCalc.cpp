#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Constants
const double PI = 3.14159265358979323846;

// Function prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double modulo(double a, double b);
double square(double x);
double squareRoot(double x);
double power(double base, double exponent);
void displayCurrentDate();
int calculateAge(int birthYear);
double sine(double x);
double cosine(double x);
double tangent(double x);
double logarithm(double x);
double factorial(int n);
vector<double> quadraticEquation(double a, double b, double c);
double standardDeviation(const vector<double>& data);
void statisticsCalculator();
void matrixOperations();
void scientificCalculator();
void conversionCalculator();
void printMatrix(const vector<vector<double>>& matrix);
void printHistory(const vector<string>& history);

int main() {
    vector<string> calculationHistory;
    int choice;
    double num1, num2, result;
    bool running = true;

    cout << "=== ADVANCED MATHEMATICAL CALCULATOR ===" << endl;
    cout << "Created with C++" << endl << endl;

    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: // Addition
                    cout << "Enter two numbers: ";
                    cin >> num1;
                    cin.ignore();
					cin >> num2;
                    cin.ignore();
                    result = add(num1, num2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + " + " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 2: // Subtraction
                    cout << "Enter two numbers: ";
                    cin >> num1;
                    cin.ignore();
					cin >> num2;
                    cin.ignore(); 
                    result = subtract(num1, num2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + " - " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 3: // Multiplication
                    cout << "Enter two numbers: ";
                    cin >> num1;
                    cin.ignore();
					cin >> num2;
		            cin.ignore();
                    result = multiply(num1, num2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + " * " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 4: // Division
                    cout << "Enter two numbers: ";
                    cin >> num1;
                    cin.ignore();
					cin >> num2;
		            cin.ignore();
                    if (num2 == 0) throw runtime_error("Error: Division by zero!");
                    result = divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + " / " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 5: // Modulo
                    cout << "Enter two numbers: ";
                    cin >> num1;
                    cin.ignore();
					cin >> num2;
  		            cin.ignore();
                    if (num2 == 0) throw runtime_error("Error: Division by zero in modulo!");
                    result = modulo(num1, num2);
                    cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + " % " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 6: // Square
                    cout << "Enter a number: ";
                    cin >> num1;
                    cin.ignore();
                    result = square(num1);
                    cout << "Result: " << num1 << "² = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + "² = " + to_string(result));
                    break;
                
                case 7: // Square Root
                    cout << "Enter a number: ";
                    cin >> num1;
                    if (num1 < 0) throw runtime_error("Error: Square root of negative number!");
                    result = squareRoot(num1);
                    cout << "Result: √" << num1 << " = " << result << endl;
                    calculationHistory.push_back("√" + to_string(num1) + " = " + to_string(result));
                    break;
                
                case 8: // Power
                    cout << "Enter base and exponent: ";
                    cin >> num1 >> num2;
                    result = power(num1, num2);
                    cout << "Result: " << num1 << "^" << num2 << " = " << result << endl;
                    calculationHistory.push_back(to_string(num1) + "^" + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 9: // Current Date
                    displayCurrentDate();
                    break;
                
                case 10: // Age Calculator
                    int birthYear;
                    cout << "Enter your birth year: ";
                    cin >> birthYear;
                    cout << "Your age is: " << calculateAge(birthYear) << " years" << endl;
                    calculationHistory.push_back("Age calculation for birth year " + to_string(birthYear));
                    break;
                
                case 11: // Trigonometry
                    scientificCalculator();
                    break;
                
                case 12: // Quadratic Equation
                    double a, b, c;
                    cout << "Enter coefficients a, b, c: ";
                    cin >> a >> b >> c;
                    {
                        vector<double> roots = quadraticEquation(a, b, c);
                        if (roots.empty()) {
                            cout << "No real roots" << endl;
                            calculationHistory.push_back("Quadratic equation " + to_string(a) + "x² + " + 
                                                      to_string(b) + "x + " + to_string(c) + " has no real roots");
                        } else if (roots.size() == 1) {
                            cout << "Double root: x = " << roots[0] << endl;
                            calculationHistory.push_back("Quadratic equation " + to_string(a) + "x² + " + 
                                                      to_string(b) + "x + " + to_string(c) + " has double root x = " + 
                                                      to_string(roots[0]));
                        } else {
                            cout << "Roots: x1 = " << roots[0] << ", x2 = " << roots[1] << endl;
                            calculationHistory.push_back("Quadratic equation " + to_string(a) + "x² + " + 
                                                      to_string(b) + "x + " + to_string(c) + " has roots x1 = " + 
                                                      to_string(roots[0]) + ", x2 = " + to_string(roots[1]));
                        }
                    }
                    break;
                
                case 13: // Statistics
                    statisticsCalculator();
                    break;
                
                case 14: // Matrix Operations
                    matrixOperations();
                    break;
                
                case 15: // Unit Conversions
                    conversionCalculator();
                    break;
                
                case 16: // View History
                    printHistory(calculationHistory);
                    break;
                
                case 0: // Exit
                    running = false;
                    cout << "Exiting calculator. Goodbye!" << endl;
                    break;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << endl;
    }

    return 0;
}

void displayMenu() {
    cout << "===== MAIN MENU =====" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulo" << endl;
    cout << "6. Square" << endl;
    cout << "7. Square Root" << endl;
    cout << "8. Power" << endl;
    cout << "9. Current Date" << endl;
    cout << "10. Age Calculator" << endl;
    cout << "11. Scientific Calculator (Trigonometry, Logs, etc.)" << endl;
    cout << "12. Quadratic Equation Solver" << endl;
    cout << "13. Statistics Calculator" << endl;
    cout << "14. Matrix Operations" << endl;
    cout << "15. Unit Conversions" << endl;
    cout << "16. View Calculation History" << endl;
    cout << "0. Exit" << endl;
}

// Basic arithmetic operations
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
double modulo(double a, double b) { return fmod(a, b); }
double square(double x) { return x * x; }
double squareRoot(double x) { return sqrt(x); }
double power(double base, double exponent) { return pow(base, exponent); }

// Date and time functions
void displayCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    cout << "Current date: " 
         << 1900 + localTime->tm_year << "-"
         << 1 + localTime->tm_mon << "-"
         << localTime->tm_mday << endl;
}

int calculateAge(int birthYear) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    int currentYear = 1900 + localTime->tm_year;
    return currentYear - birthYear;
}

// Trigonometric functions (accept degrees)
double sine(double x) { return sin(x * PI / 180.0); }
double cosine(double x) { return cos(x * PI / 180.0); }
double tangent(double x) { return tan(x * PI / 180.0); }

// Logarithmic function
double logarithm(double x) { 
    if (x <= 0) throw runtime_error("Error: Logarithm of non-positive number!");
    return log10(x); 
}

// Factorial function
double factorial(int n) {
    if (n < 0) throw runtime_error("Error: Factorial of negative number!");
    if (n == 0 || n == 1) return 1;
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Quadratic equation solver
vector<double> quadraticEquation(double a, double b, double c) {
    vector<double> roots;
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        roots.push_back((-b + sqrt(discriminant)) / (2 * a));
        roots.push_back((-b - sqrt(discriminant)) / (2 * a));
    } else if (discriminant == 0) {
        roots.push_back(-b / (2 * a));
    }
    
    return roots;
}

// Statistics functions
double standardDeviation(const vector<double>& data) {
    if (data.empty()) return 0;
    
    double sum = 0;
    for (double num : data) {
        sum += num;
    }
    double mean = sum / data.size();
    
    double variance = 0;
    for (double num : data) {
        variance += pow(num - mean, 2);
    }
    variance /= data.size();
    
    return sqrt(variance);
}

void statisticsCalculator() {
    vector<double> data;
    double num;
    char choice;
    
    cout << "=== STATISTICS CALCULATOR ===" << endl;
    cout << "Enter data points (enter 'd' when done):" << endl;
    
    while (true) {
        cout << "Enter number: ";
        if (!(cin >> num)) {
            cin.clear();
            cin >> choice;
            if (choice == 'd' || choice == 'D') break;
            else {
                cout << "Invalid input. Try again." << endl;
                continue;
            }
        }
        data.push_back(num);
    }
    
    if (data.empty()) {
        cout << "No data entered." << endl;
        return;
    }
    
    // Calculate statistics
    double sum = 0, minVal = data[0], maxVal = data[0];
    for (double num : data) {
        sum += num;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }
    double mean = sum / data.size();
    double median = 0;
    
    // Calculate median
    vector<double> sortedData = data;
    sort(sortedData.begin(), sortedData.end());
    if (sortedData.size() % 2 == 1) {
        median = sortedData[sortedData.size() / 2];
    } else {
        median = (sortedData[sortedData.size() / 2 - 1] + sortedData[sortedData.size() / 2]) / 2;
    }
    
    double stdDev = standardDeviation(data);
    
    // Display results
    cout << "\n=== STATISTICS RESULTS ===" << endl;
    cout << "Count: " << data.size() << endl;
    cout << "Sum: " << sum << endl;
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Standard Deviation: " << stdDev << endl;
}

// Matrix operations
void matrixOperations() {
    int rows, cols;
    cout << "=== MATRIX OPERATIONS ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    vector<vector<double>> matrix1(rows, vector<double>(cols));
    vector<vector<double>> matrix2(rows, vector<double>(cols));
    
    // Input matrix 1
    cout << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }
    
    // Input matrix 2
    cout << "Enter elements of matrix 2:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }
    
    // Perform operations
    vector<vector<double>> sum(rows, vector<double>(cols));
    vector<vector<double>> difference(rows, vector<double>(cols));
    vector<vector<double>> product(rows, vector<double>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
            product[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    
    // Display results
    cout << "\n=== MATRIX RESULTS ===" << endl;
    
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1);
    
    cout << "Matrix 2:" << endl;
    printMatrix(matrix2);
    
    cout << "Sum:" << endl;
    printMatrix(sum);
    
    cout << "Difference:" << endl;
    printMatrix(difference);
    
    cout << "Element-wise Product:" << endl;
    printMatrix(product);
}

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double num : row) {
            cout << setw(10) << num;
        }
        cout << endl;
    }
    cout << endl;
}

// Scientific calculator functions
void scientificCalculator() {
    int sciChoice;
    double num, result;
    bool sciRunning = true;
    
    while (sciRunning) {
        cout << "\n=== SCIENTIFIC CALCULATOR ===" << endl;
        cout << "1. Sine (degrees)" << endl;
        cout << "2. Cosine (degrees)" << endl;
        cout << "3. Tangent (degrees)" << endl;
        cout << "4. Logarithm (base 10)" << endl;
        cout << "5. Natural Logarithm (base e)" << endl;
        cout << "6. Factorial" << endl;
        cout << "7. Degrees to Radians" << endl;
        cout << "8. Radians to Degrees" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> sciChoice;
        
        try {
            switch (sciChoice) {
                case 1:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = sine(num);
                    cout << "sin(" << num << "°) = " << result << endl;
                    break;
                
                case 2:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = cosine(num);
                    cout << "cos(" << num << "°) = " << result << endl;
                    break;
                
                case 3:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = tangent(num);
                    cout << "tan(" << num << "°) = " << result << endl;
                    break;
                
                case 4:
                    cout << "Enter number: ";
                    cin >> num;
                    result = logarithm(num);
                    cout << "log10(" << num << ") = " << result << endl;
                    break;
                
                case 5:
                    cout << "Enter number: ";
                    cin >> num;
                    if (num <= 0) throw runtime_error("Error: Logarithm of non-positive number!");
                    result = log(num);
                    cout << "ln(" << num << ") = " << result << endl;
                    break;
                
                case 6:
                    int n;
                    cout << "Enter integer: ";
                    cin >> n;
                    result = factorial(n);
                    cout << n << "! = " << result << endl;
                    break;
                
                case 7:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = num * PI / 180.0;
                    cout << num << "° = " << result << " radians" << endl;
                    break;
                
                case 8:
                    cout << "Enter angle in radians: ";
                    cin >> num;
                    result = num * 180.0 / PI;
                    cout << num << " radians = " << result << "°" << endl;
                    break;
                
                case 0:
                    sciRunning = false;
                    break;
                
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Unit conversion functions
void conversionCalculator() {
    int convChoice;
    double value, result;
    bool convRunning = true;
    
    while (convRunning) {
        cout << "\n=== UNIT CONVERSION CALCULATOR ===" << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "3. Kilometers to Miles" << endl;
        cout << "4. Miles to Kilometers" << endl;
        cout << "5. Kilograms to Pounds" << endl;
        cout << "6. Pounds to Kilograms" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> convChoice;
        
        switch (convChoice) {
            case 1:
                cout << "Enter temperature in Celsius: ";
                cin >> value;
                result = (value * 9/5) + 32;
                cout << value << "°C = " << result << "°F" << endl;
                break;
            
            case 2:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> value;
                result = (value - 32) * 5/9;
                cout << value << "°F = " << result << "°C" << endl;
                break;
            
            case 3:
                cout << "Enter distance in kilometers: ";
                cin >> value;
                result = value * 0.621371;
                cout << value << " km = " << result << " miles" << endl;
                break;
            
            case 4:
                cout << "Enter distance in miles: ";
                cin >> value;
                result = value * 1.60934;
                cout << value << " miles = " << result << " km" << endl;
                break;
            
            case 5:
                cout << "Enter weight in kilograms: ";
                cin >> value;
                result = value * 2.20462;
                cout << value << " kg = " << result << " lbs" << endl;
                break;
            
            case 6:
                cout << "Enter weight in pounds: ";
                cin >> value;
                result = value * 0.453592;
                cout << value << " lbs = " << result << " kg" << endl;
                break;
            
            case 0:
                convRunning = false;
                break;
            
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

// Print calculation history
void printHistory(const vector<string>& history) {
    if (history.empty()) {
        cout << "No calculations in history." << endl;
        return;
    }
    
    cout << "=== CALCULATION HISTORY ===" << endl;
    for (size_t i = 0; i < history.size(); ++i) {
        cout << i+1 << ". " << history[i] << endl;
    }
}