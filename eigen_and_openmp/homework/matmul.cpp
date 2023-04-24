// Libraries
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <vector>
#include <numeric>
#include <cmath>

// Functions
void fill(std::vector<double> & mat){
  for (auto & val : mat){

    val = -1.0 + 2.0*drand48();	// Range number between -1 and 1
  }
  return;
}

double multiply_simple(int size, long int seed){

  // create and fill matriz
  srand48(seed); 			// Seed for randow numbers

  // Matrix 1d
  std::vector<double> A(size*size), B(size*size), C(size*size);
  fill(A); fill(B);

  // Start time measurement
  auto start = std::chrono::steady_clock::now();
  
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k) {
	C[i*size+j] += A[i*size+k]*B[k*size+j];
      }
    }
  }
  
  // End time measurement
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  
  return elapsed_seconds.count();
  
}


double multiply_eigen(int size, unsigned int seed){
  srand(seed); 			// Seed
  // Create matrices
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);
  auto start = std::chrono::steady_clock::now();

  auto C{A*B};
  double tmp = C(0,0);

  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  return elapsed_seconds.count();
}


double mean(std::vector<double> & vec){
  // Calculate mean of vector
  // https://www.phind.com
  // https://en.cppreference.com/w/cpp/algorithm/accumulate
  // Was tested
  return std::accumulate(vec.begin(),vec.end(),0.0)/vec.size();
  
}

double standard_deviation(std::vector<double> &vec, double &mymean){
  // Calculate standard_deviation
  // https://en.cppreference.com/w/cpp/numeric/math/sqrt
  // Was tested
  
  double aux_standard_deviation=0;

  for(auto v : vec){
    aux_standard_deviation+=(v-mymean)*(v-mymean);
  }

  aux_standard_deviation = aux_standard_deviation/(vec.size()-1); 
  
  return std::sqrt(aux_standard_deviation);
  
}


int main(int argc, char **argv){

  if (argc != 3){
    std::cout<<"Please insert the N and samples number"<<std::endl;
    return 1;
  }
  double mean_eigen;		// Mean to eigen multiplication
  double sigma_eigen;		// Standard deviation to eigen multiplication 

  double mean_simple;		// Mean to simple multiplication
  double sigma_simple;		// Standard deviation to eigen multiplication
  
  std::vector<double> vec_wall_clock_eigen; // Wall clock time in eigen multiplication
  std::vector<double> vec_wall_clock_simple; // Wall clock time in simple multiplication
  
  
  for (int i=0; i < atoi(argv[2]); i++) {
    vec_wall_clock_eigen.push_back(multiply_eigen(atoi(argv[1]), i));
    vec_wall_clock_simple.push_back(multiply_simple(atoi(argv[1]), i));    
  }

  // Statistics operations  
  mean_eigen = mean(vec_wall_clock_eigen);
  mean_simple = mean(vec_wall_clock_simple);

  sigma_eigen = standard_deviation(vec_wall_clock_eigen, mean_eigen);
  sigma_simple = standard_deviation(vec_wall_clock_simple, mean_simple);

  //  Print results
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  std::cout << mean_eigen << " , " << sigma_eigen << " , " << mean_simple
       << " , " << sigma_simple << std::endl; 
  
  return 0;
}
