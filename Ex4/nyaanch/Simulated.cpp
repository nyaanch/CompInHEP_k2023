#include "Simulated.h"

Simulated::Simulated(){}
Simulated::~Simulated(){}

int Simulated::particle_id() const { return p_id; }
int Simulated::parentParticle_id() const { return pp_id;}

void Simulated::SetPid(int id){
  p_id = id;
}

void Simulated::SetPPid(int id){
  pp_id = id;
}
