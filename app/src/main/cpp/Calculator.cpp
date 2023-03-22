#include "include/Calculator.h"

namespace calculator {

    int Calculator::sum(int first, int second) {
        return first + second;
    };
    int Calculator::minus(int first, int second){
        return first - second;
    };
    int Calculator::divide(int first, int second){
        return first / second;
    };
    int Calculator::times(int first, int second){
        return first * second;
    };

}