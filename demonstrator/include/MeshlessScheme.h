//
// Created by Johannes Martin on 21.09.22.
//

#ifndef DEMONSTRATOR_MESHLESSSCHEME_H
#define DEMONSTRATOR_MESHLESSSCHEME_H

#include <iomanip>

#include "parameter.h"
#include "InitialDistribution.h"
#include "Logger.h"
#include "Domain.h"
#include "Helper.h"

class MeshlessScheme {

public:
    struct Configuration {
        std::string initFile;
        std::string outDir;
        double timeStep;
        double timeEnd;
        int h5DumpInterval;
        double periodicBoxLimits[2 * DIM];
        double kernelSize;
#if MURNAGHAN_EOS
        double MURN_K0;
        double MURN_n;
        double MURN_rho0;
#else
        double gamma; // adiabatic index
#endif // Murnaghan EOS
    };

    MeshlessScheme(Configuration config, Particles *particles, Domain::Cell domain);
    ~MeshlessScheme();

    void run();

private:
    Configuration config;
    double timeStep;
    Particles *particles;
#if PERIODIC_BOUNDARIES
    Particles ghostParticles;
#endif
    Domain domain;
    Helper helper {};
};


#endif //DEMONSTRATOR_MESHLESSSCHEME_H
