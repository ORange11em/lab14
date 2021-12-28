#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[],int N,double b[]){
    for (int i=0; i < N ;i++){
        b[0]+=a[i];
    }
    b[0]/=N;

    double sd;
    for(int j = 0; j < N; ++j) {
    sd += pow(a[j] - b[0], 2);
    }
    b[1] = sqrt(sd/ N);  

    double gm=1;
    for (int o = 0; o < N; o++){
        gm = gm * a[o];
        b[2] = pow(gm, (double)1 / N);
    }

    double hg;
    for(int k=0;k < N ; ++k){
        hg += (1/a[k]);
    }
    b[3] = N/hg;

    for(int u = 0; u < N; ++u) {
        if (a[u]>b[4]){
            b[4] =a[u];
        }
        if (a[u]<b[4]){
            b[5] =a[u];
        }
    }
}