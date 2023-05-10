#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <execution>
#include <chrono>
#include <tbb/task_scheduler_init.h>

template<typename Func>
void time_function(Func func);


int main(int argc, char **argv){
  
  // Variables
  int ARRAY_SIZE,THREADS_NUMBER,PARALLEL_EXECUTION_POLICY;
  ARRAY_SIZE=200000000;
  
  std::clog<<"Please in command line insert the follow parameters: \n"<<
    "ARRAY_SIZE: integer [-2147483648,2147483647], 200 000 000 is default \n"<<
    "THREADS_NUMBER: [1, $(nproc)+1] \n"<<
    "PARALLEL_EXECUTION_POLICY: 0 to seq, 1 to par and 2 to par_unseq \n"<<std::endl;

  // Parameters verification
  if(argc==3){
    THREADS_NUMBER=atoi(argv[1]);
    PARALLEL_EXECUTION_POLICY=atoi(argv[2]);
    std::clog<<"ARRAY_SIZE = 200 000 000"<<std::endl;
    std::clog<<"THREADS_NUMBER = "<<THREADS_NUMBER <<std::endl;
    std::clog<<"PARALLEL_EXECUTION_POLICY = "<<PARALLEL_EXECUTION_POLICY <<"\n"<<std::endl;

  }
  else if(argc==4){
    ARRAY_SIZE = atoi(argv[1]);
    THREADS_NUMBER=atoi(argv[2]);
    PARALLEL_EXECUTION_POLICY=atoi(argv[3]);
    std::clog<<"ARRAY_SIZE = "<< ARRAY_SIZE <<std::endl;
    std::clog<<"THREADS_NUMBER = "<<THREADS_NUMBER <<std::endl;
    std::clog<<"PARALLEL_EXECUTION_POLICY = "<<PARALLEL_EXECUTION_POLICY<<"\n" <<std::endl;

  }
  else{
    std::cerr<<"Please insert parameters"<<std::endl;
    return 1;
  }

  // code from: https://iluvatar.bitbucket.io/IntroSciCompHPC/#orgec90905
  std::vector<double> myArray(ARRAY_SIZE);
  std::iota(myArray.begin(), myArray.end(), 0); // fill array with 0, 1, 2, ..., ARRAY_SIZE-1

  switch(PARALLEL_EXECUTION_POLICY){
  case 0:
    {
      std::clog<<"seq execution policy"<<std::endl;
      auto seq_policy = [&myArray](){return std::reduce(std::execution::seq, myArray.begin(), myArray.end());};
      time_function(seq_policy);
    }
    
    break;

  case 1:
    {
      tbb::task_scheduler_init init(THREADS_NUMBER);
      std::clog<<"par execution policy"<<std::endl;
      auto par_policy = [&myArray](){return std::reduce(std::execution::par, myArray.begin(), myArray.end());};
      time_function(par_policy);
    }
    
    break;

  case 2:
    {
      tbb::task_scheduler_init init(THREADS_NUMBER);
      std::clog<<"par_unseq execution policy"<<std::endl;
      auto par_unseq_policy = [&myArray](){return std::reduce(std::execution::par_unseq, myArray.begin(), myArray.end());};
      time_function(par_unseq_policy);
    }
    break;

  default:
    std::cerr<<"Please insert a policy execution option between 0 and 2"<<std::endl;
    break;
  }
  
  
  return 0;
}

// Professor's function
template<typename Func>
double time_function(Func func) {
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << duration_ms/1000.0 << std::endl; // [s]
}

// Bibliography
// [1] «task_scheduler_init Class». https://www.cism.ucl.ac.be/Services/Formations/ICS/ics_2013.0.028/composer_xe_2013/Documentation/en_US/tbb/help/reference/task_scheduler/task_scheduler_init_cls.htm (accedido 7 de mayo de 2023).

