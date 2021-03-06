#include <iostream>
#include <unistd.h>

#include "systemsolver.h"

int main(int argc, char *argv[]){

    // Creating and opening files

    FILE *DATA, *RESULT;

    DATA = fopen("data.dat", "r");
    RESULT = fopen("result.dat", "w+");

    // Reading commandline arguments

    if (argc != 2){
        printf("Usage: \n\t-g for Gauss method. \n\t-j for Jordan scheme. \n\t-l for pivot element method.\n");
        exit(1);
    }

    SystemSolver system = SystemSolver();
    system.ReadData(DATA);

    int opt;
    while((opt = getopt(argc, argv, "gjl")) != -1)
    {
        switch(opt)
        {
            case 'g':
                system.SolveGauss();
                break;
            case 'j':
                system.SolveJordan();
                break;
            case 'l':
                system.SolveLeadElement();
                break;
            default:
                std::cout << "Usage: \n\t-g for Gauss method. \n\t-j for Jordan scheme. \n\t-l for pivot element method.\n";
                exit(1);
        }
        break;
    }

    std::cout << system.GetResidual() << std::endl;
    system.WriteData(RESULT);

    fclose(DATA);
    fclose(RESULT);

    return 0;
}
