include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <sstream>
#include <functional>
#include <map>
#include <limits>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

// Constants
const double PI = 3.14159265358979323846;
const double EPSILON = 1e-10; // For numerical precision

// Currency structure and exchange rates
struct Currency {
    string code;
    string name;
    string symbol;
    double toUSD; // Exchange rate to USD
    time_t lastUpdated;
};

// Global currency database
map<string, Currency> currencies = {
    {"USD", {"USD", "US Dollar", "$", 1.0, time(0)}},
    {"EUR", {"EUR", "Euro", "€", 0.85, time(0)}},
    {"GBP", {"GBP", "British Pound", "£", 0.73, time(0)}},
    {"JPY", {"JPY", "Japanese Yen", "¥", 110.25, time(0)}},
    {"CAD", {"CAD", "Canadian Dollar", "C$", 1.25, time(0)}},
    {"AUD", {"AUD", "Australian Dollar", "A$", 1.35, time(0)}},
    {"CHF", {"CHF", "Swiss Franc", "CHF", 0.92, time(0)}},
    {"CNY", {"CNY", "Chinese Yuan", "¥", 6.45, time(0)}},
    {"INR", {"INR", "Indian Rupee", "₹", 74.50, time(0)}},
    {"BRL", {"BRL", "Brazilian Real", "R$", 5.20, time(0)}},
    {"RUB", {"RUB", "Russian Ruble", "₽", 73.80, time(0)}},
    {"MXN", {"MXN", "Mexican Peso", "MX$", 20.15, time(0)}},
    {"KRW", {"KRW", "South Korean Won", "₩", 1180.0, time(0)}},
    {"SGD", {"SGD", "Singapore Dollar", "S$", 1.35, time(0)}},
    {"NZD", {"NZD", "New Zealand Dollar", "NZ$", 1.45, time(0)}}
};

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

// New function prototypes for differentiation and integration
double numericalDerivative(const function<double(double)>& f, double x, double h = 1e-5);
double numericalIntegration(const function<double(double)>& f, double a, double b, int n = 1000);
void calculusCalculator();
double evaluateExpression(const string& expression, double x);
void functionAnalyzer();

// Currency conversion prototypes
void currencyConverter();
double convertCurrency(double amount, const string& from, const string& to);
void displayAllCurrencies();
void updateExchangeRates(bool forceUpdate = false);
void simulateMarketFluctuations();
void addCustomCurrency();
void manageCurrencies();
string getCurrencySymbol(const string& code);
bool currencyExists(const string& code);

// Enhanced menu and utility functions
void clearScreen();
void pauseScreen();
string formatNumber(double num, int precision = 6);
string formatCurrency(double amount, const string& currencyCode);

// Memory function prototypes
void memoryOperations();
double memoryRecall();
void memoryStore(double value);
void memoryClear();

// Global variables for memory
double memory = 0.0;
bool memoryStored = false;

// Global variable for auto-update
bool autoUpdateEnabled = false;
const int AUTO_UPDATE_INTERVAL = 300; // 5 minutes in seconds

