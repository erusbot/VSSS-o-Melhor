#include "utils.h"

double Utils::toPositiveAngle(double angle) {
    return fmod(angle + 2 * M_PI, 2 * M_PI);
}

double Utils::smallestAngleDiff(double target, double source) {
    double a = Utils::toPositiveAngle(target) - Utils::toPositiveAngle(source);
    if (a > M_PI) {
        a = a - 2 * M_PI;
    }
    else if (a < -M_PI) {
        a = a + 2 * M_PI;
    }
    return a;
}

double Utils::to180range(double angle) {
    angle = fmod(angle, 2 * M_PI);
    if (angle < - M_PI) {
        angle = angle + 2 * M_PI;
    } else if (angle > M_PI) {
        angle = angle - 2 * M_PI;
    }
    return angle;
}

double Utils::bound(double x, double low, double high) {
        if (x < low) x = low;
        if (x > high) x = high;
        return x;
}

double Utils::distance(doublePair first, doublePair second) {
        return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
}
