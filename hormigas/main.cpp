#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef struct ciudades{
string dato;
int longitud;
float vista;
float feromona;
};

typedef struct hormiga {
float probabilidad;
float visibilidad;
};

typedef struct ciudades matriz [10][10];

int string_a_entero(string element){ // la transformacion str a int debes modificar el i=0 y el return sacarle el /10

int largo= element.length();
int exp=largo-1;
int numero,total=0;
for (int i=1;i<largo;i++){
    if (element[i]=='0'){numero=0;}
    if (element[i]=='1'){numero=1;}
    if (element[i]=='2'){numero=2;}
    if (element[i]=='3'){numero=3;}
    if (element[i]=='4'){numero=4;}
    if (element[i]=='5'){numero=5;}
    if (element[i]=='6'){numero=6;}
    if (element[i]=='7'){numero=7;}
    if (element[i]=='8'){numero=8;}
    if (element[i]=='9'){numero=9;}
    total=(numero*pow(10,exp))+total;
    exp--;
}
return total/10;}

string lectura_archivo(){

    char linea[99999];
    int largo=0;
    ifstream lectura("informacion.txt");
    if(lectura.is_open())
    {
        while(!lectura.eof())
        {
            lectura.get(linea[largo]);
            largo++;
        }
        lectura.close();
    }
return linea;
}

void slipt (string linea, string arreglo [], int *a){
    int c=0,largo=0,j=0,d;
    string palabra,texto;
    largo=linea.length();
    for (int i=0 ; i<largo;i++){// recorro el string que contiene la informacion del archivo

            if(linea[i]!='#'){
                palabra=palabra+linea[i];}  // concatenando cada una palabra hasta que encuentre un #
            else{

                texto=palabra;
                arreglo[c]=palabra;
                palabra='\0';
                c++;}}
    *a=c;}

void traspaso (string datos[],matriz a, int largo){
int b=0;
for (int i=0; i<6;i++){
    for (int j=0;j<6;j++){
        if (b<largo){
            a[i][j].dato=datos[b];
            a[i][j].feromona=0.1;
            a[i][j].longitud=(string_a_entero(datos[b]));
            b++;
        }

    }}

}

void mostrar (matriz a){  //muestra todo
for (int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        cout<<a[i][j].dato<<" ";
    }cout<<endl;}}

void distancia(matriz a){
int num;
for (int i=1;i<6;i++){
    for(int j=1;j<6;j++){
        a[i][j].longitud=string_a_entero(a[i][j].dato);


    }}
}

void vista (matriz a){
for (int i=1;i<6;i++){
    for (int j=1;j<6;j++){
    if(a[i][j].longitud!=0)
        a[i][j].vista=(1.0/a[i][j].longitud);
    else
        a[i][j].vista=0;
    }
}
}

void mostrar2 (matriz a){  // solo la utilize para verificar que tengo numero entero
for (int i=1;i<6;i++){
    for(int j=1;j<6;j++){
        cout<<a[i][j].vista<" ";
    }cout<<endl;}}

int main(){
matriz informacion;
int largo1,c;
string datos[1000];
slipt(lectura_archivo(),datos, &largo1);
traspaso(datos,informacion,largo1);
vista(informacion);
mostrar2(informacion);
return 0;
}
