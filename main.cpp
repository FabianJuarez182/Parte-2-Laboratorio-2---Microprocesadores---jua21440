/*
*------------------------------------------
* Parte 2 Laboratorio 2.cpp
* -----------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 - Programacion de Microprocesadores
* Fabian Juárez 21440
*------------------------------------------
* Descripción: Solicitar al usuario ingreso de numero de DPIs que se 
* desean almacenar, creandose estructuras por medio de la cantida que se
* desean almacenar y luego realizar un algoritmo para ordenarlos por el 
* último número.
*------------------------------------------
*/ 
#include <iostream>
using namespace std;
//Se creara el estructure para cada persona que posee un DPI
struct persona{
  string nombre , apellido , Fecha;
  int CUI , UCUI;
};

int main() {
  int DPIs;//Variable para saber la cantidad de DPIs que se desean ingresar
  cout << "Escribe la cantidad de DPIs que desea ingresar: \n"; //Se pide la cantidad de DPIs a ingresar
  cin >> DPIs; // variable en la que se guardara la cantidad de DPIs a ingresar
  int ultimosDPI[DPIs]; //Array de los ultimos dijitos del DPI
  int aux; // El ultimo numero que utilizara para comparar con el que se tiene 
  struct persona numDpis[DPIs]; //array de estructuras de personas
  int posicion=1; //Solo sera para imprimir la posicion en la que se encuentran
  
  //Este ciclo for adquiere los datos ingresados por el usuario para que se logre obtener toda su informacion
  // ademas se guarda el ultimo numero del DPI en el array designado
  for (int i = 0; i < DPIs; i++ ){
              cout << "\n Ingrese el nombre: \n";
       cin >> numDpis[i].nombre;
       cout << "Ingrese el apellido: \n";
       cin >> numDpis[i].apellido ;
       cout << "Ingrese el CUI: \n";
       cin >> numDpis[i].CUI;
       cout << "Ingrese el ultimo numero del CUI: \n";
       cin >> numDpis[i].UCUI;
       cout << "Ingrese la fecha de vencimiento: \n";
       cin >> numDpis[i].Fecha;
       ultimosDPI[i]= numDpis[i].UCUI;
    }
//Este ciclo ordenara el ultimo digito del DPI de manera ascendente 
  for (int i = 0; i <= DPIs; i++ ){
      for (int j = 1; j <= DPIs; j++ ){
            if (ultimosDPI[j-1] > ultimosDPI[j]){
                aux = ultimosDPI[j-1];
                ultimosDPI[j-1] = ultimosDPI[j];
                ultimosDPI[j] = aux;
            }
       }
    }
//Se imprimiran los DPIs de manera ordenada de menor a mayor
    cout<<"\nLos elementos del array ordenados son: \n";
    for(int i=0;i<DPIs;i++)
    {
        for (int j=0; j<DPIs; j++){
            if (ultimosDPI[i] == numDpis[j].UCUI ){
                printf("Posicion ordenada: %d Numero de DPI : %d \n",posicion++,numDpis[j].CUI);
            }
        }
    }
}