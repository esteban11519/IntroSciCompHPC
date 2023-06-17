//Diana Muñoz Valencia
//Samuel Miranda Rocha
// Andres Sebastian Prieto Alarcon
// Esteban Ladino Fajardo
#include <random>
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <mpi.h>
#include <vector>


void diagonal(int M, int N,int pid,int  np);

int main(int argc, char **argv){
  // Command line verification
  // if(argc!=2){
  //   std::cerr<<"Please insert in  command line the samples\n";
  //   return 1;
  // }  
  MPI_Init(&argc,&argv);
  int M;       			// filas
  int N;			// Columnas
  int pid;			// process id
  int np;			// number of process
  
  M=std::stoi(argv[1]);
  N=std::stoi(argv[2]);
  
  MPI_Comm_size(MPI_COMM_WORLD,&np);
  MPI_Comm_rank(MPI_COMM_WORLD,&pid);

  diagonal(M, N, reps, pid, np);
  
  MPI_Finalize();
  
  return 0;
}



void diagonal(int M, int N, int pid,int  np){

  // M: Número de filas
  // N: Número de columnas
  
  int Mlocal = M/np;
  std::vector<int> matriz_local(Mlocal*N,0);

  imin_global = pid*Mlocal;
  imax_global = imin_global+Mlocal;

  for (int ii=0; ii<N; ii++){
    matriz_local[ii*N+ii]=imin_global+ii+1;
  }
    
  
  if(pid==0){
    std::vector<int> var(Mlocal*N,0);

    for(int i=0; i<np<i ++){
      MPI_Recv(&var[0],n,MPI_INT,i,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

      for(int ii=0; ii<Mlocal*N; ii++){
	std::cout<<var[ii];
	if((ii+1)%N==0){
	  std::endl;
	}
	else{
	  std::cout<<" ";
	}                 
      }
      
      
    }

       MPI_Reduce(&localSum, &globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Output the global sum on process 0
    if (rank == 0) {
        cout << "Global sum: " << globalSum << endl;
    }
    
  }
    
    MPI_Send(&buffer[0],n,MPI_INT,0,1,MPI_COMM_WORLD);  
  }
}
