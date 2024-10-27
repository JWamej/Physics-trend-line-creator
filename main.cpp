#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;


tuple<double, double, double> quadratic(vector<tuple<int, double, double>> database, int uncertaintyMultiplier, int resolution, int divider){
    int index;
    double resultEquation;
    double resultExpected;
    double uncertainty;
    int checkmark;

    for (int a=(-resolution); a<resolution; a++){
        for (int b=(-resolution); b<resolution; b++){

            for (int c=(-resolution); c<resolution; c++){
                index = 0;
                checkmark = 0;
                double normalizedA = a / divider;
                double normalizedB = b / divider;
                double normalizedC = c / divider;

                for (int x=0; x<16; x++){
                    double normalizedX = x*10;
                    resultEquation = normalizedA * pow(x, 2) + normalizedB * x + normalizedC;
                    resultExpected = get<1>(database[index]);
                    uncertainty = get<2>(database[index]);
                    if (resultEquation > (resultExpected - uncertainty * uncertaintyMultiplier) && resultEquation < (resultExpected + uncertainty * uncertaintyMultiplier)){
                        checkmark ++;
                    }
                    
                    index ++;
                }
                
                if (checkmark == 16){
                    return {normalizedA, normalizedB, normalizedC};
                }

            }
        }
    }
    return {-INFINITY, 0, 0};
}


tuple<double, double, double, double> polynomial3(vector<tuple<int, double, double>> database, int uncertaintyMultiplier, int resolution, int divider){
    int index;
    double resultEquation;
    double resultExpected;
    double uncertainty;
    int checkmark;


    for (int a=(-resolution); a<resolution; a++){

        for (int b=(-resolution); b<resolution; b++){

            for (int c=(-resolution); c<resolution; c++){

                for (int d=(-resolution); d<resolution; d++){
                    index = 0;
                    checkmark = 0;
                    double normalizedA = a / divider;
                    double normalizedB = b / divider;
                    double normalizedC = c / divider;
                    double normalizedD = d / divider;

                    for (int x=0; x<16; x++){
                        double normalizedX = x*10;
                        resultEquation = normalizedA * pow(x, 3) + normalizedB * pow(x, 2) + normalizedC * x + normalizedD;
                        resultExpected = get<1>(database[index]);
                        uncertainty = get<2>(database[index]);
                        if (resultEquation > (resultExpected - uncertainty * uncertaintyMultiplier) && resultEquation < (resultExpected + uncertainty * uncertaintyMultiplier)){
                            checkmark ++;
                        }
                        
                        index ++;
                    }
                    
                    if (checkmark == 16){
                        return {normalizedA, normalizedB, normalizedC, normalizedD};
                    }

                }
            }
        }
    }
    return {-INFINITY, 0, 0, 0};
}


tuple<double, double, double> logBase(vector<tuple<int, double, double>> database, int uncertaintyMultiplier, int resolution, int divider){
    int index;
    double resultEquation;
    double resultExpected;
    double uncertainty;
    int checkmark;

    for (int a=(-resolution); a<resolution; a++){
        for (double b=0.0000001; b<resolution; b++){
            for (int c=(-resolution); c<resolution; c++){
                index = 0;
                checkmark = 0;
                double normalizedA = a / divider;
                double normalizedB = b / divider;
                double normalizedC = c / divider;

                for (double x=0.0000000001; x<16; x++){
                    double normalizedX = x*10;
                    resultEquation = normalizedA * (log(normalizedB) / log(x)) + normalizedC;

                    resultExpected = get<1>(database[index]);
                    uncertainty = get<2>(database[index]);
                    if (resultEquation > (resultExpected - uncertainty * uncertaintyMultiplier) && resultEquation < (resultExpected + uncertainty * uncertaintyMultiplier)){
                        checkmark ++;
                    }
                    
                    index ++;
                    }
                    
                    if (checkmark == 16){
                        return {normalizedA, normalizedB, normalizedC};
                    }
                }
            }
        }
    return {-INFINITY, 0, 0};
    }


tuple<double, double, double> logValue(vector<tuple<int, double, double>> database, int uncertaintyMultiplier, int resolution, int divider){
    int index;
    double resultEquation;
    double resultExpected;
    double uncertainty;
    int checkmark;

    for (int a=(-resolution); a<resolution; a++){
        for (double b=0.0000001; b<resolution; b++){
            for (int c=(-resolution); c<resolution; c++){
                index = 0;
                checkmark = 0;
                double normalizedA = a / divider;
                double normalizedB = b / divider;
                double normalizedC = c / divider;

                for (double x=0.00000001; x<16; x++){
                    double normalizedX = x*10;
                    resultEquation = normalizedA * (log(x) / log(normalizedB)) + normalizedC;

                    resultExpected = get<1>(database[index]);
                    uncertainty = get<2>(database[index]);
                    if (resultEquation > (resultExpected - uncertainty * uncertaintyMultiplier) && resultEquation < (resultExpected + uncertainty * uncertaintyMultiplier)){
                        checkmark ++;
                    }
                    
                    index ++;
                    }
                    
                    if (checkmark == 16){
                        return {normalizedA, normalizedB, normalizedC};
                    }
                }
            }
        }
    return {-INFINITY, 0, 0};
    }


