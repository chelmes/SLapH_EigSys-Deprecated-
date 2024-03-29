#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

//Class handling parameter passing to eigensystem calculation
class IO {
  private:
    //Absolute paths to configurations and destination of the eigensystems
    std::string config_path;
    std::string result_path;

    //controlling the extent of the 4 dimensional configuration
    //LT = temporal, LX = nx, and so on...
    int LT;
    int LX;
    int LY;
    int LZ;

    //various helper variables
    //number of colours
    int NCOL;
    //number of lattice directions
    int NDIR;
    //3d volume in terms of colours and lattice directions
    int V3;
    //size of 4d lattice in terms of doubles
    int V4_LIME;
    //same for one timeslice
    int V_TS;
    //number of desired eigenvalues, also used for setup of eigensystem
    int NEV;
    int MAT_ENTRIES;


    //parameters for Smearing and Chebyshev acceleration
    //weight for 2d staples
    double alpha_1;
    //weight for outer 3d staples
    double alpha_2;
    //number of iterations
    int iter;

    //Chebyshev acceleration:
    //Lower cutoff for spectrum
    double LAM_C;
    //High end cutoff for spectrum
    double LAM_L;

  public:
    //set values according to input file
    void set_values(const char*);
    //print summary of layout
    void print_summary();
    //get integer valued variable
    int get_int(std::string);
    //get floating point valued variable
    double get_float(std::string);
    //get path to configs or destination
    std::string get_path(std::string);
};

