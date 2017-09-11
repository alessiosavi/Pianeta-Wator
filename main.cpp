#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <windows.h>

#define COL 500
#define RIG 180
#define CP 15
#define CS 0
#define CB 9

/* COLORI INT COLOR
BLACK 	      0
BLUE	      1
GREEN	      2
CYAN	      3
RED	          4
MAGENTA	      5
BROWN	      6
LIGHTGRAY	  7
DARKGRAY	  8
LIGHTBLUE	  9
LIGHTGREEN	  10
LIGHTCYAN	  11
LIGHTRED	  12
LIGHTMAGENTA  13
YELLOW	      14
WHITE	      15 
*/

using namespace std;

struct zona{
       char tipo;
       char turno;
       int tRp;
       int tRs;
       int vita;
};

struct zona pianeta[COL][RIG];
int tRpesci,tRsquali,longevita,vitalita;


void visualizza(){
     int x,y;
     for(x=0;x<COL;x++)
        for(y=0;y<RIG;y++)
            switch(pianeta[x][y].tipo){
                case 0:
                     putpixel(x,y,CB);
                     break;
                case 1:
                     putpixel(x,y,CP);
                     break;
                case 2:
                     putpixel(x,y,CS);
            }
}

void scambia(int x1,int y1,int x2,int y2){
     struct zona aux;
     aux=pianeta[x2][y2];
     pianeta[x2][y2]=pianeta[x1][y1];
     pianeta[x1][y1]=aux;
}

int mangia (int x,int y){
    int r;
    int xm,xp;
     int ym,yp;
     switch (x){
            case 0:
                 xm=COL-1;
                 xp=x+1;
                 break;
            case COL-1:
                 xp=0;
                 xm=x-1;
                 break;
            default:
                 xm=x-1;
                 xp=x+1;
     }
     switch (y){
            case 0:
                 yp=RIG-1;
                 ym=y+1;
                 break;
            case RIG-1:
                 ym=0;
                 yp=y-1;
                 break;
            default:
                 ym=y+1;
                 yp=y-1;
     }
     if(pianeta[xm][y].tipo==1){
         scambia(x,y,xm,y);
         pianeta[xm][y].vita=longevita;
         putpixel(xm,y,CS);
         putpixel(x,y,CB);
         return 1;
     }
     if(pianeta[x][yp].tipo==1){
         scambia(x,y,x,yp);
         pianeta[x][yp].vita=longevita;
         putpixel(x,yp,CS);
         putpixel(x,y,CB);
         return 1;
     }
     if(pianeta[xp][y].tipo==1){
         scambia(x,y,xp,y);
         pianeta[xp][y].vita=longevita;
         putpixel(xp,y,CS);
         putpixel(x,y,CB);
         return 1;
     }
     if(pianeta[x][ym].tipo==1){
         scambia(x,y,x,ym);
         pianeta[x][ym].vita=longevita;
         putpixel(x,ym,CS);
         putpixel(x,y,CB);
         return 1;
     }
     return 0;
         
    
}

