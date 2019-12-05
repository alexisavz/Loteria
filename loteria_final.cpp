#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generarTabla(int cMatTablero[4][4]);
void mostrarTabla(int cMatTablero[4][4]);
void vertical(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]);
void horizontal(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]);
void diagonal(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]);
void cuatroEsquinas(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]);
void posito(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]);
void cuadroExterior(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]);
void dezplieganumeros(int matrizA[][4], int matrizB[][4], int formaDeGanar);
void igualaMatriz(int matrizA[][4], int matrizB[][4]);
void validaNumero(int matrizA[][4], int matrizB[][4], int baraja);

int main(){
    int cMatTablero[4][4];
    int tableroValores[4][4];
    int barajas[16];
    generarTabla(cMatTablero);
    igualaMatriz(cMatTablero, tableroValores);
    int formaDeGanar;
    cout<<"BIENVENIDO A LA LOTERIA TEC"<<endl;
    cout<<"Selecciona la opcion para ganar: "<<endl;
    cout<<"1) Vertical"<<endl;
    cout<<"2) Horizontal"<<endl;
    cout<<"3) Diagonal"<<endl;
    cout<<"4) Cuatro esqinas"<<endl;
    cout<<"5) Posito"<<endl;
    cout<<"6) Cuadro exterior"<<endl;
    cout<<"\nOpcion: ";

    do{
        cin>>formaDeGanar;
        if(formaDeGanar<1 || formaDeGanar>6){
            cout<<"Introduzca una opcion valida: ";
        }
    } while(formaDeGanar<1 || formaDeGanar>6);

    cout<<"\nTU TABLA ES:"<<endl;
    mostrarTabla(cMatTablero);

    switch(formaDeGanar){
        case 1: vertical(cMatTablero, barajas, tableroValores);
            break;
        case 2: horizontal(cMatTablero, barajas, tableroValores);
            break;
        case 3: diagonal(cMatTablero, barajas, tableroValores);
            break;
        case 4: cuatroEsquinas(cMatTablero, barajas, tableroValores);
            break;
        case 5: posito(cMatTablero, barajas, tableroValores);
            break;
        case 6: cuadroExterior(cMatTablero, barajas, tableroValores);
            break;
    }
    dezplieganumeros(cMatTablero, tableroValores,formaDeGanar);

    return 0;
}

void generarTabla(int cMatTablero[4][4]){
    int iR, iC, iCont;

    for (iR = 0; iR < 4; iR++){
        for (iC = 0; iC < 4; iC++){
            cMatTablero[iR][iC] = 1;
            srand((int)time(0));
        }
    }

    for (iCont = 1; iCont <= 15; ){
        iR = rand() % 4;
        iC = rand() % 4;
        if (cMatTablero[iR][iC] == 1){
            cMatTablero[iR][iC] = rand() % 53+1;
            iCont++;
        }
    }
}
/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */

void mostrarTabla(int cMatTablero[4][4]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(j<3){
                cout<<cMatTablero[i][j]<<"-";
            }
            else{
                cout<<cMatTablero[i][j];
            }
        }
        cout<<endl;
    }
}
/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */

