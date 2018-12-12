#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const double POLLING_INTERVAL = 0.3; // in seconds (300ms)
const double KMPH_TO_KMPS = 0.000277778;
const double KMPS2_TO_G = 101.971621;

struct DataOBD
{
    double Vel;     // 차속 (Km/h) now
    double VelPrev; // 차속 (Km/h), 300ms before now
};

struct DataOther
{
    double Sound; // in-car sound pressure in dB
};

// takes two velocities (km/h) and returns the magnitude of the
// difference in km/s
double velocityChange(double v1, double v2)
{
    return fabs(KMPH_TO_KMPS * (v1 - v2));
}

double getAcceleration(double v1, double v2)
{
    return KMPS2_TO_G * (velocityChange(v1, v2) / POLLING_INTERVAL);
}

bool accidentDetected(struct DataOBD *obd, struct DataOther *other)
{
    if (other->Sound >= 160)
    {
        return true;
    }
    const double vel = fabs(obd->VelPrev);
    const double accel = getAcceleration(obd->Vel, obd->VelPrev);
    if (vel > 0.0 && accel >= 4.0)
    {
        return true;
    }
    return false;
}

int main()
{
    struct DataOBD dataOBD1;
    dataOBD1.Vel = 1.5;
    dataOBD1.VelPrev = 150.56;
    struct DataOther dataOther1;
    dataOther1.Sound = 65.5;

    assert(accidentDetected(&dataOBD1, &dataOther1));
    dataOther1.Sound = 165.5;
    assert(accidentDetected(&dataOBD1, &dataOther1));
    dataOBD1.VelPrev = 1.56;
    assert(accidentDetected(&dataOBD1, &dataOther1));
    dataOther1.Sound = 65.5;
    assert(!accidentDetected(&dataOBD1, &dataOther1));
    return 0;
}