#include <random>
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <mpi.h>

// adapted from: https://iluvatar.bitbucket.io/IntroSciCompHPC/#orgcb2762e
template <typename T>
void calculate_and_print(T, T, int, int); 
int N_c_serial(int, int);

int main(int argc, char **argv){
  // Command line verification
  if(argc!=2){
    std::cerr<<"Please insert in  command line the samples\n";
    return 1;
  }  
  MPI_Init(&argc,&argv);
  int N;       			// samples 
  int nLocal; 			// n local (samples by each process)
  int pid;			// process id
  int np;			// number of process
  int count;			// Number of samples inside circle
  
  N=std::stoi(argv[1]);
  
  MPI_Comm_size(MPI_COMM_WORLD,&np);
  MPI_Comm_rank(MPI_COMM_WORLD,&pid);

  nLocal=N/np;

  if((N%nLocal)!=0 && np>1 && pid==(np-1)){
    // Last process has remaining samples when (N%nLocal)!=0 
    nLocal+=N%nLocal;  
  }
  // Verification of correct nLocal when (N%nLocal)!=0
  //printf("Process %d of %d has %d samples \n",pid, np, nLocal);
  
  auto start = std::chrono::high_resolution_clock::now();    
  count=N_c_serial(nLocal,pid);
  if(pid==0){
    // Receive and accumulate all counts
    int buffer;
    for(int n_pid=1;n_pid<np;n_pid++){
      MPI_Recv(&buffer,1,MPI_INT,n_pid,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      count+=buffer;
    }
    auto end = std::chrono::high_resolution_clock::now();

    calculate_and_print(start,end,count,N);
  }
  else{
    MPI_Send(&count,1,MPI_INT,0,1,MPI_COMM_WORLD);  
  }
  
  MPI_Finalize();
  
  return 0;
}

int N_c_serial(int N, int seed){
  int count = 0;

  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(-1.0,1.0);

  for(int ii=0; ii<N; ++ii){
    double rx = dis(gen);
    double ry = dis(gen);

    if((rx*rx+ry*ry)<1)
      count++;
  }
  
  return count;
}

template <typename T>
void calculate_and_print(T start, T end, int count, int N){
  auto duration_mus = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  double pi_aprox=count*4.0/N;
  double rel_dif=(pi_aprox-M_PI)*100.0/M_PI;

  // print
  std::clog.precision(15);
  std::clog.setf(std::ios::scientific);
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  
  std::clog << duration_mus/1000000.0 << "\n"; //[s]
  std::cout << N <<" "<< pi_aprox << " " << rel_dif << std::endl;
  return;
}
