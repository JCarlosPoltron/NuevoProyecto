#include <iostream>
#include <stdlib.h>
using namespace std;

float** generaMatriz(int m,int n);
void liberaMatriz(float** X, int m);
void leeMatriz(float** X, int m, int n);
void muestraMatriz(float** X, int m, int n);
void inicializaMatriz(float** X, int m, int n);
void inicializaIdentidad(float** X, int m, int n);
float** generaTranspuesta(float** X, int m, int n);
float** sumaMatrices(float** X, int m1, int n1,float** Y, int m2, int n2);
float** restaMatrices(float** X, int m1, int n1,float** Y, int m2, int n2);

int main(void){
    int m1,n1,m2,n2;
    float **A, **B, **C, **D;

    cout << "Dame m de A ";
    cin>>m1;
    cout << "Dame n de A ";
    cin>>n1;
    cout << "Dame m de B ";
    cin>>m2;
    cout << "Dame n de B ";
    cin>>n2;

    if(m1==m2 && n1==n2){

        A = generaMatriz(m1,n1);
        B = generaMatriz(m2,n2);

        cout<<"A"<<endl;
        leeMatriz(A,m1,n1);
        cout<<endl<<"B"<<endl;
        leeMatriz(B,m2,n2);

        C = sumaMatrices(A,m1,n1,B,m2,n2);
        D = restaMatrices(A,m1,n1,B,m2,n2);

        system("cls");
        cout<<"A"<<endl;
        muestraMatriz(A,m1,n1);
        cout<<endl<<"B"<<endl;
        muestraMatriz(B,m1,n1);
        cout<<endl<<"C"<<endl;
        muestraMatriz(C,m1,n1);
        cout<<endl<<"D"<<endl;
        muestraMatriz(D,m2,n2);

        liberaMatriz(A,m1);
        liberaMatriz(B,m2);
        liberaMatriz(C,m1);
        liberaMatriz(D,m2);
    }
    else{
        cout<<"Error! No pueden sumarse... =("<<endl;
    }

    return 0;
}
float** generaMatriz(int m,int n){
    int i;
    float **M=NULL;
    if(m>0&&n>0){
        M = new float*[m];
        for(i=0;i<m;i++)
            M[i] = new float[n];
    }
    return M;
}
void liberaMatriz(float** X, int m){
    int i;
    if(X!=NULL){
        for(i=0;i<m;i++)
            delete[] X[i];
        delete[] X;
    }
}
void leeMatriz(float** X, int m, int n){
    int i,j;
    if(X!=NULL){
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
                cout<<"Ingresa ["<<i<<"]["<<j<<"] ";
                cin>>X[i][j];
            }
    }
}
void muestraMatriz(float** X, int m, int n){
    int i,j;
    if(X!=NULL){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                cout<<X[i][j]<<"\t";
            cout<<endl;
        }
    }
}
void inicializaMatriz(float** X, int m, int n){
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            X[i][j] = 0.0;
}
void inicializaIdentidad(float** X, int m, int n){
    int i,j;
    if(m==n){
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(i==j)
                X[i][j] = 1;
            else
                X[i][j] = 0;

    }
}
float** generaTranspuesta(float** X, int m, int n){
    int i, j;
    float **XT;
    if(m>0&&n>0){
        XT = generaMatriz(n,m);
    }
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            XT[j][i] = X[i][j];

    return XT;
}
float** sumaMatrices(float** X, int m1, int n1,float** Y, int m2, int n2){
    int i,j;
    float **Z=NULL;
    cout<<" m1"<<m1<<" n1"<<n1<<" m2"<<m2<<" n2"<<n2<<endl;
    if(m1==m2 && n1==n2){
        Z = generaMatriz(m1,n2);
        for(i=0;i<m1;i++)
            for(j=0;j<n2;j++)
                Z[i][j] = X[i][j] + Y[i][j];
    }
    return Z;
}
float** restaMatrices(float** X, int m1, int n1,float** Y, int m2, int n2){
    int i,j;
    float **Z=NULL;
    if(m1==m2 && n1==n2){
        Z = generaMatriz(m1,n2);
        for(i=0;i<m1;i++)
            for(j=0;j<n2;j++)
                Z[i][j] = X[i][j] - Y[i][j];
    }
    return Z;
}

