void muovi (int x,int y){
     int r;
     int xm,xp;
     int ym,yp;
     switch (x){
            case 0:
                 xm=COL-1;
                 xp=x+1;
                 break;
            case COL-1:
                 xp=0;
                 xm=x-1;
                 break;
            default:
                 xm=x-1;
                 xp=x+1;
     }
     switch (y){
            case 0:
                 yp=RIG-1;
                 ym=y+1;
                 break;
            case RIG-1:
                 ym=0;
                 yp=y-1;
                 break;
            default:
                 ym=y+1;
                 yp=y-1;
     }
     int controllo;
     if(pianeta[x][y].tipo!=0) do{
         r=rand()%4;
         switch(r){
             case 0:
                  if(pianeta[xm][y].tipo==0){
                      scambia(x,y,xm,y);
                      if(pianeta[xm][y].tipo==1)
                          putpixel(xm,y,CP);
                      else putpixel(xm,y,CS);
                      putpixel(x,y,CB);
                      controllo=1;
                  }
                  else controllo=0;
                  break;
             case 1:
                  if(pianeta[x][yp].tipo==0){ 
                      scambia(x,y,x,yp);
                      if(pianeta[x][yp].tipo==1)
                          putpixel(x,yp,CP);
                      else putpixel(x,yp,CS);
                      putpixel(x,y,CB);
                      controllo=1;
                  }
                  else controllo=0;
                  break;
             case 2:
                  if(pianeta[xp][y].tipo==0){
                      scambia(x,y,xp,y);
                      if(pianeta[xp][y].tipo==1)
                          putpixel(xp,y,CP);
                      else putpixel(xp,y,CS);
                      putpixel(x,y,CB);
                      controllo=1;
                  }
                  else controllo=0;
                  break;  
             case 3:
                  if(pianeta[x][ym].tipo==0){ 
                      scambia(x,y,x,ym);
                      if(pianeta[x][ym].tipo==1)
                          putpixel(x,ym,CP);
                      else putpixel(x,ym,CS);
                      putpixel(x,y,CB);
                      controllo=1;
                  }
                  else controllo=0;
         }
     }while(controllo=0);
     }
                                

