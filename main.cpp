/*
COPYRIGHT (c) Magistri Cumacini All Rights Reserved.
Memory sviluppato in c++.
@sviluppatori: Marroffino Antonio
               Martucci Flavio
               Frontino Nunzio Samuele
               Lacaj Klaidi
@ultima modifica: 20/12/'20
*/
//******************************* LIBRERIE ***********************************//
#include<graphics.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//******************************* COSTANTI ***********************************//
//--DIMENSIONI
#define WINX 800
#define WINY 600
//--MASSIMI
#define MAX_STRINGA 100
#define MAX_BANDIERE 40
//--LIMITI
#define X_LIMITE_TORNAINDIETRO 113
#define Y_LIMITE_TORNAINDIETRO 30
#define X_LIMITE_GENERABANDIERE 650
#define Y_LIMITE_GENERABANDIERE 30
#define X_LIMITE_BANDIERESPECIALI 320
#define Y_LIMITE_BANDIERESPECIALI 580
#define LIMITEDESTRO_GENERA 200
#define LIMITEALTO_GENERA 100
#define LIMITESINISTRO_GENERA 600
#define LIMITEBASSO_GENERA 200
//--TESTI
#define X_MEMORY 135
#define Y_MEMORY 100
#define X_MENU_BANDIERE X_BOTTONE_MENU_BANDIERE
#define Y_MENU_BANDIERE Y_BOTTONE_MENU_BANDIERE+12
#define X_MENU_GIOCA X_BOTTONE_MENU_GIOCA+20
#define Y_MENU_GIOCA Y_BOTTONE_MENU_GIOCA+12
#define X_SCRITTA_SVILUPPATO 40
#define Y_SCRITTA_SVILUPPATO Y_MEMORY+90
#define X_REGOLAMENTO X_BOTTONE_REGOLAMENTO-6
#define Y_REGOLAMENTO Y_BOTTONE_REGOLAMENTO-10
#define X_SCRITTA_REGOLAMENTO X_BOTTONE_REGOLAMENTO-RAGGIO_REGOLAMENTO-30
#define Y_SCRITTA_REGOLAMENTO Y_BOTTONE_REGOLAMENTO-RAGGIO_REGOLAMENTO-20
#define X_TORNAINDIETRO X_BOTTONE_TORNAINDIETRO
#define Y_TORNAINDIETRO (Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO)/2-3
#define X_GENERABANDIERE X_BOTTONE_GENERABANDIERE
#define Y_GENERABANDIERE (Y_BOTTONE_GENERABANDIERE+Y_LUNGHEZZA_GENERABANDIERE)/2-3
#define X_BANDIERESPECIALI 320
#define Y_BANDIERESPECIALI 580
#define X_BANDIERE 300
#define Y_BANDIERE 80
#define X_GENERA X_BOTTONE_GENERA+140
#define Y_GENERA Y_BOTTONE_GENERA+32
#define X_MASSIMOBANDIERE 30
#define Y_MASSIMOBANDIERE 180
#define X_OK X_BOTTONE_OK
#define Y_OK Y_BOTTONE_OK+3
#define X_CANCELLA 140
#define Y_CANCELLA 420
#define X_SALVA 170
#define Y_SALVA 420
#define X_GENERACASUALE 220
#define Y_GENERACASUALE Y_BOTTONE_GENERACASUALE+17
//--BOTTONI
#define X_BOTTONE_TORNAINDIETRO 20
#define Y_BOTTONE_TORNAINDIETRO 5
#define X_LUNGHEZZA_TORNAINDIETRO 110
#define Y_LUNGHEZZA_TORNAINDIETRO 30
#define X_BOTTONE_GENERABANDIERE 660
#define Y_BOTTONE_GENERABANDIERE 5
#define X_LUNGHEZZA_GENERABANDIERE 120
#define Y_LUNGHEZZA_GENERABANDIERE 30
#define X_BOTTONE_REGOLAMENTO 730
#define Y_BOTTONE_REGOLAMENTO 550
#define RAGGIO_REGOLAMENTO 30
#define X_BOTTONE_MENU_BANDIERE 345
#define Y_BOTTONE_MENU_BANDIERE 300
#define X_LUNGHEZZA_MENU_BANDIERE 110
#define Y_LUNGHEZZA_MENU_BANDIERE 50
#define X_BOTTONE_MENU_GIOCA 345
#define Y_BOTTONE_MENU_GIOCA 375
#define X_LUNGHEZZA_MENU_GIOCA 110
#define Y_LUNGHEZZA_MENU_GIOCA 50
#define X_BOTTONE_GENERA 175
#define Y_BOTTONE_GENERA 110
#define X_LUNGHEZZA_GENERA 450
#define Y_LUNGHEZZA_GENERA 100
#define X_BOTTONE_GENERACASUALE X_BOTTONE_GENERA
#define Y_BOTTONE_GENERACASUALE 530
#define X_LUNGHEZZA_GENERACASUALE X_LUNGHEZZA_GENERA
#define Y_LUNGHEZZA_GENERACASUALE 50
#define X_BOTTONE_OK 365
#define Y_BOTTONE_OK 300
#define X_LUNGHEZZA_OK 65
#define Y_LUNGHEZZA_OK 50
//--BANDIERE
#define DIM 80
#define DIST 20
#define LATOBANDIERE1 60
#define LATOBANDIERE2 40
#define RETROBANDIERE 15
//--DIFFICOLTA'
#define TEMPO_DIFFICOLTA1 60
#define TEMPO_DIFFICOLTA2 120
#define TEMPO_DIFFICOLTA3 80
#define TEMPO_DIFFICOLTA4 240
#define DIMENSIONE_DIFFICOLTA1 4
#define DIMENSIONE_DIFFICOLTA2 6
#define DIMENSIONE_DIFFICOLTA3 6
#define DIMENSIONE_DIFFICOLTA4 8
//*************************** DICHIARAZIONE TIPI *****************************//
typedef FILE* Tfile;                            //puntatore al file
typedef int Tcoordinata;                        //coordinata
typedef char Tstringa[MAX_STRINGA];             //stringa
typedef struct {
  bool righeOcolonne;
  char numeroStrisce, colore1, colore2, colore3;
} Tbandiera;                                    //struttura di una bandiera
typedef struct {
  Tstringa nome;
  int tempo;
} Tutente;                                      //struttura di un utente
//************************** PROTOTIPI FUNZIONI ******************************//
void graficaMenu();                                                                                     //procedura che stampa la grafica del menù
//--FUNZIONI BANDIERE
void bandiere();                                                                                        //macroprocedura per la gestione delle bandiere
void graficaBandiere();                                                                                 //procedura che imposta la grafica delle bandiere
void generaBandiere(Tbandiera bandiereSalvate[], int *cont);                                            //procedura che genera le bandiere e le salva nell'array
void graficaGeneraBandiere();                                                                           //procedura che imposta la grafica delle generazione bandiere
int letturaDaFile(Tbandiera buffer[]);                                                                  //funzione che restituisce quante strutture sono state lette dal file
void scritturaSuFile(Tbandiera buffer[], int cont);                                                     //procedura che salva l'array di bandiere sul file
bool bandieraSelezionata(Tcoordinata x, Tcoordinata y, int *posizione, int cont, Tbandiera bandiereSalvate[]);//funzione che restituisce se la bandiera va cancellata
void cancellaBandiera(Tbandiera bandiereSalvate[], int posizione, int *cont);                           //procedura che cancella una bandiera
bool chiediConferma(Tstringa frase, Tcoordinata xFrase, Tcoordinata yFrase);                            //funzione che chiede all'utente una domanda
Tbandiera creaBandiera();                                                                               //funzione che restiruisce una struttura di tipo Tbandiera
void controlloMassimoBandiere();                                                                        //procedura che controlla se il numero massimo di bandiere è stato raggiunto
bool bandieraEsiste(Tbandiera bandiera, Tbandiera bandiereSalvate[], int cont);                         //funzione che confronta una bandiera con tutte le bandiere salvate
//--REGOLAMENTO
void regolamento();                                                                                     //procedura che mostra le regole del gioco
//--FUNZIONI IN COMUNE
void creaTesto(int colore, int coloreSfondo, int font, int dimensioneCarattere, Tcoordinata xCoor, Tcoordinata yCoor, Tstringa frase);//procedura che stampa una stringa
void bottone(Tcoordinata x, Tcoordinata y,int lunghezzax,int lunghezzay,int colore);                    //procedura che crea un pulsante sullo schermo
void attendiClickDelMouse(Tcoordinata *x, Tcoordinata *y);                                              //procedura che restituisce le coordinate del click del mouse
void stampaBandiera(Tbandiera bandiera, Tcoordinata x1, Tcoordinata y1, Tcoordinata x2, Tcoordinata y2);//procedura che stampa una bandiera
//--FUNZIONI GIOCA
void gioca();                                                                                           //macroprocedura che gestisce la partita
int inserisciNome(Tutente* datiUtente);                                                                 //funzione che permette all'utente di inserire il suo nome (per la classifica)
int giocaPartita(Tutente* datiUtente);                                                                  //funzione che restituisce il risultato della partita
int letturaFile(Tbandiera bandiere[][DIM], int dim);                                                    //funzione che legge dal file le bandiere
void duplicaBandiere(Tbandiera bandiere[][DIM], int dim);                                               //procedura che duplica le bandiere
void mescolaBandiere(Tbandiera bandiere[][DIM], int dim);                                               //procedura che mescola le bandiere
void stampaMatrice(Tbandiera bandiere[][DIM], int dim);                                                 //procedura che stampa la matrice bandiere
void riempiAppoggio(Tbandiera appoggio[][DIM], int dim);                                                //procedura che riempie la matrice di appoggio con le bandiere da utilizzare
int controllaCaselleScoperte(Tbandiera appoggio[][DIM], Tbandiera bandiere[][DIM], int* c, int dim, time_t tempoInizio, int tempoMax); //funzione che mostra le bandiere selezionate
int confrontaBandiere(Tbandiera bandiera1, Tbandiera bandiera2);                                        //funzione che confronta 2 bandiere
int sceltaDifficolta(int* dim, int* tempoMax);                                                          //funzione che permette all'utente di scegliere la difficoltà
int clickValido(int x, int y, int* dim, int* tempoMax, int posx, int posy, int dy, int ly);             //funzione che verifica se il click è avvenuto sulla bandiera
int attendiClickDelMouseTempo(int *x, int *y, time_t tempoInizio, int tempoMax);	                    //funzione che attende il click, e stampa il tempo rimanente
Tbandiera retroBandiera();	                                                                            //funzione che crea il retro di una bandiera
void visualizzaClassifica();                                                                            //procedura che stampa la classifica aggiornata con nome utente e tempo
//************************ PROGRAMMA PRINCIPALE ******************************//
main() {
  initwindow(WINX+10, WINY+10);
  srand(time(NULL));
  Tcoordinata x, y;
  do {
    cleardevice();
    graficaMenu();
    attendiClickDelMouse(&x, &y);
    //Controllo che l'utente clicchi sul tasto BANDIERE
    if((x>X_BOTTONE_MENU_BANDIERE && x<X_BOTTONE_MENU_BANDIERE+X_LUNGHEZZA_MENU_BANDIERE &&
        y>Y_BOTTONE_MENU_BANDIERE && y<Y_BOTTONE_MENU_BANDIERE+Y_LUNGHEZZA_MENU_BANDIERE) ||
        (x>X_BOTTONE_MENU_BANDIERE-40 && x<X_BOTTONE_MENU_BANDIERE+X_LUNGHEZZA_MENU_BANDIERE+40 &&
         y>Y_BOTTONE_MENU_BANDIERE-1 && y<Y_BOTTONE_MENU_BANDIERE+Y_LUNGHEZZA_MENU_BANDIERE+1 &&
         getpixel(x,y)==LIGHTBLUE))
      bandiere();
    //Controllo che l'utente clicchi sul tasto REGOLAMENTO
    if(getpixel(x,y)==YELLOW || getpixel(x,y)==RED)
      regolamento();
    //Controllo che l'utente clicchi sul tasto GIOCA
    if((x>X_BOTTONE_MENU_GIOCA && x<X_BOTTONE_MENU_GIOCA+X_LUNGHEZZA_MENU_GIOCA &&
        y>Y_BOTTONE_MENU_GIOCA && y<Y_BOTTONE_MENU_GIOCA+Y_LUNGHEZZA_MENU_GIOCA) ||
        (x>X_BOTTONE_MENU_GIOCA-40 && x<X_BOTTONE_MENU_GIOCA+X_LUNGHEZZA_MENU_GIOCA+40 &&
         y>Y_BOTTONE_MENU_GIOCA-1 && y<Y_BOTTONE_MENU_GIOCA+Y_LUNGHEZZA_MENU_BANDIERE+1 &&
         getpixel(x,y)==LIGHTBLUE))
      gioca();

  } while(1); //il ciclo si ripete finchè l'applicazione non viene chiusa
  closegraph();
  return 0;
}

