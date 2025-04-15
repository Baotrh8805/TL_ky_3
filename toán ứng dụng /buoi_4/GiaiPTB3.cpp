#include <iostream>
#include <cmath>

using namespace std;

void solveCubicEquation(const double& a, const double& b, const double& c, const double& d) {
    if (a == 0) {
        cout << "Không phải phương trình bậc 3!" << endl;
        return;
    }

    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

    double delta = (q * q / 4) + (p * p * p / 27);

    if (delta > 0) { 
        double u = cbrt(-q / 2 + sqrt(delta));
        double v = cbrt(-q / 2 - sqrt(delta));
        double x1 = u + v - (b / (3 * a));

        cout << "Phương trình có một nghiệm thực: x = " << x1 << endl;
    } 
    else if (delta == 0) { 
        double x1 = 3 * q / p - (b / (3 * a));
        double x2 = -3 * q / (2 * p) - (b / (3 * a));

        cout << "Phương trình có nghiệm kép:\n";
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } 
    else { 
        double r = sqrt(-p / 3);
        double theta = acos(3 * q / (2 * p) * sqrt(-3 / p));

        double x1 = 2 * r * cos(theta / 3) - (b / (3 * a));
        double x2 = 2 * r * cos((theta + 2 * M_PI) / 3) - (b / (3 * a));
        double x3 = 2 * r * cos((theta + 4 * M_PI) / 3) - (b / (3 * a));

        cout << "Phương trình có ba nghiệm thực:\n";
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
    }
}

int main() {
    double a, b, c, d;
    cout << "Nhập hệ số a, b, c, d: ";
    cin >> a >> b >> c >> d;

    solveCubicEquation(a, b, c, d);
    return 0;
}