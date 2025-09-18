//
// Created by Jakob Sappler on 18.09.25
//

#include "../include/EquationOfState.h"

EquationOfState::EquationOfState(
#if EOS == 0
    double gamma
#elif EOS == 1
    double K0, murn_n, rho0
#endif // EOS
    ) :
# if EOS == 0
    gamma {gamma}
#elif EOS == 1
    K0 {K0}, murn_n {murn_n}, rho0 {rho0}
#endif //EOS
    {
#if EOS == 0
        Logger(INFO) << "Using ideal gas polytropic EOS with gamma = " << gamma;
#elif EOS == 1
        Logger(INFO) << "Using Murnaghan EOS, K0 = " << K0 <<
                            ", n = " << murn_n << ", rho0 = " << rho0;
#endif //EOS
}

double EquationOfState::EOSPressure(const double &rho, const double &u){
#if EOS == 0 // Ideal gas
    return (gamma - 1) * u * rho;
#elif EOS == 1 // Murnaghan
    return K0 / murn_n * (pow(rho / rho0, murn_n) - 1);
#endif // EOS
}

double EquationOfState::EOSSoundSpeed(const double &rho, const double &u,
                        const double &p){
#if EOS == 0 // Ideal gas
    return sqrt(gamma * p / rho);
#elif EOS == 1 // Murnaghan
    return K0 / rho0 * pow(rho / rho0, murn_n - 1);
#endif // EOS
}

double EquationOfState::EOSInternalEnergy(const double &rho, const double &p){
#if EOS == 0 // Ideal gas
    return p /((gamma - 1) * rho);
#elif EOS == 1 // Murnaghan
    return 1;
#endif // EOS
}