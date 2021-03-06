//
//  Center.h
//  
//
//  Created by Tao Han on 5/2/14.
//
//

#ifndef ____Center__
#define ____Center__


#include "Properties.h"
#include "InnerSolvPatch.h"

#include <vector>

using namespace std;

class Center {
public:
    Center(double dt, SolvProp solvProp, const InnerSolvPatch &Yin, const InnerSolvPatch &Yang);
    ~Center() {};
    
    void interpPsi(const vector<vector<vector<double> > > &psi_Yin, const vector<vector<vector<double> > > &psi_Yang); // interpolate psi in neighboring cells from Yin and Yang grids
    void interpMu(const vector<vector<vector<double> > > &mu_Yin, const vector<vector<vector<double> > > &mu_Yang); // interpolate mu in neighboring cells from Yin and Yang grids
    
    void calcMu_dw(); // calculate mu at the center from double well potential
    void calcMu_sd(); // calculate mu at the center from simple diffusion model, where mu = psi
    void updatePsi(); // update psi at the center from mu
    
    void initPsi(double val) {psi = val;};
    double psiAtCenter() const {return psi;};
    double muAtCenter() const {return mu;};
    
private:
    SolvProp props; // inner solvent properties
    double dt; // time step
    double dr; // step in radius direction
    double psi; // psi at the center
    double mu; // mu at the center
    vector<vector<int> > nbs_Yin, nbs_Yang; // positions of neighbors of center in Yin-Yang grids, here we use the first order interpolation, assuming all neighbors fall exactly on the cells in Yin-Yang grids
    vector<double> psi_Yin_nbs, psi_Yang_nbs, mu_Yin_nbs, mu_Yang_nbs; // storing psi and mu in neighboring cells
};


#endif /* defined(____Center__) */