//************************** FUNZIONI BANDIERE *******************************//
//GRAFICA MENU'
void graficaMenu() {
  Tstringa StrMemory= {'M','E','M','O','R','Y','\0'};
  Tstringa StrBandiere= {'B','A','N','D','I','E','R','E','\0'};
  Tstringa StrGioca= {'G','I','O','C','A','\0'};
  Tstringa StrRegolamento= {'R','E','G','O','L','A','M','E','N','T','O','\0'};
  Tstringa StrI = {'i','\0'};
  creaTesto(WHITE, BLACK, SIMPLEX_FONT, 8, X_MEMORY, Y_MEMORY, StrMemory);
  creaTesto(WHITE, BLACK, DEFAULT_FONT, 1, X_SCRITTA_SVILUPPATO, Y_SCRITTA_SVILUPPATO, "Sviluppato da: Marroffino Antonio, Martucci Flavio, Frontino Nunzio Samuele, Lacaj Klaidi");
  bottone(X_BOTTONE_MENU_BANDIERE, Y_BOTTONE_MENU_BANDIERE, X_LUNGHEZZA_MENU_BANDIERE, Y_LUNGHEZZA_MENU_BANDIERE, LIGHTBLUE);
  creaTesto(WHITE, LIGHTBLUE, COMPLEX_FONT, 3, X_MENU_BANDIERE, Y_MENU_BANDIERE, StrBandiere);
  bottone(X_BOTTONE_MENU_GIOCA, Y_BOTTONE_MENU_GIOCA, X_LUNGHEZZA_MENU_GIOCA, Y_LUNGHEZZA_MENU_GIOCA, LIGHTBLUE);
  creaTesto(WHITE, LIGHTBLUE, COMPLEX_FONT, 3, X_MENU_GIOCA, Y_MENU_GIOCA, StrGioca);
  creaTesto(WHITE, BLACK, COMPLEX_FONT, 1, X_SCRITTA_REGOLAMENTO, Y_SCRITTA_REGOLAMENTO, StrRegolamento);
  setcolor(YELLOW);
  circle(X_BOTTONE_REGOLAMENTO,Y_BOTTONE_REGOLAMENTO,RAGGIO_REGOLAMENTO);
  setfillstyle(SOLID_FILL,YELLOW);
  floodfill(X_BOTTONE_REGOLAMENTO,Y_BOTTONE_REGOLAMENTO,YELLOW);
  creaTesto(RED, YELLOW, COMPLEX_FONT, 2, X_REGOLAMENTO, Y_REGOLAMENTO, StrI);
}
//BANDIERE
void bandiere() {
  Tbandiera bandiereSalvate[MAX_BANDIERE];
  Tcoordinata x, y, x1, y1, x2, y2;
  int i, posizione=0, distanza=60;
  int cont=letturaDaFile(bandiereSalvate);;
  do {
    cleardevice();
    x1=100, y1=140, x2=150, y2=170;
    for(i=0; i<cont; i++) {
      if(i%10==0) {
        x1=100;
        x2=150;
        y1+=distanza;
        y2+=distanza;
      } else {
        x1+=distanza;
        x2+=distanza;
      }
      stampaBandiera(bandiereSalvate[i], x1, y1, x2, y2);
    }
    graficaBandiere();
    attendiClickDelMouse(&x, &y);
    //Controllo che l'utente clicchi su una bandiera
    if(bandieraSelezionata(x, y, &posizione, cont, bandiereSalvate))
      cancellaBandiera(bandiereSalvate, posizione, &cont);
    //Controllo che l'utente clicchi sul tasto GENERA BANDIERE
    if((x>X_BOTTONE_GENERABANDIERE && x<X_BOTTONE_GENERABANDIERE+X_LUNGHEZZA_GENERABANDIERE &&
        y>Y_BOTTONE_GENERABANDIERE && y<Y_BOTTONE_GENERABANDIERE+Y_LUNGHEZZA_GENERABANDIERE) ||
        (x>X_BOTTONE_GENERABANDIERE-40 && y<Y_BOTTONE_GENERABANDIERE+Y_LUNGHEZZA_GENERABANDIERE &&
         getpixel(x,y)==CYAN))
      generaBandiere(bandiereSalvate,&cont);
    //il ciclo termina quando l'utente preme sul tasto TORNA INDIETRO
  } while(!((x>X_BOTTONE_TORNAINDIETRO && x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO &&
             y>Y_BOTTONE_TORNAINDIETRO && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO) ||
            (x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO+40 && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO &&
             getpixel(x,y)==CYAN)));

  scritturaSuFile(bandiereSalvate,cont);
}
//GRAFICA BANDIERE
void graficaBandiere() {
  Tstringa StrBandiere = {'B','A','N','D','I','E','R','E','\0'};
  Tstringa StrTornaIndietro = {'T','O','R','N','A',' ','I','N','D','I','E','T','R','O','\0'};
  Tstringa StrGeneraBandiere = {'G','E','N','E','R','A',' ','B','A','N','D','I','E','R','E','\0'};
  creaTesto(WHITE, BLACK, COMPLEX_FONT, 5, X_BANDIERE, Y_BANDIERE, StrBandiere);
  bottone(X_BOTTONE_TORNAINDIETRO,Y_BOTTONE_TORNAINDIETRO,X_LUNGHEZZA_TORNAINDIETRO,Y_LUNGHEZZA_TORNAINDIETRO,CYAN);
  creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_TORNAINDIETRO, Y_TORNAINDIETRO, StrTornaIndietro);
  bottone(X_BOTTONE_GENERABANDIERE,Y_BOTTONE_GENERABANDIERE,X_LUNGHEZZA_GENERABANDIERE,Y_LUNGHEZZA_GENERABANDIERE,CYAN);
  creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_GENERABANDIERE, Y_GENERABANDIERE, StrGeneraBandiere);
}
//GENERA BANDIERE
void generaBandiere(Tbandiera bandiereSalvate[], int *cont) {
  int x1=250, y1=250, x2, y2, lunghezza=300, altezza=150;
  int x, y;
  Tbandiera bandiera;
  x2=x1+lunghezza;
  y2=y1+altezza;

  do {
    cleardevice();
    graficaGeneraBandiere();
    attendiClickDelMouse(&x, &y);
    //Controllo che l'utente clicchi il tasto di GENERAZIONE CASUALE
    if((x>X_BOTTONE_GENERACASUALE && x<X_BOTTONE_GENERACASUALE+X_LUNGHEZZA_GENERACASUALE &&
        y>Y_BOTTONE_GENERACASUALE && y<Y_BOTTONE_GENERACASUALE+Y_LUNGHEZZA_GENERACASUALE) ||
        (x>X_BOTTONE_GENERACASUALE-40 && x<X_BOTTONE_GENERACASUALE+X_LUNGHEZZA_GENERACASUALE+40 &&
         y>Y_BOTTONE_GENERACASUALE-1 && y<Y_BOTTONE_GENERACASUALE+Y_LUNGHEZZA_GENERACASUALE+1 &&
         getpixel(x,y)==RED)) {
      //Controllo che il numero massimo di bandiere non sia stato raggiunto
      if(*cont>=MAX_BANDIERE)
        controlloMassimoBandiere();
      else {
        do {
          //creo una bandiera
          do {
            bandiera=creaBandiera();
            //Il ciclo termina quando la bandiera creata non esiste
          } while(bandieraEsiste(bandiera,bandiereSalvate,*cont));
          bandiereSalvate[*cont]=bandiera;
          (*cont)++;
          //Il ciclo si ripete finchè non si raggiunge il massimo numero di bandiere
        } while((*cont)<MAX_BANDIERE);
      }
    }
    //Controllo che l'utente clicchi sul tasto GENERA
    if((x>X_BOTTONE_GENERA && x<X_BOTTONE_GENERA+X_LUNGHEZZA_GENERA &&
        y>Y_BOTTONE_GENERA && y<Y_BOTTONE_GENERA+Y_LUNGHEZZA_GENERA) ||
        (x>X_BOTTONE_GENERA-40 && x<X_BOTTONE_GENERA+X_LUNGHEZZA_GENERA+40 &&
         y>Y_BOTTONE_GENERA-1 && y<Y_BOTTONE_GENERA+Y_LUNGHEZZA_GENERA+1 &&
         getpixel(x,y)==WHITE))
      //Controllo che il numero massimo di bandiere non sia stato raggiunto
      if(*cont>=MAX_BANDIERE)
        controlloMassimoBandiere();
      else {
        do {
          //CREA LA BANDIERA
          bandiera=creaBandiera();
          //Il ciclo termina quando la bandiera creata non esiste
        } while(bandieraEsiste(bandiera,bandiereSalvate,*cont));
        stampaBandiera(bandiera, x1, y1, x2, y2);
        //Controllo che l'utente voglia salvare la bandiera
        if(chiediConferma("Vuoi salvare questa bandiera?",X_SALVA,Y_SALVA)) {
          bandiereSalvate[*cont]=bandiera;
          (*cont)++;
        }
      }
    //Il ciclo termina quando l'utente clicca sul tasto TORNA INDIETRO
  } while(!((x>X_BOTTONE_TORNAINDIETRO && x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO &&
             y>Y_BOTTONE_TORNAINDIETRO && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO) ||
            (x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO+40 && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO &&
             getpixel(x,y)==CYAN)));
}
//GRAFICA GENERA BANDIERE
void graficaGeneraBandiere() {
  Tstringa strTornaIndietro= {'T','O','R','N','A',' ','I','N','D','I','E','T','R','O','\0'};
  Tstringa strGenera = {'G','E','N','E','R','A','\0'};
  Tstringa strGeneraCasuale = {'G','E','N','E','R','A',' ','I','N',' ','M','O','D','O',' ','C','A','S','U','A','L','E','\0'};
  bottone(X_BOTTONE_TORNAINDIETRO,Y_BOTTONE_TORNAINDIETRO,X_LUNGHEZZA_TORNAINDIETRO,Y_LUNGHEZZA_TORNAINDIETRO,CYAN);
  creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_TORNAINDIETRO, Y_TORNAINDIETRO, strTornaIndietro);
  bottone(X_BOTTONE_GENERA,Y_BOTTONE_GENERA,X_LUNGHEZZA_GENERA,Y_LUNGHEZZA_GENERA,WHITE);
  creaTesto(BLACK, WHITE, DEFAULT_FONT, 4, X_GENERA, Y_GENERA, strGenera);
  bottone(X_BOTTONE_GENERACASUALE,Y_BOTTONE_GENERACASUALE,X_LUNGHEZZA_GENERACASUALE,Y_LUNGHEZZA_GENERACASUALE,RED);
  creaTesto(BLACK, RED, DEFAULT_FONT, 2, X_GENERACASUALE, Y_GENERACASUALE, strGeneraCasuale);
}
//SCRITTURA SUL FILE
void scritturaSuFile(Tbandiera buffer[], int cont) {
  Tfile fpBandiere;
  remove("bandiere.txt");
  fpBandiere=fopen("bandiere.txt", "wb");
  fwrite(buffer, sizeof(Tbandiera), cont, fpBandiere);
  fclose(fpBandiere);
}
//LETTURA DAL FILE
int letturaDaFile(Tbandiera buffer[]) {
  Tfile fpBandiere;
  int cont;
  fpBandiere=fopen("bandiere.txt", "rb");
  cont=fread(buffer,sizeof(Tbandiera), MAX_BANDIERE, fpBandiere);
  fclose(fpBandiere);
  return cont;
}
//BANDIERA SELEZIONATA
bool bandieraSelezionata(Tcoordinata x, Tcoordinata y, int *posizione, int cont, Tbandiera bandiereSalvate[]) {
  int i, x1=100, y1=140, x2=150, y2=170, distanzax=10, distanzay=30;
  //Trovo la posizione della bandiera
  for(i=0; i<cont; i++) {
    if(i%10==0) {
      x1=100;
      x2=150;
      y1=y1+60;
      y2=y2+60;
    } else {
      x1=x1+60;
      x2=x2+60;
    }
    //Stampo una cornice rossa intorno alla bandiera cliccata
    if(x>x1 && x<x2 && y>y1 && y<y2) {
      *posizione=i;
      setcolor(RED);
      rectangle(x1-5, y1-5, x2+5, y2+5);
      setfillstyle(SOLID_FILL, RED);
      floodfill(x1, y1, RED);
      stampaBandiera(bandiereSalvate[i], x1, y1, x2, y2);
      //Chiedo all'utente se vuole cancellare la bandiera selezionata
      if(chiediConferma("Vuoi cancellare questa bandiera?", X_CANCELLA, Y_CANCELLA))
        return 1;
    }
  }
  return 0;
}
//CANCELLA BANDIERA
void cancellaBandiera(Tbandiera bandiereSalvate[], int posizione, int* cont) {
  int i;
  (*cont)--;
  //Sposto le bandiere di una posizione indietro
  for(i=posizione; i<*cont; i++)
    bandiereSalvate[i]=bandiereSalvate[i+1];
}
//CHIEDI CONFERMA
bool chiediConferma(Tstringa frase,Tcoordinata xFrase, Tcoordinata yFrase) {
  Tcoordinata x, y, x1=350, y1=450, x2=390, y2=490;
  Tstringa si= {'S','I','\0'};
  Tstringa no= {'N','O','\0'};
  //Stampo la casella del SI
  setcolor(GREEN);
  rectangle(x1, y1, x2, y2);
  creaTesto(GREEN,BLACK,DEFAULT_FONT,2,x1+5,y1+12,si);
  //Stampo la casella del NO
  x1+=60;
  x2+=60;
  setcolor(RED);
  rectangle(x1, y1, x2, y2);
  creaTesto(RED,BLACK,DEFAULT_FONT,2,x1+5,y1+12,no);
  //Stampo la frase
  creaTesto(WHITE, BLACK, DEFAULT_FONT, 2, xFrase, yFrase, frase);
  x1-=60;
  x2-=60;
  //L'utente deve cliccare o SI o NO
  do {
    attendiClickDelMouse(&x, &y);
    if(x>x1 && x<x2 && y>y1 && y<y2) {
      return 1;
    } else if(x>x1+60 && x<x2+60 && y>y1 && y<y2) {
      return 0;
    }
  } while(1);
}
//CREA BANDIERA
Tbandiera creaBandiera() {
  Tbandiera bandiera;
  //Riempimento struttura
  bandiera.righeOcolonne=rand()%2;
  bandiera.numeroStrisce=rand()%2+1;
  bandiera.colore1=rand()%8+8;
  bandiera.colore2=rand()%8+8;
  bandiera.colore3=rand()%8+8;
  return bandiera;
}
//CONTROLLO MASSIMO BANDIERE
void controlloMassimoBandiere() {
  Tcoordinata x,y;
  Tstringa StrRiga1= {'H','A','I',' ','R','A','G','G','I','U','N','T','O',' ','I','L',' ','M','A','S','S','I','M','O','\0'};
  Tstringa StrRiga2= {'N','U','M','E','R','O',' ','D','I',' ','B','A','N','D','I','E','R','E','\0'};
  do {
    cleardevice();
    creaTesto(RED, WHITE, 3, 5, X_MASSIMOBANDIERE, Y_MASSIMOBANDIERE, StrRiga1);
    creaTesto(RED, WHITE, 3, 5, X_MASSIMOBANDIERE+60, Y_MASSIMOBANDIERE+45, StrRiga2);
    bottone(X_BOTTONE_OK, Y_BOTTONE_OK, X_LUNGHEZZA_OK, Y_LUNGHEZZA_OK, RED);
    creaTesto(BLACK, RED, 3, 5, X_OK, Y_OK, "OK");
    attendiClickDelMouse(&x, &y);
    //Il ciclo termina quando l'utente preme il tasto OK
  } while(!((x>X_BOTTONE_OK && x<X_BOTTONE_OK+X_LUNGHEZZA_OK &&
             y>Y_BOTTONE_OK && y<Y_BOTTONE_OK+Y_LUNGHEZZA_OK) ||
            (x>X_BOTTONE_OK-40 && x<X_BOTTONE_OK+X_LUNGHEZZA_OK+40 &&
             y>Y_BOTTONE_OK-1 && y<Y_BOTTONE_OK+Y_LUNGHEZZA_OK+1 &&
             getpixel(x,y)==RED)));
}
//BANDIERA ESISTE
bool bandieraEsiste(Tbandiera bandiera, Tbandiera bandiereSalvate[], int cont) {
  int i;
  //Se il contatore è 0 non ci sono altre bandiere
  if(cont==0)
    return 0;
  //Confronto tutte le bandiere salvate
  for(i=0; i<cont; i++)
    if(confrontaBandiere(bandiera,bandiereSalvate[i]))
      return 1; //la bandiera esiste già

  return 0;
}
//**************************** FUNZIONI COMUNI *******************************//
//CREA TESTO
void creaTesto(int colore, int coloreSfondo, int font, int dimensioneCarattere, Tcoordinata xCoor, Tcoordinata yCoor, Tstringa frase) {
  setcolor(colore);
  setbkcolor(coloreSfondo);
  settextstyle(font, HORIZ_DIR, dimensioneCarattere);
  outtextxy(xCoor, yCoor, frase);
  setbkcolor(BLACK);
}
//ATTENDI CLICK DEL MOUSE
void attendiClickDelMouse(Tcoordinata *x, Tcoordinata *y) {
  clearmouseclick(WM_LBUTTONDOWN);
  //Il ciclo termina con il click del mouse
  while(!ismouseclick(WM_LBUTTONDOWN)) {
    delay(10);
  }
  *x=mousex();
  *y=mousey();
}
//STAMPA BANDIERA
void stampaBandiera(Tbandiera bandiera, Tcoordinata x1, Tcoordinata y1, Tcoordinata x2, Tcoordinata y2) {
  //Stampo la cornice della bandiera
  setcolor(WHITE);
  rectangle(x1, y1, x2, y2);
  if(bandiera.righeOcolonne) {                         //(1) colonne
    //Stampo una bandiera con una riga verticale in mezzo
    if(bandiera.numeroStrisce==1) {
      line(x1+((x2-x1)/2), y1, x1+((x2-x1)/2), y2);
      setfillstyle(SOLID_FILL, bandiera.colore1);
      floodfill(x1+1, y1+1, WHITE);
      setfillstyle(SOLID_FILL, bandiera.colore2);
      floodfill(x1+((x2-x1)/2)+1, y1+1, WHITE);
    }
    //Stampo una bandiera con due righe verticali
    else {
      line(x1+((x2-x1)/3), y1, x1+((x2-x1)/3), y2);
      line(x2-((x2-x1)/3), y1, x2-((x2-x1)/3), y2);
      setfillstyle(SOLID_FILL, bandiera.colore1);
      floodfill(x1+1, y1+1, WHITE);
      setfillstyle(SOLID_FILL, bandiera.colore2);
      floodfill(x1+((x2-x1)/3)+1, y1+1, WHITE);
      setfillstyle(SOLID_FILL,bandiera.colore3);
      floodfill(x2-((x2-x1)/3)+1, y1+1, WHITE);
    }
  } else {                                             //(0) righe
    //Stampo una bandiera con una riga orizzontale in mezzo
    if(bandiera.numeroStrisce==1) {
      line(x1, y1+((y2-y1)/2), x2, y1+((y2-y1)/2));
      setfillstyle(SOLID_FILL, bandiera.colore1);
      floodfill(x1+1, y1+1, WHITE);
      setfillstyle(SOLID_FILL, bandiera.colore2);
      floodfill(x1+1, y1+((y2-y1)/2)+1, WHITE);
    }
    //Stampo una bandiera con due righe orizzontali
    else {
      line(x1, y1+((y2-y1)/3), x2, y1+((y2-y1)/3));
      line(x1, y2-((y2-y1)/3), x2, y2-((y2-y1)/3));
      setfillstyle(SOLID_FILL, bandiera.colore1);
      floodfill(x1+1, y1+1, WHITE);
      setfillstyle(SOLID_FILL, bandiera.colore2);
      floodfill(x1+1, y1+((y2-y1)/3)+1, WHITE);
      setfillstyle(SOLID_FILL, bandiera.colore3);
      floodfill(x1+1, y2-((y2-y1)/3)+1, WHITE);
    }
  }
}
//BOTTONE
void bottone(int x, int y,int lunghezzax,int lunghezzay,int colore) {
  setcolor(colore);
  setfillstyle(SOLID_FILL, colore);
  circle(x, y+lunghezzay/2, lunghezzay/2);
  floodfill(x, y+lunghezzay/2, colore);
  circle(x+lunghezzax, y+lunghezzay/2, lunghezzay/2);
  floodfill(x+lunghezzax, y+lunghezzay/2, colore);
  rectangle(x, y, x+lunghezzax, y+lunghezzay);
  floodfill(x+lunghezzax/2, y+1, colore);
}

