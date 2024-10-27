#include <cmath>
#include <vector>
#include <tuple>
#include <stdio.h>

using namespace std;


tuple<double, double, double, double> hyperbole(const vector<double>& resultsDatabase);


// This code is based on the knowledge that the function f(x)=-(190/(x-156))+0.4 *very* approximately matches the trend.
// I have came up with this function after spending some time with GDC and just trying out every mathematical operation I could thought of.
int main(){
    vector<tuple<int, double, double>> coordinatesExperiment = {
        {0, 2.46, 0.15},
        {10, 2.20, 0.15},
        {20, 2.07, 0.15},
        {30, 2.04, 0.14},
        {40, 1.94, 0.14},
        {50, 1.83, 0.14},
        {60, 1.80, 0.14},
        {70, 1.77, 0.14},
        {80, 1.76, 0.14},
        {90, 1.92, 0.14},
        {100, 2.06, 0.14},
        {110, 2.22, 0.15},
        {120, 3.10, 0.17},
        {130, 9.17, 0.16},
        {140, 17.91, 0.52},
        {150, 31.27, 1.42}};
    
    // I have decided to use pure vector<double> without any tuples to spped up the acces to desired value in the hyperbole().
    vector<double> resultsExperiment = {
        2.46,
        2.20,
        2.07,
        2.04,
        1.94,
        1.83,
        1.80,
        1.77,
        1.76,
        1.92,
        2.06,
        2.22,
        3.10,
        9.17,
        17.91,
        31.27};

    tuple<double, double, double, double> resultBestCombination = hyperbole(resultsExperiment);
    double a = get<1>(resultBestCombination);
    double b = get<2>(resultBestCombination);
    double c = get<3>(resultBestCombination);
    printf("Best combination found:\nf(x)= %.1f/(x%f))+%.2f", a, b, c);
}


// function f(x)=a/(x+b))+c
// where:
// -250.0 < a < -100
// -175.0 < b < -151.0
// 0.00 < c < 2.50
tuple<double, double, double, double> hyperbole(const vector<double>& resultsDatabase){
    const double a_initial = -500.0, a_step = 0.1, a_final = -000.0;
    const double b_initial = -175.0, b_step = 0.1, b_final = -150.1;
    const double c_initial = 0.00, c_step = 0.01, c_final = 2.50;

    tuple<double, double, double, double> winner = {-INFINITY, 0, 0, 0};
    

    for (double a = a_initial; a <= a_final; a += a_step){
        printf("%.1f\n", a);
        for (double b = b_initial; b <= b_final; b  += b_step){  
            for (double c = c_initial; c <= c_final; c += c_step){
                double percent_accuracy = 0;

                for (int i = 0; i <= 15; i++){
                    int x = 10 * i;
                    double resultCalculated = (a / (x + b)) + c;
                    double resultExpected = resultsDatabase[i];
                    percent_accuracy += (1 - abs((resultExpected - resultCalculated) / resultExpected));
                }

                double average_percent_accuracy = percent_accuracy / 16;
                if (average_percent_accuracy > get<0>(winner)){
                    winner = {average_percent_accuracy, a, b, c};
                }
            }
        }
    }
    return winner;
}