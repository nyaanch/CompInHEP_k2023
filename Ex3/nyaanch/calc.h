#include <cmath>
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <fstream>

class Matrix{

  private:
    double x,y;

    std::vector<double> xi;
    std::vector<double> yi;

  public:
    double distance(double x, double y){ 

        double r = sqrt(pow(x,2) + pow(y,2));

        return r;
    };

    double var(std::vector<double>& measurement){

        double var;
        double mu = accumulate(measurement.begin(), measurement.end(), static_cast<double>(0))/measurement.size();
        
        for(int i = 0; i < measurement.size(); i++){
            var += pow(measurement[i]-mu, 2); 
        }
        var = var/measurement.size();

        return var;
    };

    double covar(std::vector<double>& xi, std::vector<double>& yi){

        double covar;
        double muX = accumulate(xi.begin(), xi.end(), static_cast<double>(0))/xi.size();
        double muY = accumulate(yi.begin(), yi.end(), static_cast<double>(0))/yi.size();

        for(int i = 0; i<xi.size(); i++){
            covar += (xi[i]-muX) * (yi[i]-muY); 
        }
        covar = covar/xi.size();

        return covar;
    };

    std::array<double, 4> M(std::vector<double>& xi, std::vector<double>& yi){

        std::array<double, 4> mtrx;

        mtrx[0] = var(xi);
        mtrx[1] = covar(xi, yi);
        mtrx[2] = covar(xi, yi);
        mtrx[3] = var(yi);

        return mtrx;
    };

    double error(double x, double y, std::array<double, 4>& M){

        double r = distance(x,y);    
        double e = sqrt(pow(x/r, 2)*pow(M[0], 2)  + pow(y/r, 2)*pow(M[3], 2) + 2*x*y/pow(r, 2)*M[1]);

        return e;
    };

    double significance(double x, double y, std::array<double, 4>& M){

      double r = distance(x,y);
      double e = error(x,y,M);
      double S = r/e;

      return S;
    };
  
  };