int main() {
    vector<string> calculationHistory;
    int choice;
    double num1, num2, result;
    bool running = true;
    
    // Initialize currency rates
    updateExchangeRates();

    cout << "=== ADVANCED MATHEMATICAL CALCULATOR ===" << endl;
    cout << "Created with C++" << endl;
    cout << "Includes Real-Time Currency Conversion" << endl << endl;

    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: // Addition
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    result = add(num1, num2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << formatNumber(result) << endl;
                    calculationHistory.push_back(to_string(num1) + " + " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 2: // Subtraction
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    result = subtract(num1, num2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << formatNumber(result) << endl;
                    calculationHistory.push_back(to_string(num1) + " - " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 3: // Multiplication
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    result = multiply(num1, num2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << formatNumber(result) << endl;
                    calculationHistory.push_back(to_string(num1) + " * " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 4: // Division
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    if (abs(num2) < EPSILON) throw runtime_error("Error: Division by zero!");
                    result = divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << formatNumber(result) << endl;
                    calculationHistory.push_back(to_string(num1) + " / " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 5: // Modulo
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    if (abs(num2) < EPSILON) throw runtime_error("Error: Division by zero in modulo!");
                    result = modulo(num1, num2);
                    cout << "Result: " << num1 << " % " << num2 << " = " << formatNumber(result) << endl;
                    calculationHistory.push_back(to_string(num1) + " % " + to_string(num2) + " = " + to_string(result));
                    break;
                
                case 6: // Square
                    cout << "Enter a number: ";
                    cin >> num1;
                    result = square(num1);
                    cout << "Result: " << num1 << "² = " << formatNumber(result) << endl;
                    calculationHistory.push_back(to_string(num1) + "² = " + to_string(result));
                    break;
                
                case 7: // Square Root
                    cout << "Enter a number: ";
                    cin >> num1;
                    if (num1 < 0) throw runtime_error("Error: Square root of negative number!");
                    result = squareRoot(num1);
                    cout << "Result: √" << num1 << " = " << formatNumber(result) << endl;
                    calculationHistory.push_back("√" + to_string(num1) + " = " + to_string(result));
                    break;
                
                case 8: // Power
                    cout << "Enter base and exponent: ";
                    cin >> num1 >> num2;
                    result = power(num1, num2);
                    cout << "Result: " << num1 << "^" << num2 << " = " << formatNumber(result) << endl;
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
                
                case 11: // Scientific Calculator
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
                            cout << "Double root: x = " << formatNumber(roots[0]) << endl;
                            calculationHistory.push_back("Quadratic equation " + to_string(a) + "x² + " + 
                                                      to_string(b) + "x + " + to_string(c) + " has double root x = " + 
                                                      to_string(roots[0]));
                        } else {
                            cout << "Roots: x1 = " << formatNumber(roots[0]) << ", x2 = " << formatNumber(roots[1]) << endl;
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
                    
                case 16: // Factorial
                    int n;
                    cout << "Enter a number: ";
                    cin >> n;
                    result = factorial(n);
                    cout << "Result: Factorial(" << n << ") = " << formatNumber(result) << endl;
                    calculationHistory.push_back("Factorial(" + to_string(n) + ") = " + to_string(result));
                    break;
                
                case 17: // Calculus Operations
                    calculusCalculator();
                    break;
                
                case 18: // Function Analyzer
                    functionAnalyzer();
                    break;
                
                case 19: // Currency Converter
                    currencyConverter();
                    break;
                
                case 20: // Memory Operations
                    memoryOperations();
                    break;
                
                case 21: // View History
                    printHistory(calculationHistory);
                    break;
                
                case 22: // Clear Screen
                    clearScreen();
                    break;
                
                case 23: // Manage Currencies
                    manageCurrencies();
                    break;
                
                case 24: // Update Exchange Rates
                    updateExchangeRates(true);
                    cout << "Exchange rates updated successfully!" << endl;
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
        
        if (choice != 0 && choice != 22) {
            pauseScreen();
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\n===== MAIN MENU =====" << endl;
    cout << "MATHEMATICAL OPERATIONS:" << endl;
    cout << " 1. Addition" << endl;
    cout << " 2. Subtraction" << endl;
    cout << " 3. Multiplication" << endl;
    cout << " 4. Division" << endl;
    cout << " 5. Modulo" << endl;
    cout << " 6. Square" << endl;
    cout << " 7. Square Root" << endl;
    cout << " 8. Power" << endl;
    cout << " 9. Current Date" << endl;
    cout << "10. Age Calculator" << endl;
    cout << "11. Scientific Calculator" << endl;
    cout << "12. Quadratic Equation Solver" << endl;
    cout << "13. Statistics Calculator" << endl;
    cout << "14. Matrix Operations" << endl;
    cout << "15. Unit Conversions" << endl;
    cout << "16. Factorial" << endl;
    cout << "17. Calculus Operations" << endl;
    cout << "18. Function Analyzer" << endl;
    cout << "\nCURRENCY & FINANCE:" << endl;
    cout << "19. Currency Converter" << endl;
    cout << "23. Manage Currencies" << endl;
    cout << "24. Update Exchange Rates" << endl;
    cout << "\nUTILITIES:" << endl;
    cout << "20. Memory Operations" << endl;
    cout << "21. View Calculation History" << endl;
    cout << "22. Clear Screen" << endl;
    cout << " 0. Exit" << endl;
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
    
    // Use gamma function for larger values to avoid overflow
    if (n > 20) {
        return tgamma(n + 1);
    }
    
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Quadratic equation solver
vector<double> quadraticEquation(double a, double b, double c) {
    vector<double> roots;
    
    if (abs(a) < EPSILON) {
        if (abs(b) < EPSILON) {
            if (abs(c) < EPSILON) {
                roots.push_back(0); // Infinite solutions, return 0 as representative
            }
            // Otherwise no solution
        } else {
            roots.push_back(-c / b); // Linear equation
        }
        return roots;
    }
    
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        roots.push_back((-b + sqrt(discriminant)) / (2 * a));
        roots.push_back((-b - sqrt(discriminant)) / (2 * a));
    } else if (abs(discriminant) < EPSILON) {
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
    string input;
    
    cout << "=== STATISTICS CALCULATOR ===" << endl;
    cout << "Enter data points (enter 'done' when finished):" << endl;
    
    while (true) {
        cout << "Enter number: ";
        cin >> input;
        
        if (input == "done" || input == "DONE") break;
        
        try {
            num = stod(input);
            data.push_back(num);
        } catch (const exception& e) {
            cout << "Invalid input. Please enter a number or 'done' to finish." << endl;
            cin.clear();
        }
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
    
    // Calculate mode
    map<double, int> frequency;
    for (double num : sortedData) {
        frequency[num]++;
    }
    
    double mode = sortedData[0];
    int maxCount = 1;
    for (const auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }
    
    // Display results
    cout << "\n=== STATISTICS RESULTS ===" << endl;
    cout << "Count: " << data.size() << endl;
    cout << "Sum: " << formatNumber(sum) << endl;
    cout << "Mean: " << formatNumber(mean) << endl;
    cout << "Median: " << formatNumber(median) << endl;
    cout << "Mode: " << formatNumber(mode) << " (appears " << maxCount << " times)" << endl;
    cout << "Minimum: " << formatNumber(minVal) << endl;
    cout << "Maximum: " << formatNumber(maxVal) << endl;
    cout << "Standard Deviation: " << formatNumber(stdDev) << endl;
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
            cout << setw(12) << formatNumber(num, 4);
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
        cout << "9. Exponential (e^x)" << endl;
        cout << "10. Absolute Value" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> sciChoice;
        
        try {
            switch (sciChoice) {
                case 1:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = sine(num);
                    cout << "sin(" << num << "°) = " << formatNumber(result) << endl;
                    break;
                
                case 2:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = cosine(num);
                    cout << "cos(" << num << "°) = " << formatNumber(result) << endl;
                    break;
                
                case 3:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = tangent(num);
                    cout << "tan(" << num << "°) = " << formatNumber(result) << endl;
                    break;
                
                case 4:
                    cout << "Enter number: ";
                    cin >> num;
                    result = logarithm(num);
                    cout << "log10(" << num << ") = " << formatNumber(result) << endl;
                    break;
                
                case 5:
                    cout << "Enter number: ";
                    cin >> num;
                    if (num <= 0) throw runtime_error("Error: Logarithm of non-positive number!");
                    result = log(num);
                    cout << "ln(" << num << ") = " << formatNumber(result) << endl;
                    break;
                
                case 6:
                    int n;
                    cout << "Enter integer: ";
                    cin >> n;
                    result = factorial(n);
                    cout << n << "! = " << formatNumber(result) << endl;
                    break;
                
                case 7:
                    cout << "Enter angle in degrees: ";
                    cin >> num;
                    result = num * PI / 180.0;
                    cout << num << "° = " << formatNumber(result) << " radians" << endl;
                    break;
                
                case 8:
                    cout << "Enter angle in radians: ";
                    cin >> num;
                    result = num * 180.0 / PI;
                    cout << num << " radians = " << formatNumber(result) << "°" << endl;
                    break;
                
                case 9:
                    cout << "Enter exponent: ";
                    cin >> num;
                    result = exp(num);
                    cout << "e^" << num << " = " << formatNumber(result) << endl;
                    break;
                
                case 10:
                    cout << "Enter number: ";
                    cin >> num;
                    result = abs(num);
                    cout << "|" << num << "| = " << formatNumber(result) << endl;
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
        
        if (sciChoice != 0) {
            pauseScreen();
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
        cout << "7. Meters to Feet" << endl;
        cout << "8. Feet to Meters" << endl;
        cout << "9. Liters to Gallons" << endl;
        cout << "10. Gallons to Liters" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> convChoice;
        
        switch (convChoice) {
            case 1:
                cout << "Enter temperature in Celsius: ";
                cin >> value;
                result = (value * 9/5) + 32;
                cout << value << "°C = " << formatNumber(result) << "°F" << endl;
                break;
            
            case 2:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> value;
                result = (value - 32) * 5/9;
                cout << value << "°F = " << formatNumber(result) << "°C" << endl;
                break;
            
            case 3:
                cout << "Enter distance in kilometers: ";
                cin >> value;
                result = value * 0.621371;
                cout << value << " km = " << formatNumber(result) << " miles" << endl;
                break;
            
            case 4:
                cout << "Enter distance in miles: ";
                cin >> value;
                result = value * 1.60934;
                cout << value << " miles = " << formatNumber(result) << " km" << endl;
                break;
            
            case 5:
                cout << "Enter weight in kilograms: ";
                cin >> value;
                result = value * 2.20462;
                cout << value << " kg = " << formatNumber(result) << " lbs" << endl;
                break;
            
            case 6:
                cout << "Enter weight in pounds: ";
                cin >> value;
                result = value * 0.453592;
                cout << value << " lbs = " << formatNumber(result) << " kg" << endl;
                break;
            
            case 7:
                cout << "Enter length in meters: ";
                cin >> value;
                result = value * 3.28084;
                cout << value << " m = " << formatNumber(result) << " ft" << endl;
                break;
            
            case 8:
                cout << "Enter length in feet: ";
                cin >> value;
                result = value * 0.3048;
                cout << value << " ft = " << formatNumber(result) << " m" << endl;
                break;
            
            case 9:
                cout << "Enter volume in liters: ";
                cin >> value;
                result = value * 0.264172;
                cout << value << " L = " << formatNumber(result) << " gallons" << endl;
                break;
            
            case 10:
                cout << "Enter volume in gallons: ";
                cin >> value;
                result = value * 3.78541;
                cout << value << " gallons = " << formatNumber(result) << " L" << endl;
                break;
            
            case 0:
                convRunning = false;
                break;
            
            default:
                cout << "Invalid choice. Try again." << endl;
        }
        
        if (convChoice != 0) {
            pauseScreen();
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

// Calculus functions
double numericalDerivative(const function<double(double)>& f, double x, double h) {
    // Using central difference for better accuracy
    return (f(x + h) - f(x - h)) / (2 * h);
}

double numericalIntegration(const function<double(double)>& f, double a, double b, int n) {
    // Simpson's rule for numerical integration
    if (n % 2 != 0) n++; // Ensure n is even
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }
    
    return sum * h / 3;
}

void calculusCalculator() {
    int calcChoice;
    double a, b, x, result;
    bool calcRunning = true;
    
    // Predefined functions
    map<int, string> functions = {
        {1, "sin(x)"},
        {2, "cos(x)"},
        {3, "x^2"},
        {4, "x^3"},
        {5, "e^x"},
        {6, "ln(x)"},
        {7, "1/x"}
    };
    
    while (calcRunning) {
        cout << "\n=== CALCULUS CALCULATOR ===" << endl;
        cout << "1. Numerical Differentiation" << endl;
        cout << "2. Numerical Integration" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> calcChoice;
        
        try {
            switch (calcChoice) {
                case 1: {
                    cout << "\n=== NUMERICAL DIFFERENTIATION ===" << endl;
                    cout << "Select a function:" << endl;
                    for (const auto& func : functions) {
                        cout << func.first << ". f(x) = " << func.second << endl;
                    }
                    cout << "Enter function choice: ";
                    int funcChoice;
                    cin >> funcChoice;
                    
                    if (functions.find(funcChoice) == functions.end()) {
                        throw runtime_error("Invalid function choice!");
                    }
                    
                    cout << "Enter point x to calculate derivative: ";
                    cin >> x;
                    
                    function<double(double)> f;
                    switch (funcChoice) {
                        case 1: f = [](double x) { return sin(x); }; break;
                        case 2: f = [](double x) { return cos(x); }; break;
                        case 3: f = [](double x) { return x * x; }; break;
                        case 4: f = [](double x) { return x * x * x; }; break;
                        case 5: f = [](double x) { return exp(x); }; break;
                        case 6: 
                            if (x <= 0) throw runtime_error("ln(x) undefined for x <= 0");
                            f = [](double x) { return log(x); }; 
                            break;
                        case 7:
                            if (abs(x) < EPSILON) throw runtime_error("1/x undefined at x = 0");
                            f = [](double x) { return 1.0 / x; };
                            break;
                    }
                    
                    result = numericalDerivative(f, x);
                    cout << "f'(x) at x = " << x << " is approximately " << formatNumber(result) << endl;
                    break;
                }
                
                case 2: {
                    cout << "\n=== NUMERICAL INTEGRATION ===" << endl;
                    cout << "Select a function:" << endl;
                    for (const auto& func : functions) {
                        cout << func.first << ". f(x) = " << func.second << endl;
                    }
                    cout << "Enter function choice: ";
                    int funcChoice;
                    cin >> funcChoice;
                    
                    if (functions.find(funcChoice) == functions.end()) {
                        throw runtime_error("Invalid function choice!");
                    }
                    
                    cout << "Enter lower limit a: ";
                    cin >> a;
                    cout << "Enter upper limit b: ";
                    cin >> b;
                    
                    if (a > b) {
                        swap(a, b);
                        cout << "Swapped limits (a must be <= b)" << endl;
                    }
                    
                    function<double(double)> f;
                    switch (funcChoice) {
                        case 1: f = [](double x) { return sin(x); }; break;
                        case 2: f = [](double x) { return cos(x); }; break;
                        case 3: f = [](double x) { return x * x; }; break;
                        case 4: f = [](double x) { return x * x * x; }; break;
                        case 5: f = [](double x) { return exp(x); }; break;
                        case 6: 
                            if (a <= 0) throw runtime_error("ln(x) undefined for x <= 0");
                            f = [](double x) { return log(x); }; 
                            break;
                        case 7:
                            if (a <= 0 && b >= 0) throw runtime_error("1/x undefined at x = 0");
                            f = [](double x) { return 1.0 / x; };
                            break;
                    }
                    
                    result = numericalIntegration(f, a, b);
                    cout << "∫f(x)dx from " << a << " to " << b << " ≈ " << formatNumber(result) << endl;
                    break;
                }
                
                case 0:
                    calcRunning = false;
                    break;
                
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (calcChoice != 0) {
            pauseScreen();
        }
    }
}

// Function analyzer
void functionAnalyzer() {
    cout << "\n=== FUNCTION ANALYZER ===" << endl;
    cout << "This feature analyzes basic polynomial functions." << endl;
    
    double a, b, c;
    cout << "Enter coefficients for quadratic function f(x) = ax² + bx + c:" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    
    function<double(double)> f = [a, b, c](double x) { return a*x*x + b*x + c; };
    
    // Find derivative
    function<double(double)> f_prime = [a, b](double x) { return 2*a*x + b; };
    
    // Find critical points
    vector<double> criticalPoints;
    if (abs(a) > EPSILON) {
        double criticalPoint = -b / (2*a);
        criticalPoints.push_back(criticalPoint);
    }
    
    // Analyze function
    cout << "\n=== FUNCTION ANALYSIS ===" << endl;
    cout << "f(x) = " << a << "x² + " << b << "x + " << c << endl;
    cout << "f'(x) = " << 2*a << "x + " << b << endl;
    
    if (!criticalPoints.empty()) {
        double cp = criticalPoints[0];
        cout << "Critical point: x = " << formatNumber(cp) << endl;
        cout << "f(" << formatNumber(cp) << ") = " << formatNumber(f(cp)) << endl;
        
        if (a > 0) {
            cout << "This is a minimum point (parabola opens upward)" << endl;
        } else {
            cout << "This is a maximum point (parabola opens downward)" << endl;
        }
    }
    
    // Calculate definite integral over a range
    double lower, upper;
    cout << "\nEnter range for definite integral calculation:" << endl;
    cout << "Lower limit: "; cin >> lower;
    cout << "Upper limit: "; cin >> upper;
    
    if (lower > upper) swap(lower, upper);
    
    double integral = numericalIntegration(f, lower, upper);
    cout << "∫f(x)dx from " << lower << " to " << upper << " ≈ " << formatNumber(integral) << endl;
}

// Currency conversion functions
void currencyConverter() {
    double amount;
    string fromCurrency, toCurrency;
    bool convRunning = true;
    
    while (convRunning) {
        cout << "\n=== CURRENCY CONVERTER ===" << endl;
        cout << "Supported currencies: ";
        int count = 0;
        for (const auto& currency : currencies) {
            cout << currency.first;
            if (++count < currencies.size()) cout << ", ";
            if (count % 8 == 0) cout << endl << "                   ";
        }
        cout << endl;
        
        cout << "Enter amount: ";
        cin >> amount;
        
        cout << "Enter source currency code: ";
        cin >> fromCurrency;
        transform(fromCurrency.begin(), fromCurrency.end(), fromCurrency.begin(), ::toupper);
        
        if (!currencyExists(fromCurrency)) {
            cout << "Error: Currency '" << fromCurrency << "' not supported." << endl;
            continue;
        }
        
        cout << "Enter target currency code: ";
        cin >> toCurrency;
        transform(toCurrency.begin(), toCurrency.end(), toCurrency.begin(), ::toupper);
        
        if (!currencyExists(toCurrency)) {
            cout << "Error: Currency '" << toCurrency << "' not supported." << endl;
            continue;
        }
        
        if (fromCurrency == toCurrency) {
            cout << "Source and target currencies are the same." << endl;
            continue;
        }
        
        try {
            double result = convertCurrency(amount, fromCurrency, toCurrency);
            cout << "\n=== CONVERSION RESULT ===" << endl;
            cout << formatCurrency(amount, fromCurrency) << " = " << formatCurrency(result, toCurrency) << endl;
            
            // Show exchange rate
            double rate = currencies[toCurrency].toUSD / currencies[fromCurrency].toUSD;
            cout << "Exchange rate: 1 " << fromCurrency << " = " << formatNumber(rate, 6) << " " << toCurrency << endl;
            
            // Show last update time
            time_t lastUpdate = max(currencies[fromCurrency].lastUpdated, currencies[toCurrency].lastUpdated);
            cout << "Last updated: " << ctime(&lastUpdate);
            
        } catch (const exception& e) {
            cerr << "Conversion error: " << e.what() << endl;
        }
        
        cout << "\n1. New conversion" << endl;
        cout << "2. Update exchange rates" << endl;
        cout << "3. View all currencies" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                break;
            case 2:
                updateExchangeRates(true);
                break;
            case 3:
                displayAllCurrencies();
                break;
            case 0:
                convRunning = false;
                break;
            default:
                cout << "Invalid choice. Continuing with new conversion." << endl;
        }
    }
}

double convertCurrency(double amount, const string& from, const string& to) {
    if (!currencyExists(from) || !currencyExists(to)) {
        throw runtime_error("Invalid currency code");
    }
    
    // Convert to USD first, then to target currency
    double usdAmount = amount / currencies[from].toUSD;
    return usdAmount * currencies[to].toUSD;
}

void displayAllCurrencies() {
    cout << "\n=== SUPPORTED CURRENCIES ===" << endl;
    cout << setw(8) << "Code" << setw(20) << "Currency" << setw(10) << "Symbol" 
         << setw(15) << "Rate to USD" << setw(25) << "Last Updated" << endl;
    cout << string(78, '-') << endl;
    
    for (const auto& pair : currencies) {
        const Currency& curr = pair.second;
        cout << setw(8) << curr.code 
             << setw(20) << curr.name 
             << setw(10) << curr.symbol
             << setw(15) << formatNumber(curr.toUSD, 4);
        
        // Format last updated time
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &curr.lastUpdated);
        string timeStr(buffer);
        timeStr = timeStr.substr(0, timeStr.length() - 1); // Remove newline
        cout << setw(25) << timeStr << endl;
    }
}

void updateExchangeRates(bool forceUpdate) {
    time_t currentTime = time(0);
    
    for (auto& pair : currencies) {
        Currency& curr = pair.second;
        
        // Update if forced or if rates are older than 1 hour
        if (forceUpdate || (currentTime - curr.lastUpdated) > 3600) {
            // Simulate real-time rate fluctuations
            simulateMarketFluctuations();
            curr.lastUpdated = currentTime;
        }
    }
    
    if (forceUpdate) {
        cout << "Exchange rates updated with current market fluctuations." << endl;
    }
}

void simulateMarketFluctuations() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-0.02, 0.02); // ±2% fluctuation
    
    for (auto& pair : currencies) {
        if (pair.first != "USD") { // USD is base currency
            double fluctuation = 1.0 + dis(gen);
            pair.second.toUSD *= fluctuation;
            
            // Ensure rates stay within reasonable bounds
            if (pair.second.toUSD < 0.001) pair.second.toUSD = 0.001;
            if (pair.second.toUSD > 10000) pair.second.toUSD = 10000;
        }
    }
}

void addCustomCurrency() {
    string code, name, symbol;
    double rate;
    
    cout << "\n=== ADD CUSTOM CURRENCY ===" << endl;
    cout << "Enter currency code (3 letters): ";
    cin >> code;
    transform(code.begin(), code.end(), code.begin(), ::toupper);
    
    if (currencyExists(code)) {
        cout << "Currency '" << code << "' already exists." << endl;
        return;
    }
    
    if (code.length() != 3) {
        cout << "Currency code must be 3 letters." << endl;
        return;
    }
    
    cout << "Enter currency name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter currency symbol: ";
    getline(cin, symbol);
    
    cout << "Enter exchange rate to USD: ";
    cin >> rate;
    
    if (rate <= 0) {
        cout << "Exchange rate must be positive." << endl;
        return;
    }
    
    currencies[code] = {code, name, symbol, rate, time(0)};
    cout << "Currency '" << code << "' added successfully!" << endl;
}

void manageCurrencies() {
    int choice;
    bool managing = true;
    
    while (managing) {
        cout << "\n=== CURRENCY MANAGEMENT ===" << endl;
        cout << "1. View All Currencies" << endl;
        cout << "2. Add Custom Currency" << endl;
        cout << "3. Remove Currency" << endl;
        cout << "4. Update Exchange Rates" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayAllCurrencies();
                break;
                
            case 2:
                addCustomCurrency();
                break;
                
            case 3:
                {
                    string code;
                    cout << "Enter currency code to remove: ";
                    cin >> code;
                    transform(code.begin(), code.end(), code.begin(), ::toupper);
                    
                    if (code == "USD") {
                        cout << "Cannot remove base currency USD." << endl;
                    } else if (currencies.erase(code)) {
                        cout << "Currency '" << code << "' removed successfully." << endl;
                    } else {
                        cout << "Currency '" << code << "' not found." << endl;
                    }
                }
                break;
                
            case 4:
                updateExchangeRates(true);
                cout << "Exchange rates updated!" << endl;
                break;
                
            case 0:
                managing = false;
                break;
                
            default:
                cout << "Invalid choice." << endl;
        }
        
        if (choice != 0) {
            pauseScreen();
        }
    }
}

bool currencyExists(const string& code) {
    return currencies.find(code) != currencies.end();
}

string getCurrencySymbol(const string& code) {
    if (currencyExists(code)) {
        return currencies[code].symbol;
    }
    return code; // Return code if symbol not found
}

string formatCurrency(double amount, const string& currencyCode) {
    string symbol = getCurrencySymbol(currencyCode);
    
    // Format based on currency type
    if (symbol == "€" || symbol == "£" || symbol == "₹") {
        // Symbol before amount
        return symbol + formatNumber(amount, 2);
    } else if (symbol == "$" || symbol == "C$" || symbol == "A$" || symbol == "NZ$" || symbol == "S$" || symbol == "MX$" || symbol == "R$") {
        // Symbol before amount
        return symbol + formatNumber(amount, 2);
    } else if (symbol == "¥" || symbol == "₩" || symbol == "₽") {
        // Symbol before amount
        return symbol + formatNumber(amount, 2);
    } else {
        // Code after amount
        return formatNumber(amount, 2) + " " + currencyCode;
    }
}

// Memory functions
void memoryOperations() {
    int memChoice;
    double value;
    bool memRunning = true;
    
    while (memRunning) {
        cout << "\n=== MEMORY OPERATIONS ===" << endl;
        cout << "1. Store Value in Memory" << endl;
        cout << "2. Recall Value from Memory" << endl;
        cout << "3. Clear Memory" << endl;
        cout << "4. Show Memory Status" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> memChoice;
        
        switch (memChoice) {
            case 1:
                cout << "Enter value to store: ";
                cin >> value;
                memoryStore(value);
                cout << "Value " << formatNumber(value) << " stored in memory." << endl;
                break;
            
            case 2:
                if (memoryStored) {
                    cout << "Memory value: " << formatNumber(memoryRecall()) << endl;
                } else {
                    cout << "Memory is empty." << endl;
                }
                break;
            
            case 3:
                memoryClear();
                cout << "Memory cleared." << endl;
                break;
            
            case 4:
                if (memoryStored) {
                    cout << "Memory contains: " << formatNumber(memory) << endl;
                } else {
                    cout << "Memory is empty." << endl;
                }
                break;
            
            case 0:
                memRunning = false;
                break;
            
            default:
                cout << "Invalid choice. Try again." << endl;
        }
        
        if (memChoice != 0) {
            pauseScreen();
        }
    }
}

double memoryRecall() { return memory; }
void memoryStore(double value) { memory = value; memoryStored = true; }
void memoryClear() { memory = 0; memoryStored = false; }

// Utility functions
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

string formatNumber(double num, int precision) {
    stringstream ss;
    ss << fixed << setprecision(precision) << num;
    string result = ss.str();
    
    // Remove trailing zeros and decimal point if not needed
    size_t dotPos = result.find('.');
    if (dotPos != string::npos) {
        // Remove trailing zeros
        result = result.substr(0, result.find_last_not_of('0') + 1);
        // Remove decimal point if at the end
        if (result.back() == '.') {
            result.pop_back();
        }
    }
    
    return result;
}
