#include <iostream>
#include <random>
#include <string>

using namespace std;

int main (int argc, char **arg)
{
    unsigned short int low,high,N,n;
    string executable;
    string results;
    
    executable=arg[1];
    results=arg[2];
    low=atoi(arg[3]);
    high=atoi(arg[4]);
    N=atoi(arg[5]);
    n=atoi(arg[6]);

    random_device rd; // Semilla de forma aleatoria
    mt19937 gen(rd()); // 32-bit Mersenne Twister by Matsumoto and Nishimura, 1998
    // Se transforma lo randow a unsigned int
    // Se regeran números aleatorios de  uniform_int_distribution <> name(a,b), intervalo [a,b] 
    uniform_int_distribution <> distrib(low,high);
    
    system("gmake");
    system(("echo nxm modo_1 modo_2 modo_3 modo_4 >"+results).c_str());

    for(unsigned short int i=0;i<N;i++){
        unsigned short int aux_n=distrib(gen);
        unsigned short int aux_m=distrib(gen);
        for (unsigned short int j = 0; j < n; j++)
        {   
            system((executable+" "+to_string(aux_n)+" "+to_string(aux_m)+">>"+results).c_str());
        };
    };

}