int main(int argc, char *argv[])
{
    system("title Crescita Grafica");
    FILE *f;
    int x,y;
    int ran,ctrl;
    int pesci,squali;
    char turno=0;
    struct zona aux;
    int tempo,intervallo,i,n;
    n=1;
    f=fopen("Dati.txt","wt");


    printf("----Benvenuto su Wator!----\n Su questo meraviglioso(si fa per dire) pianeta ricoperto d'acqua sul quale\n il tempo si misura in Crononi lottano per la sopravvivenza due specie:\n i candidi Savi-Fish e i nerissimi Bu-Shark\n");
    printf("\nInserisci il numero di Crononi da far scorrere: ");
    scanf("%d",&tempo);
    printf("\nInserisci ogni quanti Crononi inserire dati nel file \"Dati.txt\": ");
    scanf("%d",&intervallo);
    printf("\nInserisci il numero iniziale dei Savi-Fish: ");
    scanf("%d",&pesci);
    printf("\nInserisci il numero di Crononi necessari alla riproduzione dei Savi-Fish: ");    
    scanf("%d",&tRpesci);
    printf("\nInserisci la longevita' dei Savi-Fish: ");
    scanf("%d",&vitalita);
    printf("\nInserisci il numero iniziale dei Bu-Shark: ");
    scanf("%d",&squali);
    printf("\nInserisci il numero di Crononi necessari alla riproduzione dei Bu-Shark: ");
    scanf("%d",&tRsquali);
    printf("\nInserisci per quanti Crononi un Bu-Shark puo' sopravvivere senza mangiare: ");
    scanf("%d",&longevita);
    
    fprintf(f,"------DATI INIZIALI------");
    fprintf(f,"\nDurata della simulazione : %d Crononi",tempo);
    fprintf(f,"\nIntervallo di tempo analizzato: %d Crononi",intervallo);
    fprintf(f,"\nPopolazione iniziale Savi-Fish: %d",pesci);
    fprintf(f,"\nTempo di riproduzione dei Savi-Fish: %d Crononi",tRpesci);
    fprintf(f,"\nLongevita' Savi-Fish: %d Crononi",vitalita);
    fprintf(f,"\nPopolazione iniziale Bu-Shark: %d",squali);
    fprintf(f,"\nTempo di riproduzione dei Bu-Shark: %d Crononi",tRsquali);
    fprintf(f,"\nLongevita' Bu-Shark: %d Crononi",longevita);
    fprintf(f,"\n-------------------------\n");
    
        
    for(x=0;x<COL;x++)
        for(y=0;y<RIG;y++)
            pianeta[x][y].tipo=0;
    
    initwindow(COL,RIG,"Wator");
    printf("\nSpostare la finestra di simulazione in un punto visibile dello schermo\n");
    system("pause");
    srand(time(NULL));
    for(ran=0;ran<pesci;ran++){
        x=rand()%COL+1;
        y=rand()%RIG+1;
        if(pianeta[x][y].tipo==0){
            pianeta[x][y].tipo=1;
            pianeta[x][y].tRp=tRpesci;
            pianeta[x][y].vita=vitalita;
            pianeta[x][y].turno=1;
        }
        else x--;
    }
    for(ran=0;ran<squali;ran++){
        x=rand()%COL+1;
        y=rand()%RIG+1;
        if(pianeta[x][y].tipo==0){
            pianeta[x][y].tipo=2;
            pianeta[x][y].tRs=tRsquali;
            pianeta[x][y].vita=longevita;
            pianeta[x][y].turno=1;
        }
        else x--;
    }
    //matrice inizializzata con squali e pesci
    visualizza();
    printf("\nSimulazione pronta, ");
    system("pause");
    for(ran=tempo;ran>=0;ran--){
    for(x=0;x<COL;x++)
        for(y=0;y<RIG;y++){
            if(pianeta[x][y].turno!=turno){
				switch(pianeta[x][y].tipo){
					case 1:
						 if(pianeta[x][y].vita!=0){
							 pianeta[x][y].vita--;
							 if (pianeta[x][y].tRp==0){
								pesci++;
                                pianeta[x][y].tRp=tRpesci;
								aux=pianeta[x][y];
								muovi(x,y);
								pianeta[x][y]=aux;
								pianeta[x][y].vita=vitalita;
								}
								else{
									pianeta[x][y].tRp--;
									muovi(x,y);
								}
						 }
						 else {
                              pianeta[x][y].tipo=0;
						      putpixel(x,y,CB);
						      pesci--;
                            }
						 break;
					case 2:
						if(pianeta[x][y].vita!=0){
							 pianeta[x][y].vita--;
							 if (pianeta[x][y].tRs==0){
								 squali++;
                                 pianeta[x][y].tRs=tRsquali;
								 aux=pianeta[x][y];
								 ctrl=mangia(x,y);
								 if(ctrl==0)
									 muovi(x,y);
								 else pesci--;
								 pianeta[x][y]=aux;
								 pianeta[x][y].vita=longevita;
							 }
							 else{
								 pianeta[x][y].tRs--;
								 ctrl=mangia(x,y);
								  if(ctrl==0)
									  muovi(x,y);
							 }
						}
						 else {
                              pianeta[x][y].tipo=0;
							  putpixel(x,y,CB);
							  squali--;
                            }
				}
            
            /*if (pianeta[x][y].tipo==2)
                ctrl=mangia(x,y);
            if(pianeta[x][y].tipo==1||(pianeta[x][y].tipo==2&&ctrl==0))
                muovi(x,y);
            */
                
			}
		}
    pianeta[x][y].turno=turno;
    if(turno=0) turno=1;
    else turno=0;
    if(i<intervallo)i++;
    else{
        fprintf(f,"\nIntervallo: %d",n);
        fprintf(f,"\nPopolazione dei Savi-Fish: %d",pesci);
        fprintf(f,"\nPopolazione dei Bu-Shark: %d\n",squali);
        i=0;
        n++;
        }
        
    system ("cls");
    printf("Simulazione in corso. . .\nPopolazione attuale dei Savi-Fish: %d\nPopolazione attuale dei Bu-Shark: %d\n----Crononi Rimasti: %d",pesci,squali,ran);
    }
    system("cls");
    printf("\nSimulazione terminata!");
    pesci=squali=0;
    for(x=0;x<COL;x++)
        for(y=0;y<RIG;y++){
            if(pianeta[x][y].tipo==1)
                pesci++;
            if(pianeta[x][y].tipo==2)
                squali++;
        }
    printf("\nPopolazione finale dei Savi-Fish: %d",pesci);
    printf("\nPopolazione finale dei Bu-Shark: %d\n",squali);
    
    fprintf(f,"\n------DATI INIZIALI------");
    fprintf(f,"\nPopolazione finale dei Savi-Fish: %d",pesci);
    fprintf(f,"\nPopolazione finale dei Bu-Shark: %d\n",squali);
    fprintf(f,"\n-------------------------");
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
