#include <iostream>
#include <chrono>
using namespace std;

unsigned int *crear_arreglo_entero(unsigned int n){
    return new unsigned int[n];
};

void liberacion_arreglo_entero(unsigned int *x){
    delete []x;
    return;
};

unsigned int **crear_matriz_entera(unsigned short int &n,unsigned short int &m)
{
    unsigned int **X=new unsigned int*[n];
    for(unsigned short int i=0;i<n;i++)
    {
        X[i]=new unsigned int[m];
    };
    return X;
};

void liberacion_matriz_entera(unsigned int **X,unsigned short int &n){
    for(unsigned short int i=0;i<n;i++){
        delete[] X[i];
    };
    delete []X;
    return;
};

bool modo_1(unsigned short int &n,unsigned short int &m){
    unsigned int **arreglo_modo_1=crear_matriz_entera(n,m);
    // cout<<"Modo 1"<<endl;
    for (unsigned short int i = 0; i < n; i++){
        for (unsigned short int j = 0; j < m; j++){
            arreglo_modo_1[i][j]=(unsigned int)(j+i*m);
            // cout<<arreglo_modo_1[i][j]<<" ";
        };
        // cout<<"\n";
    };
    liberacion_matriz_entera(arreglo_modo_1,n);
    return true;
};

bool modo_2(unsigned short int &n,unsigned short int &m){
    
    unsigned int *arreglo_modo_2=crear_arreglo_entero((unsigned int)(n*m));

    // cout<<"Modo 2"<<endl;
    for (unsigned short int i = 0; i < n; i++){
        for (unsigned short int j = 0; j < m; j++){
            arreglo_modo_2[(unsigned int)(j+i*m)]=(unsigned int)(j+i*m);
            // cout<<arreglo_modo_2[j+i*m]<<" ";

        };
        // cout<<"\n";
    };
    liberacion_arreglo_entero(arreglo_modo_2);
    return true;
};

bool modo_3(unsigned short int &n,unsigned short int &m){
        
    unsigned int *arreglo_modo_3=crear_arreglo_entero((unsigned int)(n*m));

    // cout<<"Modo 3"<<endl;
    for (unsigned short int i = 0; i < n; i++){
        for (unsigned short int j = 0; j < m; j++){
            arreglo_modo_3[(unsigned int)(i+j*n)]=(unsigned int)(i+j*n);
        };
    };

    
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout<<arreglo_modo_3[j+i*m]<<" ";
    //     };
    //     cout<<"\n";
    // };
    liberacion_arreglo_entero(arreglo_modo_3);
    return true;
};

bool modo_4(unsigned short int &n,unsigned short int &m){
    
    unsigned int *arreglo_modo_4=crear_arreglo_entero((unsigned int)(n*m));


    // cout<<"Modo 4"<<endl;
    for (unsigned int i = 0; i < (unsigned int)(n*m); i++){    
        arreglo_modo_4[i]=i;
        // cout<<arreglo_modo_4[i]<<" ";

        // if((i+1)%m==0){
        //     cout<<"\n";
        // };            
    };
    liberacion_arreglo_entero(arreglo_modo_4);
    return true;
};

template <typename T>

void chrono_duration(T &start, T &end){
    cout<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ";
};

int main(int argc,char** argv){

    unsigned short int n,m; // Filas y columnas
    n=atoi(argv[1]);
    m=atoi(argv[2]);
    
    auto start = chrono::steady_clock::now();
    modo_1(n,m);
    auto end = chrono::steady_clock::now();
    chrono_duration(start,end);
    
    start = chrono::steady_clock::now();
    modo_2(n,m);
    end = chrono::steady_clock::now();
    chrono_duration(start,end);
    
    start = chrono::steady_clock::now();
    modo_3(n,m);
    end = chrono::steady_clock::now();
    chrono_duration(start,end);
    
    start = chrono::steady_clock::now();
    modo_4(n,m);
    end = chrono::steady_clock::now();
    chrono_duration(start,end);
    
    return 0;

}