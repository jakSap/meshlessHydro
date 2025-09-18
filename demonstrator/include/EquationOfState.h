//
// Created by Jakob Sappler on 18.09.25
//

#ifndef MESHLESSHYDRO_EQUATIONOFSTATE_H
#define MESHLESSHYDRO_EQUATIONOFSTATE_H

#include <cmath>

#include "parameter.h"
#include "Logger.h"

class EquationOfState {

public:
    EquationOfState(
#if EOS == 0
                double gamma
#elif EOS == 1
                double K0, murn_n, rho0
#endif // EOS
    );

    double EOSPressure(const double &rho, const double &u);
    double EOSSoundSpeed(const double &rho, const double &u,
                        const double &p);
    double EOSInternalEnergy(const double &rho, const double &p);

#if EOS == 0
    double gamma;
#elif EOS == 1
    double K0, murn_n, rho0;
#endif // EOS
};
#endif // MESHLESSHYDRO_EQUATIONOFSTATE_H