//******************************* REGOLAMENTO ********************************//
void regolamento() {
  Tcoordinata x,y,xScritta=40,yScritta;
  int raggio=30;
  Tcoordinata x1LineaOrizzontale=50,y1LineaOrizzontale=50,x2LineaOrizzontale=750,y2LineaOrizzontale=580;
  Tcoordinata x1LineaVerticale=20,y1LineaVerticale=80,x2LineaVerticale=780,y2LineaVerticale=550;
  Tstringa StrTornaIndietro = {'T','O','R','N','A',' ','I','N','D','I','E','T','R','O','\0'};
  Tstringa riga = " ";
  Tfile fpRegolamento;

  do {
    cleardevice();
    bottone(X_BOTTONE_TORNAINDIETRO,Y_BOTTONE_TORNAINDIETRO,X_LUNGHEZZA_TORNAINDIETRO,Y_LUNGHEZZA_TORNAINDIETRO,CYAN);
    creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_TORNAINDIETRO, Y_TORNAINDIETRO, StrTornaIndietro);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    circle(x1LineaOrizzontale,y1LineaVerticale,raggio);
    floodfill(x1LineaOrizzontale,y1LineaVerticale,WHITE);
    circle(x2LineaOrizzontale,y1LineaVerticale,raggio);
    floodfill(x2LineaOrizzontale,y1LineaVerticale,WHITE);
    circle(x1LineaOrizzontale,y2LineaVerticale,raggio);
    floodfill(x1LineaOrizzontale,y2LineaVerticale,WHITE);
    circle(x2LineaOrizzontale,y2LineaVerticale,raggio);
    floodfill(x2LineaOrizzontale,y2LineaVerticale,WHITE);
    line(x1LineaOrizzontale,y1LineaOrizzontale,x2LineaOrizzontale,y1LineaOrizzontale);
    line(x1LineaVerticale,y1LineaVerticale,x1LineaVerticale,y2LineaVerticale);
    line(x2LineaVerticale,y1LineaVerticale,x2LineaVerticale,y2LineaVerticale);
    line(x1LineaOrizzontale,y2LineaOrizzontale,x2LineaOrizzontale,y2LineaOrizzontale);
    floodfill(WINX/2,WINY/2,WHITE);

    yScritta=80;
    //Prelevo il reglamento dal file e lo stampo
    fpRegolamento=fopen("regolamento.txt","r");
    while(fgets(riga,MAX_STRINGA,fpRegolamento)!=NULL) {
      creaTesto(BLACK, WHITE, 1, 1, xScritta, yScritta, riga);
      yScritta+=30;
    }
    fclose(fpRegolamento);
    attendiClickDelMouse(&x,&y);
    //Il ciclo termina quando l'utente clicca sul tasto TORNA INDIETRO
  } while(!((x>X_BOTTONE_TORNAINDIETRO && x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO &&
             y>Y_BOTTONE_TORNAINDIETRO && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO) ||
            (x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO+40 && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO &&
             getpixel(x,y)==CYAN))); //il ciclo termina quando premo sul bottone "TORNA INDIETRO"
}
//*****************************FUNZIONI GIOCA*********************************//
//GIOCA
void gioca() {
  int valoreGioca;
  Tstringa StrBandiereInsufficienti= {'N','O','N',' ','S','O','N','O',' ','S','T','A','T','E',' ','C','R','E','A','T','E',' ','A','B','B','A','S','T','A','N','Z','A',' ','B','A','N','D','I','E','R','E','\0'};
  Tutente datiUtente;
  Tstringa stringa;
  Tfile fpclassifica;
  int x,y;
  int xi,xl,yi,yl;

//Menù inserimento nome
  inserisciNome(&datiUtente);

  valoreGioca=giocaPartita(&datiUtente);
  // se gioca return 0 -> partita completata con successo
  // se gioca return 1 -> torna indietro / partita abbandonata
  // se gioca return 2 -> non ci sono bandiere a sufficienza
  // se gioca return 3 -> partita non terminata a causa del tempo
  if(valoreGioca==1) // se torna indietro/partita abbandonata
    cleardevice();

  if(valoreGioca==2) { //se non ci sono bandiere a sufficienza
    cleardevice();
    bottone(WINX/2-330, 50-2, 660, 20, RED);
    creaTesto(15, RED, DEFAULT_FONT, 2, WINX/2-330, 50, StrBandiereInsufficienti);
    delay(3000);
  }

  if(valoreGioca==0) { //se completato con successo
    fpclassifica=fopen("classifica.dat","ab");
    fwrite(&datiUtente,sizeof(datiUtente),1,fpclassifica); // salva struttura utente nel file
    fclose(fpclassifica);

    xi=WINX-200;
    xl=160;
    yi=WINY-50-7;
    yl=30;
    bottone(xi, yi, xl, yl, CYAN);
    creaTesto(15, CYAN, DEFAULT_FONT, 2, WINX-200, WINY-50, "CLASSIFICA");
    //L'utente deve cliccare su VISUALIZZA CLASSIFICA
    do {
      attendiClickDelMouse(&x,&y);
    } while(!((x>xi && x<xi+xl && y>yi && y<yi+yl) || (x<xi+xl+40 && y<yi+yl && getpixel(x,y)==CYAN)));
    visualizzaClassifica();
  }
  cleardevice();
}
//INSERIMENTO NOME
int inserisciNome(Tutente* datiUtente) {
  Tstringa nome,stringa;
  char car;
  int i=0;
  cleardevice();
  creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-280, 50, "INSERISCI IL NOME UTENTE:");
  creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-200, 80, "(PREMERE INVIO AL TERMINE)");
  creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-330, 150, "NOME: ");
  //Il ciclo permette all'utente di scrivere il nome
  do {
    car=getch();
    if((car>='a' && car<='z') || (car>='A' && car<='Z') || (car>='1' && car<='9') || car==32 || car=='_' || car=='-') {
      nome[i]=car;
      i++;
      nome[i]=0;
      sprintf(stringa,"NOME: %s",nome);
      creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-330, 150, stringa);
    }
    if(car==8) { //cancella il carattere scritto
      if(i!=0)
        i--;
      nome[i]=0;
      sprintf(stringa,"NOME: %s                                     ",nome);
      creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-330, 150, stringa);
    }
    //Il ciclo termina quando viene premuto INVIO
  } while(car!=13);
  strcpy(datiUtente->nome,nome);
}
//GIOCA PARTITA
int giocaPartita(Tutente* datiUtente) {
  time_t tempoInizio;
  Tstringa stringa;
  Tbandiera bandiere[DIM][DIM];
  Tbandiera appoggio[DIM][DIM];
  int dim, tempoMax;	                                                                //variabili dedicate a tempo e dimensione in base alla modalita
  int c=0, tentativi=0, abbandona=0, tempoEsaurito=0, tempoImpiegato;
  int valore, coppieDiFila=0,bandiereMinime;

  if((abbandona=sceltaDifficolta(&dim, &tempoMax))==1) return 1;                        //menu scelta difficolta. Se l'utente ha abbandonato ritorna 1
  if((bandiereMinime=letturaFile(bandiere, dim))==1) return 2;                          //prelevo dal file le bandiere e le metto in una matrice. Se non ci sono abbastanza bandiere ritorna 2
  duplicaBandiere(bandiere, dim);
  mescolaBandiere(bandiere, dim);                                                       //le bandiere vengono duplicate e mescolate
  stampaMatrice(bandiere, dim);                                                         //stampo le bandiere per formare il campo da gioco
  riempiAppoggio(appoggio, dim);                                                        //riempi la matrice di appoggio con il retro bandiere
  bottone(WINX/2-320, 50-2, 660, 20, DARKGRAY);
  creaTesto(15, DARKGRAY, DEFAULT_FONT, 2, WINX/2-320, 50, "HAI 5 SECONDI PER MEMORIZZARE LE BANDIERE");
  delay(5000);
  tempoInizio=time(NULL);
  do {
    cleardevice();
    stampaMatrice(appoggio,dim);                                                        //stampo le bandiere coperte
    creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-270, 10, "TROVA TUTTE LE COPPIE DI BANDIERE");
    valore=controllaCaselleScoperte(appoggio, bandiere, &c, dim, tempoInizio, tempoMax);//controllo che l'utente scopra due caselle identiche, se è vero rimangono scoperte
    if(valore==1) return 1;					                                            //se valore 1 abbandona il gioco
    if(valore==0)  coppieDiFila=coppieDiFila+1;                                         //se valore 0 coppia corretta
    else coppieDiFila=0;			                                                    //se valore diverso da 0 coppia errata, azzera coppie di fila
    if(coppieDiFila>=2 && c<((dim*dim)/2)) {                                            //aggiungi 5 secondi se due coppie corrette di fila. Solo se non è finita la partita
      tempoMax=tempoMax+5;                                                              //aggiungi 5 secondi al tempo massimo
      bottone(WINX/2-320, 50-2, 610, 20, GREEN);
      creaTesto(15, GREEN, DEFAULT_FONT, 2, WINX/2-320, 50, "SONO STATI AGGIUNTI 5 SECONDI DI BONUS");
      delay(1000);
    }
    tempoImpiegato=difftime(time(NULL), tempoInizio);
    if(tempoMax<tempoImpiegato) tempoEsaurito=1;                                        //se superato tempo massimo termina la partita
    tentativi++;
  } while(c<((dim*dim)/2) && !tempoEsaurito);

  cleardevice();
  stampaMatrice(appoggio, dim);                                                         //mostra matrice memori a fine gioco

  if(tempoEsaurito) {
    creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-230, 50, "TEMPO LIMITE SUPERATO, RIPROVA");
    delay(3000);
    return 3;                                                                           //se è finito il tempo ritorna 3
  }

  creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-310, 40, "HAI COMPLETATO IL MEMORY!");
  sprintf(stringa, "TENTATIVI UTILIZZATI: %d", tentativi);
  creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-200, 80, stringa);
  sprintf(stringa, "TEMPO IMPIEGATO: %d secondi", tempoImpiegato);
  creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-200, 110, stringa);
  datiUtente->tempo=tempoImpiegato;								                        // salvo il tempo impiegato
  return 0;                                                                             //se completato con successo ritorna 0
}
//LETTURA FILE
int letturaFile(Tbandiera bandiere[][DIM], int dim) {
  int i, j, numBandiere=0;
  Tfile fpBandiere;
  fpBandiere=fopen("bandiere.txt","rb");
  //Riempie metà matrice delle bandiere
  for(j=0; j<dim/2; j++) {
    for(i=0; i<dim; i++) {
      if(fread(&bandiere[j][i], sizeof(Tbandiera), 1, fpBandiere)>0) {
        numBandiere++;
      }
    }
  }
  fclose(fpBandiere);
  //Controlla se ci sono abbastanza bandiere nel file
  if(numBandiere>=(dim*dim)/2)
    return 0;
  return 1;
}
//DUPLICA BANDIERE
void duplicaBandiere(Tbandiera bandiere[][DIM], int dim) {
  int i, j;
  for(j=0; j<dim/2; j++)
    for(i=0; i<dim; i++)
      bandiere[(j+dim/2)][i]=bandiere[j][i];
}
//MESCOLA BANDIERE
void mescolaBandiere(Tbandiera bandiere[][DIM], int dim) {
  Tbandiera temp;
  int i1, j1, i2, j2, i;
  for(i=0; i<30; i++) {
    i1=rand()%dim;
    j1=rand()%dim;
    i2=rand()%dim;
    j2=rand()%dim;
    temp=bandiere[i1][j1];
    bandiere[i1][j1]=bandiere[i2][j2];
    bandiere[i2][j2]=temp;
  }
}
//STAMPA MATRICE
void stampaMatrice(Tbandiera bandiere[][DIM], int dim) {
  Tbandiera bandiera;
  int x=WINX/2-(DIST+LATOBANDIERE1)*(dim/2),y=WINY/2-(DIST+LATOBANDIERE2)*(dim/2)+20; // pos prima casella
  cleardevice();
  int j, i;
  for(j=0; j<dim; j++) {
    for(i=0; i<dim; i++) {
      bandiera=bandiere[j][i];
      stampaBandiera(bandiera, x, y, x+LATOBANDIERE1, y+LATOBANDIERE2);
      x=x+DIST+LATOBANDIERE1;
    }
    x=WINX/2-(DIST+LATOBANDIERE1)*(dim/2);
    y=y+DIST+LATOBANDIERE2;
  }
}
//RETRO BANDIERA
Tbandiera retroBandiera() {
  Tbandiera retro;
  retro.colore1=RETROBANDIERE;
  retro.colore2=RETROBANDIERE;
  retro.colore3=RETROBANDIERE;
  retro.numeroStrisce=0;
  retro.righeOcolonne=1;
  return retro;
}
//RIMEPI APPOGGIO
void riempiAppoggio(Tbandiera appoggio[][DIM], int dim) {
  int j, i;
  for(j=0; j<dim; j++)
    for(i=0; i<dim; i++)
      appoggio[j][i]=retroBandiera(); //copia retro bandiera nella posizione j i della matrice
}
//CONTROLLA CASELLE SCOPERTE
int controllaCaselleScoperte(Tbandiera appoggio[][DIM], Tbandiera bandiere[][DIM], int* c, int dim, time_t tempoInizio, int tempoMax) {
  int x, y, j, i, k, cont=0, abbandona=0;
  Tbandiera bandiereScoperte[2];
  int posyScoperte[2], posxScoperte[2];
  int xi=WINX/2-(DIST+LATOBANDIERE1)*(dim/2),yi=WINY/2-(DIST+LATOBANDIERE2)*(dim/2)+20;		//pos prima casella
  bottone(X_BOTTONE_TORNAINDIETRO,Y_BOTTONE_TORNAINDIETRO,X_LUNGHEZZA_TORNAINDIETRO-40,Y_LUNGHEZZA_TORNAINDIETRO,CYAN);
  creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_TORNAINDIETRO, Y_TORNAINDIETRO, "ABBANDONA");
  do {
    do {
      abbandona=attendiClickDelMouseTempo(&x, &y, tempoInizio, tempoMax);
      if((x>X_BOTTONE_TORNAINDIETRO && x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO-40 &&
          y>Y_BOTTONE_TORNAINDIETRO && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO) ||
          (x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO+40-40 && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO &&
           getpixel(x,y)==CYAN)) // termina quando premo sul bottone "ABBANDONA"
        abbandona=1;
      if(abbandona)
        return 1;
    } while(getpixel(x,y)==0);
    i=((x-xi)/(LATOBANDIERE1+DIST)); //colonna bandiera girata
    j=((y-yi)/(LATOBANDIERE2+DIST)); //riga bandiera girata
    x=xi+(LATOBANDIERE1+DIST)*i;	 //x bandiera girata
    y=yi+(LATOBANDIERE2+DIST)*j;	 //y bandiera girata

    bandiereScoperte[cont]=bandiere[j][i];
    posyScoperte[cont]=j;
    posxScoperte[cont]=i;
    if(confrontaBandiere(retroBandiera(), appoggio[j][i])) {	                  //se corrisponde ad un retro bandiera
      setfillstyle(SOLID_FILL, 0);	                                              //cancellla la casella copri,per stampare correttamente la bandiera selezionata
      floodfill(x+5,y+5,0);
      stampaBandiera(bandiere[j][i], x, y, x+LATOBANDIERE1, y+LATOBANDIERE2);
      if(!(posxScoperte[0]==posxScoperte[1] && posyScoperte[0]==posyScoperte[1])) // se non è la stessa casella
        cont++;		                                                              //scoperta una delle due caselle
    }
  } while(cont<2); // fino a quando non vengono girate due bandiere valide

  if(confrontaBandiere(bandiereScoperte[0], bandiereScoperte[1])) {               //se le bandiere girate sono uguali
    for(k=0; k<2; k++) {
      j=posyScoperte[k];
      i=posxScoperte[k];
      appoggio[j][i]=bandiere[j][i];
    }
    (*c)++;
    bottone(WINX/2-130, 50-2, 250, 20, GREEN);
    creaTesto(15, GREEN, DEFAULT_FONT, 2, WINX/2-130, 50, "COPPIA CORRETTA!");
    delay(1000);
    return 0;
  }	// se le bandiere girate sono diverse
  bottone(WINX/2-180, 50-2, 350, 20, RED);
  creaTesto(15, RED, DEFAULT_FONT, 2, WINX/2-180, 50, "COPPIA ERRATA! RIPROVA");
  delay(1000);
  return 2;
}
//CONFRONTA BANDIERE
int confrontaBandiere(Tbandiera bandiera1, Tbandiera bandiera2) {
  if(bandiera1.righeOcolonne==bandiera2.righeOcolonne && bandiera1.numeroStrisce==bandiera2.numeroStrisce &&
      bandiera1.colore1==bandiera2.colore1 && bandiera1.colore2==bandiera2.colore2) {
    if(bandiera1.numeroStrisce==2) { // solo se ha 3 strisce si confrnta anche il colore 3
      if(bandiera1.colore3==bandiera2.colore3)
        return 1; // sono uguali
    } else
      return 1;	  // sono uguali
  }
  return 0;		  // sono diverse
}
//SCELTA DIFFICOLTA'
int sceltaDifficolta(int* dim, int* tempoMax) {
  int x, y;
  int posx=285, posy=200;
  int lunghezzax=200, lunghezzay=40, dy;
  int valore;
  Tstringa strTornaIndietro = {'T','O','R','N','A',' ','I','N','D','I','E','T','R','O','\0'};
  dy=lunghezzay+20;
  cleardevice();
  bottone(X_BOTTONE_TORNAINDIETRO,Y_BOTTONE_TORNAINDIETRO,X_LUNGHEZZA_TORNAINDIETRO,Y_LUNGHEZZA_TORNAINDIETRO,CYAN);
  creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_TORNAINDIETRO, Y_TORNAINDIETRO, strTornaIndietro);
  creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-350, 80, "SCEGLI LA DIFFICOLTA DI GIOCO");

  bottone(posx, posy, lunghezzax, lunghezzay, LIGHTGREEN);		// bottone difficolta 1
  creaTesto(0, LIGHTGREEN, BOLD_FONT, 1, posx+65, posy+10, "EASY");
  bottone(posx, posy+60, lunghezzax, lunghezzay, YELLOW);		// bottone difficolta 2
  creaTesto(0, YELLOW, BOLD_FONT, 1, posx+50, posy+60+10, "NORMAL");
  bottone(posx, posy+120, lunghezzax, lunghezzay, LIGHTRED);	// bottone difficolta 3
  creaTesto(0, LIGHTRED, BOLD_FONT, 1, posx+65, posy+120+10, "HARD");
  bottone(posx, posy+180, lunghezzax, lunghezzay, RED);			// bottone difficolta 4
  creaTesto(0, RED, BOLD_FONT, 1, posx+50, posy+180+10, "EXTREME");

  do {
    attendiClickDelMouse(&x, &y);
    valore=clickValido(x, y, dim, tempoMax, posx, posy,dy, lunghezzay);
    if(valore==2) return 1; // torna indietro al menu
  } while(valore!=1);
  return 0;
}
//CLICK VALIDO
int clickValido(int x, int y, int* dim, int* tempoMax, int posx, int posy, int dy, int ly) {
  //Controllo quale bottone viene premuto
  if(x>posx && x<posx+200) {
    if(y>posy && y<posy+ly) {
      *dim=DIMENSIONE_DIFFICOLTA1;
      *tempoMax=TEMPO_DIFFICOLTA1;
      return 1;
    }
    if(y>posy+dy && y<posy+dy+ly) {
      *dim=DIMENSIONE_DIFFICOLTA2;
      *tempoMax=TEMPO_DIFFICOLTA2;
      return 1;
    }
    if(y>posy+dy*2 && y<posy+dy*2+ly) {
      *dim=DIMENSIONE_DIFFICOLTA3;
      *tempoMax=TEMPO_DIFFICOLTA3;
      return 1;
    }
    if(y>posy+dy*3 && y<posy+dy*3+ly) {
      *dim=DIMENSIONE_DIFFICOLTA4;
      *tempoMax=TEMPO_DIFFICOLTA4;
      return 1;
    }
  }
  //Controllo che l'utente clicchi sul tasto TORNA INDIETRO
  if((x>X_BOTTONE_TORNAINDIETRO && x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO &&
      y>Y_BOTTONE_TORNAINDIETRO && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO) ||
      (x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO+40 && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO &&
       getpixel(x,y)==CYAN))
    return 2;
  return 0;
}
//ATTENDI CLICK DEL MOUSE TEMPO
int attendiClickDelMouseTempo(int *x, int *y, time_t tempoInizio, int tempoMax) {
  time_t tempo;
  Tstringa stringa;
  clearmouseclick(WM_LBUTTONDOWN);
  while(!ismouseclick(WM_LBUTTONDOWN) && tempoMax>difftime(time(NULL),tempoInizio)) {
    delay(10);
    tempo=difftime(time(NULL), tempoInizio);
    tempo=tempoMax-tempo;
    //Se mancano meno di 10 secondi la scritta diventa rossa
    if(tempo<10) {
      bottone(10+3, WINY-35-2, 430, 20, RED);
      sprintf(stringa, "TEMPO RIMANENTE: %d secondi", tempo);
      creaTesto(15, RED, DEFAULT_FONT, 2, 10, WINY-35,stringa);
    } else {
      sprintf(stringa, "TEMPO RIMANENTE: %d secondi", tempo);
      creaTesto(15, 0, DEFAULT_FONT, 2, 10, WINY-35, stringa);
    }
  }
  if(tempoMax<difftime(time(NULL), tempoInizio))
    return 1;
  *x=mousex();
  *y=mousey();
  return 0;
}
//VISUALIZZA CLASSIFICA
void visualizzaClassifica() {
  cleardevice();
  Tfile fpclassifica;
  Tcoordinata x,y;
  Tutente datiUtente;
  Tutente datiUtenti[10];
  Tstringa stringa;
  Tstringa strTornaIndietro = {'T','O','R','N','A',' ','I','N','D','I','E','T','R','O','\0'};
  int posy=100,n=0,p;
  int i,j;
  int temp;
  Tstringa tempStr;

  fpclassifica=fopen("classifica.dat","rb");
  while((fread(&datiUtente,sizeof(datiUtente),1,fpclassifica))>0) {
    datiUtenti[n]=datiUtente;
    n++;
  }
  fclose(fpclassifica);

  // ordina array di strutture dati utenti
  for(i=0; i<n; i++) {
    for(j=0; j<n-i-1; j++) {
      if(datiUtenti[j].tempo>datiUtenti[j+1].tempo) {
        temp=datiUtenti[j].tempo;
        datiUtenti[j].tempo=datiUtenti[j+1].tempo;
        datiUtenti[j+1].tempo=temp;
        strcpy(tempStr,datiUtenti[j].nome);
        strcpy(datiUtenti[j].nome,datiUtenti[j+1].nome);
        strcpy(datiUtenti[j+1].nome,tempStr);
      }
    }
  }
  creaTesto(15, 0, DEFAULT_FONT, 3, WINX/2-150, 50, "CLASSIFICA:");
  for(p=0; p<n; p++) {
    sprintf(stringa,"%d. %s ",p+1,datiUtenti[p].nome);
    creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-300, posy, stringa);
    sprintf(stringa," %d secondi",datiUtenti[p].tempo);
    creaTesto(15, 0, DEFAULT_FONT, 2, WINX/2-300+380, posy, stringa);
    posy=posy+50;
  }
  bottone(X_BOTTONE_TORNAINDIETRO,Y_BOTTONE_TORNAINDIETRO,X_LUNGHEZZA_TORNAINDIETRO,Y_LUNGHEZZA_TORNAINDIETRO,CYAN);
  creaTesto(BLACK, CYAN, DEFAULT_FONT, 1, X_TORNAINDIETRO, Y_TORNAINDIETRO, strTornaIndietro);
  do {
    attendiClickDelMouse(&x,&y);
  } while(!((x>X_BOTTONE_TORNAINDIETRO && x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO &&
             y>Y_BOTTONE_TORNAINDIETRO && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO) ||
            (x<X_BOTTONE_TORNAINDIETRO+X_LUNGHEZZA_TORNAINDIETRO+40 && y<Y_BOTTONE_TORNAINDIETRO+Y_LUNGHEZZA_TORNAINDIETRO &&
             getpixel(x,y)==CYAN)));
}
