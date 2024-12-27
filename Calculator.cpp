#include<vector>
#include<iostream>
#include<map>
using namespace std;
#include<cmath>
// #include<concepts>

// template<typename T>
// concept Numeric = std::integral<T> || std::floating_point<T>;

template <typename T> class ScientificCalculator
{
    private:

    public:
        T add(T num1,T num2){
            return num1+num2;
        }
        T sub(T num1,T num2){
            return num1-num2;
        }
        T multiply(T num1,T num2){
            return num1*num2;
        }
        T divide(T num1,T num2){
            if(num2==0){
                throw invalid_argument("Division by zero is not allowed!");
            }
            return num1/num2;
        }
        T power(T base,T exp){
            return pow(base,exp);
        }
        T squareRoot(T value){
            if(value<0){
                throw invalid_argument("square root of negative number is not defined");
            }
            return sqrt(value);
        }
        T exponential(T value) {
            return exp(value); 
        }
        T fraction(T numerator,T denominator){
            if(denominator==0){
                throw invalid_argument("Denominator cannot be zero in a faction");
            }
            return numerator/denominator;
        }
        T logarithm(T num1){
            if(num1 <= 0){
                throw invalid_argument("Logarithm of zero or negative is not defined");
            }
            return log(num1);
        }
        T sine(T angle){
            return sin(angle);
        }
        T cosine(T angle){
            return cos(angle);
        }
        T tangent(T angle){
            return tan(angle);
        }
};

int main(){
    try {
        ScientificCalculator<double> calc;
        double a,b;
        cout<<"Enter two number for basic operations (a,b):";
        cin>>a>>b;
        cout<<"Addition : "<<calc.add(a,b)<<endl;
        cout<<"Subtraction : "<<calc.sub(a,b)<<endl;
        cout<<"Multiplication : "<<calc.multiply(a,b)<<endl;
        cout<<"Division : "<<calc.divide(a,b)<<endl;

        double base,exp;
        cout<<"Enter Base and exponent for power calculation :";
        cin>>base>>exp;
        cout<<"Power: "<<calc.power(base,exp)<<endl;

        double value;
        cout << "Enter a value for square root calculation: ";
        cin >> value;
        cout << "Square Root: " << calc.squareRoot(value) << endl;

        cout << "Enter a value for logarithm calculation: ";
        cin >> value;
        cout << "Logarithm (natural): " << calc.logarithm(value) << endl;

        cout << "Enter a value for exponential calculation (e^value): ";
        cin >> value;
        cout << "Exponential: " << calc.exponential(value) << endl;

        double numerator, denominator;
        cout << "Enter numerator and denominator for fraction calculation: ";
        cin >> numerator >> denominator;
        cout << "Fraction: " << calc.fraction(numerator, denominator) << endl;

        // Trigonometric operations
        double angle;
        cout << "Enter an angle (in radians) for trigonometric calculations: ";
        cin >> angle;
        cout << "Sine: " << calc.sine(angle) << endl;
        cout << "Cosine: " << calc.cosine(angle) << endl;
        cout << "Tangent: " << calc.tangent(angle) << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
    
}