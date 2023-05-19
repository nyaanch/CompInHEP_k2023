#ifndef TRACK_H
#define TRACK_H

class Track {
    public:
		Track();
		~Track();

        double Px();
        double Py();
        double Pz();

        double Pt();
        double P();

        double E();
		double M();

        double Eta();
        double Phi();


		void SetPtEtaPhiM(double,double,double,double);

    protected:
		double px,py,pz,e,p;
};
#endif
