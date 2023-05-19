#include "Simulated.h"

#include <iostream>

int main()
{
  Simulated particle;

  int PID, PPID;

  std::cout << "Enter PID: ";
  std::cin >> PID;

  std::cout << "Enter PPID: ";
  std::cin >> PPID;

  int input;
  double PT, ETA, PHI, M;

  std::cout << "To enter values, press 1. To use default values, press 0: ";
  std::cin >> input;

  if(!input){
    PT = 20;
    ETA = 0;
    PHI = 0;
    M = 125;
  } 
  else
  {
    std::cout << "Enter PT: ";
    std::cin >> PT;
    std::cout << "Enter ETA: ";
    std::cin >> ETA;
    std::cout << "Enter PHI: ";
    std::cin >> PHI;
    std::cout << "Enter M: ";
    std::cin >> M;
  }

  particle.SetPtEtaPhiM(PT,ETA,PHI,M);
  particle.SetPid(PID);
  particle.SetPPid(PPID);

  std::cout << std::endl;
  std::cout << "Particle ID: " << particle.particle_id() << "Parent Particle ID: " << particle.parentParticle_id()
            << "pT: " << particle.Pt() << "eta: " << particle.Eta()
            << "phi: " << particle.Phi() << "mass: " << particle.M()
            << std::endl;

  return 0;
}