tuple<double, double, double> eExponential(vector<tuple<int, double, double>> database, int uncertaintyMultiplier, int resolution, int divider){
    int index;
    double resultEquation;
    double resultExpected;
    double uncertainty;
    int checkmark;

    for (int a=(-resolution); a<resolution; a++){
        for (int b=(-resolution); b<resolution; b++){
            for (int c=(-resolution); c<resolution; c++){
                index = 0;
                checkmark = 0;
                double normalizedA = a / divider;
                double normalizedB = b / divider;
                double normalizedC = c / divider;

                for (int x=0; x<16; x++){
                    int normalizedX = x*10;
                    resultEquation = normalizedA * pow(normalizedB, x) + normalizedC;

                    resultExpected = get<1>(database[index]);
                    uncertainty = get<2>(database[index]);
                    if (resultEquation > (resultExpected - uncertainty * uncertaintyMultiplier) && resultEquation < (resultExpected + uncertainty * uncertaintyMultiplier)){
                        checkmark ++;
                    }
                    
                    index ++;
                    }
                    
                    if (checkmark == 16){
                        return {normalizedA, normalizedB, normalizedC};
                    }
                }
            }
        }
    return {-INFINITY, 0, 0};
    }


tuple<double, double> hyperbole(vector<tuple<int, double, double>> database, int uncertaintyMultiplier, int resolution, int divider){
    int index;
    double resultEquation;
    double resultExpected;
    double uncertainty;
    int checkmark;

    for (int a=(-resolution); a<resolution; a++){
        for (int b=(-resolution); b<resolution; b++){
            index = 0;
            checkmark = 0;
            double normalizedA = a / divider;
            double normalizedB = b / divider;

            for (int x=0; x<16; x++){
                int normalizedX = x*10;
                resultEquation = normalizedA / x + normalizedB;

                resultExpected = get<1>(database[index]);
                uncertainty = get<2>(database[index]);
                if (resultEquation > (resultExpected - uncertainty * uncertaintyMultiplier) && resultEquation < (resultExpected + uncertainty * uncertaintyMultiplier)){
                    checkmark ++;
                }
                
                index ++;
                }
                
                if (checkmark == 16){
                    return {normalizedA, normalizedB};
                }
                
            }
        }
    return {-INFINITY, 0};
    }



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

    cout << "Initiated" <<endl;
    int resolution = 100;
    int divider = 10;
    for (int uncertaintyMultiplierMultiplier=5; uncertaintyMultiplierMultiplier>-1; uncertaintyMultiplierMultiplier--){
        int uncertaintyMultiplier = 0 + 5 * uncertaintyMultiplierMultiplier;

        cout << "Iteration" <<endl;


        tuple<double, double, double> success1 = quadratic(coordinatesExperiment, uncertaintyMultiplier, resolution, divider);
        
        if (get<0>(success1) != -INFINITY){
            cout << "Success achieved for quadratic formula: " << get<0>(success1) << "x^2 + " << get<1>(success1) << "x + " << get<2>(success1) << endl;
        }
        
        cout << "end1" <<endl;
        // tuple<double, double, double, double> success2 = polynomial3(coordinatesExperiment, uncertaintyMultiplier, resolution, divider);

        // if (get<0>(success2) != -INFINITY){
        // cout << "Success achieved for polynomial formula (power 3): " << get<0>(success2) << "x^3 + " << get<1>(success2) << "x^2 + " << get<2>(success2) << "x + " << get<3>(success2) << endl;
        // }

        cout << "end2" <<endl;
        tuple<double, double, double> success3 = logBase(coordinatesExperiment, uncertaintyMultiplier, resolution, divider);

        if (get<0>(success3) != -INFINITY){
        cout << "Success achieved for logBase: " << get<0>(success3) << " * log_(x)" << get<1>(success3) << " + " << get<2>(success3) << endl;
        }

        cout << "end3" <<endl;
        tuple<double, double, double> success4 = logValue(coordinatesExperiment, uncertaintyMultiplier, resolution, divider);

        if (get<0>(success4) != -INFINITY){
        cout << "Success achieved for logBase: " << get<0>(success4) << " * log_(" << get<1>(success4) << ")x" << " + " << get<2>(success4) << endl;
        }

        cout << "end4" <<endl;
        tuple<double, double, double> success5 = eExponential(coordinatesExperiment, uncertaintyMultiplier, resolution, divider);

        if (get<0>(success5) != -INFINITY){
        cout << "Success achieved for exponential: " << get<0>(success5) << " * " << get<1>(success5) << "^x" << " + " << get<2>(success5) << endl;
        }

        cout << "end5" <<endl;
        tuple<double, double> success6 = hyperbole(coordinatesExperiment, uncertaintyMultiplier, resolution, divider);

        if (get<0>(success6) != -INFINITY){
        cout << "Success achieved for hyperbole: " << get<0>(success6) << " / x + " << get<1>(success6) << endl;
        }


        return 0;
    }


}