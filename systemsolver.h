//
// Created by Severin on 25.03.2022.
//

#ifndef NUMERICAL_TASK_3_SYSTEMSOLVER_H
#define NUMERICAL_TASK_3_SYSTEMSOLVER_H

#include <iostream>

class SystemSolver{
public:
    SystemSolver();
    ~SystemSolver();
    void ReadData(FILE *DATA);
    void WriteData(FILE *DATA);
    void SolveGauss();
    void SolveIordan();
    void SolveLeadElement();
    double GetResidual();
private:
    double* A; // AX = B
    double* X;
    double* B;
    int n;
};

#endif //NUMERICAL_TASK_3_SYSTEMSOLVER_H