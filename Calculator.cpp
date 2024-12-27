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
            // return pow(base,exp);
            if(exp == 0 ) return 1;
            T result=1;
            bool negativeExp=false;
            if(exp<0){
                negativeExp=true;
                exp=-exp;
            }
            while(exp>0){
                if(static_cast<int>(exp)%2==1){
                    result *=base;
                }
                base *=base;
                exp/=2;
            }
            if(negativeExp){
                return 1/result;
            }
            return result;
        }
        T squareRoot(T value){
            if(value<0){
                throw invalid_argument("square root of negative number is not defined");
            }
            // return sqrt(value);
            T guess = value / 2;
            T tolerance = 0.000001;
            while (true) {
                T newGuess = (guess + value / guess) / 2;
                if (abs(guess - newGuess) < tolerance) {
                    break;
                }
                guess = newGuess;
            }
            return guess;   

        }
        T exponential(T value) {
            // return exp(value); 
            T result = 1;
            T term = 1;
            for (int i = 1; i < 20; ++i) {
                term *= value / i;
                result += term;
            }
            return result;

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
            // return log(num1);
            T x = num1 - 1;
            T result = 0;
            T term = x;
            for (int i = 1; i < 20; ++i) {
                if (i % 2 == 1) {
                    result += term / i;
                } else {
                    result -= term / i;
                }
                term *= x;
            }
            return result;

        }
        T sine(T angle){
            // return sin(angle);
            T result = 0;
            T term = angle;
            int sign = 1;
            for (int i = 1; i < 10; i += 2) {
                result += sign * term;
                term *= angle * angle / ((i + 1) * (i + 2));
                sign = -sign;
            }
return result;

        }
        T cosine(T angle){
            // return cos(angle);
            T result = 1;
            T term = 1;
            int sign = -1;
            for (int i = 2; i < 10; i += 2) {
                term *= angle * angle / ((i - 1) * i);
                result += sign * term;
                sign = -sign;
            }
            return result;

        }
        T tangent(T angle){
            // return tan(angle);
            T sinVal = sine(angle);
            T cosVal = cosine(angle);
            if (cosVal == 0) {
                throw invalid_argument("Tangent of angle with cos(x) = 0 is undefined");
            }
            return sinVal / cosVal;
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