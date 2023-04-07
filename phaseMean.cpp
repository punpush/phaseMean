#include <iostream>
#include <random>

#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    setlocale(LC_ALL, "ru");

    int sizeOfSample = 0;
    double trueDir = 0;
    int stdev = 0;
    bool flag = true;
    std::vector<double> phase;

    std::cout << "Введите число выборок от 50 до 1000\n";
    while (flag) {
        std::cin >> sizeOfSample;

        if (sizeOfSample < 50 || sizeOfSample > 1000) {
            std::cout << "Error: Введите число выборок в указанном диапазоне\n";
        } else {
            flag = false;
        }
    }

    flag = true;

    std::cout << "Введите СКО: 10, 20, 30\n";
    while (flag) {
        std::cin >> stdev;

        if ( (stdev != 10) && (stdev != 20) && (stdev != 30)) {
            std::cout << "Error: Введите одно из указанных СКО\n";
        }
        else {
            flag = false;
        }
    }

    flag = true;

    std::cout << "Введите истинное направление от 0 до 360\n";
    while (flag) {
        std::cin >> trueDir;

        if (trueDir < 0 || trueDir > 360) {
            std::cout << "Error: Введите истинное направление в указанном диапазоне\n";
        }
        else {
            flag = false;
        }
    }

    phase.resize(sizeOfSample);

    std::mt19937 gen(std::rand());
    std::normal_distribution<> distr(trueDir, stdev);

    for (int i = 0; i < sizeOfSample; i++) {
        phase[i] = distr(gen);
    }

    for (int i = 0; i < sizeOfSample; i++) {
        if (phase.at(i) >= 360)
            phase[i] = phase[i] - 360;
        if (phase.at(i) < 0)
            phase[i] = phase[i] + 360;
    }

    double x = 0;
    double y = 0;

    for (int i = 0; i < sizeOfSample; i++) {
        x += cos(phase[i] * M_PI / 180);
        y += sin(phase[i] * M_PI / 180);
    }

    double mean = atan2(y, x) * 180 / M_PI;

    if (mean < 0) {
        mean += 360;
    }
    std::cout << "Усредненное значение угла: " << mean;
}
