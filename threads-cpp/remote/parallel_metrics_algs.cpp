#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <execution>
#include <chrono>
#include <tbb/task_scheduler_init.h>

template<typename Func>
void time_function(Func func, int); // Calculate wall clock time
bool are_command_line_arguments_valid(int &, char ** ,int &, int &, int &, int &); // arguments verification
double mean(std::vector<double> &); // Calculate mean
double standard_deviation(std::vector<double> &, double &); // Calculate standard deviation

int main(int argc, char **argv){
  
  // Variables
  int ARRAY_SIZE,THREADS_NUMBER,EXECUTION_POLICY,SAMPLES;
  ARRAY_SIZE=200000000;
  SAMPLES=7;
  
  std::clog<<"Please in command line insert the follow arguments: \n"<<
    "ARRAY_SIZE: integer [-2147483648,2147483647], default is 200 000 000 \n"<<
    "THREADS_NUMBER: [1, $(nproc)+1] \n"<<
    "EXECUTION_POLICY: 0 for seq, 1 for par and 2 for par_unseq \n"<<
    "SAMPLES: times to run, default is 7 (the results are a little different) \n"<<std::endl;

  // Parameters verification
  if(!are_command_line_arguments_valid(argc, argv,ARRAY_SIZE, THREADS_NUMBER,
			 EXECUTION_POLICY, SAMPLES)){
    std::cerr<<"Please insert valid arguments"<<std::endl;
    return 1;
  }
    
  // code from: https://iluvatar.bitbucket.io/IntroSciCompHPC/#orgec90905
  std::vector<double> myArray(ARRAY_SIZE);
  std::iota(myArray.begin(), myArray.end(), 0); // fill array with 0, 1, 2, ..., ARRAY_SIZE-1

  // Choose execution policy
  switch(EXECUTION_POLICY){
  case 0:
    {
      std::clog<<"seq execution policy"<<std::endl;
      auto seq_policy = [&myArray](){return std::reduce(std::execution::seq, myArray.begin(), myArray.end());};
      time_function(seq_policy, SAMPLES);
    }
    
    break;

  case 1:
    {
      tbb::task_scheduler_init init(THREADS_NUMBER);
      std::clog<<"par execution policy"<<std::endl;
      auto par_policy = [&myArray](){return std::reduce(std::execution::par, myArray.begin(), myArray.end());};
      time_function(par_policy, SAMPLES);
    }
    
    break;

  case 2:
    {
      tbb::task_scheduler_init init(THREADS_NUMBER);
      std::clog<<"par_unseq execution policy"<<std::endl;
      auto par_unseq_policy = [&myArray](){return std::reduce(std::execution::par_unseq, myArray.begin(), myArray.end());};
      time_function(par_unseq_policy, SAMPLES);
    }
    break;

  default:
    std::cerr<<"Please insert a policy execution option between 0 and 2"<<std::endl;
    break;
  }
  
  return 0;
}


//Adapted from Professor's function
template<typename Func>
void time_function(Func func, int samples) {
  vector<double> vec_chrono_times;
  for(int i=0; i<samples ; i++){
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    vec_chrono_times.push_back(duration_ms/1000.0);
  }

  // mean and standard deviation
  auto aux_mean=mean(vec_chrono_times);
  auto aux_standard_deviation=standard_deviation(vec_chrono_times,aux_mean);

  // Print results
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  std::cout << aux_mean << " " << aux_standard_deviation << std::endl; // [s]
  return;
}

bool are_command_line_arguments_valid(int & argc, char **argv,int ARRAY_SIZE, int & THREADS_NUMBER,
			 int & EXECUTION_POLICY, int & SAMPLES){
  if(argc==3){
    THREADS_NUMBER=atoi(argv[1]);
    EXECUTION_POLICY=atoi(argv[2]);
    std::clog<<"ARRAY_SIZE = "<<ARRAY_SIZE <<std::endl;
    std::clog<<"THREADS_NUMBER = "<<THREADS_NUMBER <<std::endl;
    std::clog<<"EXECUTION_POLICY = "<<EXECUTION_POLICY <<"\n"<<std::endl;
    std::clog<<"SAMPLES = "<<SAMPLES <<"\n"<<std::endl;
    return true;
  }
  else if(argc==4){
    ARRAY_SIZE = atoi(argv[1]);
    THREADS_NUMBER=atoi(argv[2]);
    EXECUTION_POLICY=atoi(argv[3]);
    std::clog<<"ARRAY_SIZE = "<< ARRAY_SIZE <<std::endl;
    std::clog<<"THREADS_NUMBER = "<<THREADS_NUMBER <<std::endl;
    std::clog<<"EXECUTION_POLICY = "<<EXECUTION_POLICY<<"\n" <<std::endl;
    std::clog<<"SAMPLES = "<<SAMPLES <<"\n"<<std::endl;
    return true;
  }
  else if(argc==5){
    ARRAY_SIZE = atoi(argv[1]);
    THREADS_NUMBER=atoi(argv[2]);
    EXECUTION_POLICY=atoi(argv[3]);
    SAMPLES = atoi(argv[4]);
    std::clog<<"ARRAY_SIZE = "<< ARRAY_SIZE <<std::endl;
    std::clog<<"THREADS_NUMBER = "<<THREADS_NUMBER <<std::endl;
    std::clog<<"EXECUTION_POLICY = "<<EXECUTION_POLICY<<"\n" <<std::endl;
    std::clog<<"SAMPLES = "<<SAMPLES <<"\n"<<std::endl;
    return true;
  }
  else{
    return false;
  }

  return false;
}

double mean(std::vector<double> & vec){
  // Using accumulate but in parallel form
  return std::reduce(std::execution::par,vec.begin(),vec.end())/((double)vec.size());
}

double standard_deviation(std::vector<double> &vec, double &mymean){
  double aux_standard_deviation=0;
  for(auto v : vec){
    aux_standard_deviation+=(v-mymean)*(v-mymean);
  }
  aux_standard_deviation = aux_standard_deviation/(vec.size()-1); 

  return std::sqrt(aux_standard_deviation);  
}


// Bibliography
// [1] «task_scheduler_init Class». https://www.cism.ucl.ac.be/Services/Formations/ICS/ics_2013.0.028/composer_xe_2013/Documentation/en_US/tbb/help/reference/task_scheduler/task_scheduler_init_cls.htm (accedido 7 de mayo de 2023).