void vertical(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]){
    int baraja;
    bool col1=false, col2=false, col3=false, col4=false;
    //bool comp = false;
    //int contBaraja=0;
    do{
        cout<<"\nIntroce el numero de la baraja: "; cin>>baraja;
        validaNumero(cMatTablero, tableroValores, baraja);
        /*while(baraja<1 || baraja>54){
            cout<<"Esta baraja no esta en el rango, digite otra vez: "; cin>>baraja;
            barajas[contBaraja] = baraja;
        }
        contBaraja++;

        while(comp == false){
        for(int i=1; i<16; i++){
            if(baraja == barajas[i]){
                cout<<"Esta carta ya se introdujo anteriormente, digite otra vez: "; cin>>baraja;
                barajas[contBaraja];
            }
            else{
                comp = true;
            }
        }
        }*/

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(baraja == cMatTablero[i][j]){
                    cMatTablero[i][j] = 0;
                }
            }
        }
        mostrarTabla(cMatTablero);

        if(cMatTablero[0][0] == 0 && cMatTablero[1][0] == 0 && cMatTablero[2][0] ==0 && cMatTablero[3][0] ==0)
            col1=true;
        if(cMatTablero[0][1] == 0 && cMatTablero[1][1] == 0 && cMatTablero[2][1] ==0 && cMatTablero[3][1] ==0)
            col2=true;
        if(cMatTablero[0][2] == 0 && cMatTablero[1][2] == 0 && cMatTablero[2][2] ==0 && cMatTablero[3][2] ==0)
            col3=true;
        if(cMatTablero[0][3] == 0 && cMatTablero[1][3] == 0 && cMatTablero[2][3] ==0 && cMatTablero[3][3] ==0)
            col4=true;

    }while(col1==false && col2==false && col3==false && col4==false);
    cout<<"Haz Ganado!!" <<endl<<endl;
}
/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */
void horizontal(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]){
    int baraja;
    bool fil1=false, fil2=false, fil3=false, fil4=false;
    //bool comp = false;
    //int contBaraja=0;
    do{
        cout<<"\nIntroce el numero de la baraja: "; cin>>baraja;
        validaNumero(cMatTablero, tableroValores, baraja);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(baraja == cMatTablero[i][j]){
                    cMatTablero[i][j] = 0;
                }
            }
        }
        mostrarTabla(cMatTablero);

        if(cMatTablero[0][0] == 0 && cMatTablero[0][1] == 0 && cMatTablero[0][2] ==0 && cMatTablero[0][3] ==0)
            fil1=true;
        if(cMatTablero[1][0] == 0 && cMatTablero[1][1] == 0 && cMatTablero[1][2] ==0 && cMatTablero[1][3] ==0)
            fil2=true;
        if(cMatTablero[2][0] == 0 && cMatTablero[2][1] == 0 && cMatTablero[2][2] ==0 && cMatTablero[2][3] ==0)
            fil3=true;
        if(cMatTablero[3][0] == 0 && cMatTablero[3][1] == 0 && cMatTablero[3][2] ==0 && cMatTablero[3][3] ==0)
            fil4=true;

    }while(fil1==false && fil2==false && fil3==false && fil4==false);
    cout<<"Haz Ganado!!"<< endl<< endl;
}
/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */
void diagonal(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]){
    int baraja;
    bool diag1=false, diag2=false;
    //bool comp = false;
    //int contBaraja=0;
    do{
        cout<<"\nIntroce el numero de la baraja: "; cin>>baraja;
        validaNumero(cMatTablero, tableroValores, baraja);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(baraja == cMatTablero[i][j]){
                    cMatTablero[i][j] = 0;
                }
            }
        }
        mostrarTabla(cMatTablero);

        if(cMatTablero[0][0] == 0 && cMatTablero[1][1] == 0 && cMatTablero[2][2] ==0 && cMatTablero[3][3] ==0)
            diag1=true;
        if(cMatTablero[0][3] == 0 && cMatTablero[1][2] == 0 && cMatTablero[2][1] ==0 && cMatTablero[3][0] ==0)
            diag2=true;

    }while(diag1==false && diag2==false);
    cout<<"Haz Ganado!!"<< endl<< endl;
}
/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */
void cuatroEsquinas(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]){
    int baraja;
    bool cuatroE=false;
    //bool comp = false;
    //int contBaraja=0;
    do{
        cout<<"\nIntroce el numero de la baraja: "; cin>>baraja;
        validaNumero(cMatTablero, tableroValores, baraja);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(baraja == cMatTablero[i][j]){
                    cMatTablero[i][j] = 0;
                }
            }
        }
        mostrarTabla(cMatTablero);

        if(cMatTablero[0][0] == 0 && cMatTablero[0][3] == 0 && cMatTablero[3][0] ==0 && cMatTablero[3][3] ==0)
            cuatroE=true;

    }while(cuatroE==false);
    cout<<"Haz Ganado!!"<< endl<< endl;
}
/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */
void posito(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]){
    int baraja;
    bool posi=false;
    //bool comp = false;
    //int contBaraja=0;
    do{
        cout<<"\nIntroce el numero de la baraja: "; cin>>baraja;
        validaNumero(cMatTablero, tableroValores, baraja);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(baraja == cMatTablero[i][j]){
                    cMatTablero[i][j] = 0;
                }
            }
        }
        mostrarTabla(cMatTablero);

        if(cMatTablero[1][1] == 0 && cMatTablero[1][2] == 0 && cMatTablero[2][1] ==0 && cMatTablero[2][2] ==0)
            posi=true;

    }while(posi==false);
    cout<<"Haz Ganado!!"<< endl<< endl;
}
/* *************************************************************************************************************
***************************************************************************************************************
************************************************************************************************************** */
void cuadroExterior(int cMatTablero[4][4], int barajas[16], int tableroValores[][4]){
    int baraja;
    bool cE=false;
    //bool comp = false;
    //int contBaraja=0;
    do{
        cout<<"\nIntroce el numero de la baraja: "; cin>>baraja;
        validaNumero(cMatTablero, tableroValores, baraja);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(baraja == cMatTablero[i][j]){
                    cMatTablero[i][j] = 0;
                }
            }
        }
        mostrarTabla(cMatTablero);

        if(cMatTablero[0][0] == 0 && cMatTablero[0][1] == 0 && cMatTablero[0][2] ==0 && cMatTablero[0][3] ==0 &&
           cMatTablero[1][0] == 0 && cMatTablero[2][0] == 0 && cMatTablero[3][0] ==0 && cMatTablero[1][3] ==0 &&
           cMatTablero[2][3] == 0 && cMatTablero[3][3] == 0 && cMatTablero[3][1] ==0 && cMatTablero[3][2] ==0)
            cE=true;

    }while(cE==false);
    cout<<"Haz Ganado!!"<< endl<< endl;
}


