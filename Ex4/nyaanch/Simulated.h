#include "Track.h"

class Simulated : public Track {
  public:
	Simulated();
	~Simulated();

	int particle_id() const;
	int parentParticle_id() const;

	void SetPid(int);
	void SetPPid(int);

  private:
	int p_id;
	int pp_id;
};
