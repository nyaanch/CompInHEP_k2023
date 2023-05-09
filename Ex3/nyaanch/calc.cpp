#include "calc.h"
#include <iostream>
#include <vector>
#include <array>


int main()
{
    Matrix test;

    double x, y;
    std::cout<<"Enter x: ";
    std::cin>>x;

    std::cout<<"Enter y: ";
    std::cin>>y;

    std::vector<double> xi {34.4806,83.082,63.4611,79.2523,35.2776,91.9403,99.1812,40.9363,93.3598,56.5339};
    std::vector<double> yi {4.4156,56.8751,20.1615,26.5283,67.9138,23.7937,51.3363,16.4646,67.3198,86.6816};

    double distance_r = test.distance(x, y);
    double sigma_x = test.var(xi); 
    double sigma_y = test.var(yi); 
    double sigma_xy = test.covar(xi, yi);
    
    std::array<double, 4> matrix_M = test.M(xi,yi);
    
    double error_e = test.error(x,y,matrix_M);
    double significance_S = test.significance(x,y,matrix_M);
    
    std::ofstream out("test.txt");
     
    if (out.is_open())
    {
        out<<"|\txi\t|";
        for(double i : xi){
            out<<"|\t"<<i<<"\t|";
        }
        out<<std::endl;
        
        out<<"|\tyi\t|";
        for(double i : yi){
            out<<"|\t"<<i<<"\t|";
        }
        out<<std::endl;

        out<<"|\tx = "<<x<<"\t||\ty = "<<y<<"\t|"<<std::endl;
        out<<std::endl<<"Distance: "<<distance_r<<std::endl;
        out<<std::endl<<"Error matrix:";

        for(int i = 0; i<matrix_M.size(); i++){
            if(!(i%2)) out<<std::endl;
            out<<"|\t"<<matrix_M[i]<<"\t|";
        }
        out<<std::endl;

        out<<std::endl<<"Error: "<<error_e<<std::endl;
        out<<std::endl<<"Significance: "<<significance_S<<std::endl;
    }
    out.close();

    return 0;
}