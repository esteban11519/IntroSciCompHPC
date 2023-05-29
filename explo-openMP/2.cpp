// Ladino fajardo Esteban
# include <iostream>
# include <omp.h>
# include <vector>
# include <random>

void fill_vector(std::vector<double> &, int &);
void omp_parallel_vector_sum(std::vector<double> &);

int main(int argc, char **argv)
{
  if (argc!=3){
    std::clog<<"size: argv[1]\n";
    std::clog<<"seed: argv[2]\n";
    return 1;
  }
  int size = atoi(argv[1]);
  int seed = atoi(argv[2]);

  std::clog<<"size: "<<size<<std::endl;
  std::clog<<"seed "<<seed<<std::endl;

  // init vector
  std::vector<double> vec(size);

  // fill vector
  fill_vector(vec,seed);
  omp_parallel_vector_sum(vec);  
  return 0;
  
}

void fill_vector(std::vector<double> &vec, int &seed){
    
  int N = vec.size();
  std::mt19937 gen(seed); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<> dis(-1.5, 4.5);
  for (int n = 0; n < N; ++n)
    {
      // double in [-1.5, 4.5). Each call to dis(gen) generates a new random double
         
      vec[n]=dis(gen);
    }
  return;
}


void omp_parallel_vector_sum(std::vector<double> & vec){
  double result=0.0;
  int N = vec.size();
#pragma omp parallel for reduction (+:result)
  for(int ii=0; ii<N; ++ii){
    result += vec[ii];
  }

  std::cout<<"mean: "<<result/N<<std::endl;
  return;
}