/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */

 /* Dentro de esta funcion se hace el display de las cartas ganadoras, esto se hace con una seginda matriz la cual
  * guarda los valores iniciales del tablero*/
void dezplieganumeros(int matrizA[][4], int matrizB[][4], int formaDeGanar){
    switch(formaDeGanar){
            case 1:/*Vertical*/
            if(matrizA[0][0]==0 &&matrizA[1][0]==0 &&matrizA[2][0]==0 &&matrizA[3][0]==0){
                cout<< "Ganaste con: "<<endl<<matrizB[0][0]<< " - "<< matrizB[1][0]<< " - ";
                cout<< matrizB[2][0]<< " - "<< matrizB[3][0];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[0][1]==0 &&matrizA[1][1]==0 &&matrizA[2][1]==0 &&matrizA[3][1]==0){
                    cout<< "Ganaste con: "<<endl<<matrizB[0][1]<< " - "<< matrizB[1][1]<< " - ";
                    cout<< matrizB[2][1]<< " - "<< matrizB[3][1];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[0][2]==0 &&matrizA[1][2]==0 &&matrizA[2][2]==0 &&matrizA[3][2]==0){
                cout<< "Ganaste con: "<<endl<<matrizB[0][2]<< " - "<< matrizB[1][2]<< " - ";
                cout<< matrizB[2][2]<< " - "<< matrizB[3][2];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[0][3]==0 &&matrizA[1][3]==0 &&matrizA[2][3]==0 &&matrizA[3][3]==0){
                cout<< "Ganaste con: "<<endl<<matrizB[0][3]<< " - "<< matrizB[1][3]<< " - ";
                cout<< matrizB[2][3]<< " - "<< matrizB[3][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            break;
            case 2: /*Horizontal*/
            if(matrizA[0][0]==0 &&matrizA[0][1]==0 &&matrizA[0][2]==0 &&matrizA[0][3]==0){
                cout<< "Ganaste con: "<<endl<<matrizB[0][0]<< " - "<< matrizB[0][1]<< " - ";
                cout<< matrizB[0][2]<< " - "<< matrizB[0][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[1][0]==0 &&matrizA[1][1]==0 &&matrizA[1][2]==0 &&matrizA[1][3]==0){
                cout<< "Ganaste con: "<<endl<<matrizB[1][0]<< " - "<< matrizB[1][1]<< " - ";
                cout<< matrizB[1][2]<< " - "<< matrizB[1][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[2][0]==0 &&matrizA[2][1]==0 &&matrizA[2][2]==0 &&matrizA[2][3]==0) {
                cout << "Ganaste con: " << endl << matrizB[2][0] << " - " << matrizB[2][1] << " - ";
                cout << matrizB[2][2] << " - " << matrizB[2][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[3][0]==0 &&matrizA[3][1]==0 &&matrizA[3][2]==0 &&matrizA[3][3]==0) {
                cout << "Ganaste con: " << endl << matrizB[3][0] << " - " << matrizB[3][1] << " - ";
                cout << matrizB[3][2] << " - " << matrizB[3][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            break;
            case 3: /* Diagonal*/
            if(matrizA[0][0]==0 && matrizA[1][1]==0 && matrizA[2][2]==0 && matrizA[3][3]==0){
                cout<< "Ganaste con:"<< endl<< matrizB[0][0]<< " - "<< matrizB[1][1]<< " - ";
                cout<< matrizB[2][2]<< " - "<< matrizB[3][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            if(matrizA[0][3]==0 && matrizA[1][2]==0 && matrizA[2][1]==0 && matrizA[3][0]==0){
                cout<< "Ganaste con: " << endl << matrizB[0][3] << " - "<< matrizB[1][2]<< " - ";
                cout<< matrizB[2][1]<< " - "<< matrizB[3][0];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            break;
            case 4: /*Cuatro Esquinas*/
            if(matrizA[0][0]==0 && matrizA[0][3]==0 && matrizA[3][0]==0 && matrizA[3][3]==03){
                cout<< "Ganaste con:"<< endl<< matrizB[0][0]<< " - "<< matrizB[0][3]<< " - ";
                cout<< matrizB[3][0]<< " - "<< matrizB[3][3];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            break;
            case 5: /*Posito*/
            if(matrizA[1][1]==0 && matrizA[1][2]==0 && matrizA[2][1]==0 && matrizA[2][2]==0){
                cout<< "Ganaste con:"<< endl<< matrizB[1][1]<< " - "<< matrizB[1][2]<< " - ";
                cout<< matrizB[2][1]<< " - "<< matrizB[2][2];
                cout<< endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            }
            break;
            case 6: /*Cuadro Exterior*/
            cout<< "Ganaste con:"<< endl<< matrizB[0][0]<< " - "<< matrizB[0][1] << " - ";
            cout<< matrizB[0][2]<< " - "<< matrizB[0][3]<< " - "<< matrizB[1][0]<< " - ";
            cout<< matrizB[1][3]<< " - "<< matrizB[2][0]<< " - "<< matrizB[2][3]<< " - ";
            cout<< matrizB[3][0]<< " - "<< matrizB[3][1]<< " - "<< matrizB[3][2]<< " - ";
            cout<< matrizB[3][3]<<endl<< "Para jugar otra ronda, por favor, vuelve a correr el programa";
            break;
    }
}



/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */

//Esta funcion iguala los valores de la matrizA y la matrizB para poder guardar los valores
void igualaMatriz(int matrizA[][4], int matrizB[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrizB[i][j]=matrizA[i][j];
        }
    }
}

/* *************************************************************************************************************
***************************************************************************************************************
*************************************************************************************************************** */


void validaNumero(int matrizA[][4], int matrizB[][4], int baraja){
    int cont=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(matrizB[i][j]!=baraja){
            cont++;
            }
        }
    }
    if (cont==16){
        cout<< "Este numero no esta en la baraja"<< endl<< endl;
    }
    int cont2=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(matrizB[i][j]==baraja && matrizA[i][i]==0){
                cont2++;
            }
        }
    }
    if (cont2!=0){
        cout<< "Este numero ya habia sido introducido"<< endl << endl;
    }
}
