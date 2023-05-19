#include "Track.h"
#include <cmath>

#define PI 3.14159

Track::Track(){}
Track::~Track(){}

void Track::SetPtEtaPhiM(double pt,double eta,double phi,double m)
{
    px = pt*std::cos(phi);
    py = pt*std::sin(phi);

    double cosT = std::tanh(eta);
    pz = pt*cosT;

    e = std::sqrt(px * px + py * py + pz * pz + m * m);
    p = std::sqrt(px * px + py * py + pz * pz);
}


double Track::Px() {return px;}
double Track::Py() {return py;}
double Track::Pz() {return pz;}

double Track::Pt() {return sqrt(pow(px,2) + pow(py,2));}
double Track::P()  {return sqrt(pow(px,2) + pow(py,2) + pow(pz,2));}

double Track::E() {return e;}
double Track::M() {return sqrt(pow(e,2) - pow(p,2));}

double Track::Eta() 
{
    return ((p > 0) ? std::atanh(pz / p) : 0);
}

double Track::Phi() 
{
    return std::atan2(py, px);
}