#include <graphics.h>
#include <winbgim.h>
#include <ctime>
#include <cstdlib>
#include "..\include\functions.h"   // Merge un folder inapoi, dupa care intra in folder-ul "include"

#define LATIME 1200
#define INALTIME 1000
#define TITLU "Impartirea Careului"


/* Declara variabilele marcate ca "extern" in fisierul header "functions.h" */
unsigned int tabla[LINII][COLOANE];
unsigned int nrBuline = 1,WIN=0;

unsigned int nivel_1[8]={31,72,43,73,83,84,76,88},
             nivel_2[8]={54,65,75,46,67,77,78,88},
             nivel_3[8]={31,81,33,73,83,74,84,76},
             nivel_4[8]={12,62,83,24,75,56,28,78},
             nivel_5[8]={18,12,43,63,14,44,55,76},
             nivel_6[8]={11,22,33,44,55,66,77,88},
             nivel_7[8]={31,72,63,73,83,84,76,68},
             nivel_8[8]={61,33,43,26,56,17,18,88};
int main() {
    int eroare, x, y, linie, coloana, patrat = 7, culoare = 1;

    /* Initializeaza valoarea aleatoare */
    srand(time(NULL));

    // Initializeaza fereastra
    initwindow(LATIME, INALTIME, TITLU);

    // Verificare erori si inchiderea imediata a programului in cazul in care acestea apar, informand utilizatorul
    eroare = graphresult();

    if (eroare != grOk) {    // a aparut o eroare
        cout << "[Eroare]: " << grapherrormsg(eroare) << endl;
        cout << "Apasati orice tasta pentru a opri programul..." << endl;

        getch();
        return -1;  // inchiderea programului si indicarea faptului ca procesul nu s-a terminat cu succes
    }
start:
    WIN = 0;
    patrat = 7;
    culoare = 1;

    // Deseneaza tabla de joc
    creeaza_tabla();
    setactivepage(0);

    // Creeaza butoanele
    butoane_nivele();
    soft_reset();
    new_game();
    buton_afisare_instructiuni();

    getmouseclick(WM_LBUTTONDOWN,x,y);

    // Verificare pentru butonul "INSTRUCTIUNI"
    if (x < 675 && y < 50 && x > 430 && y > 10) {
        instructiuni();
    }

    // Verificare pentru butonul "RANDOM"
    if (x > 1000 && y > 180 && x < 1150 && y < 230) {
        deseneaza_buline_random();
        deseneaza_sageata(180);
    }

    // Verificare pentru butonul "CUSTOM"

    else if(x < 1150 && y < 290 && x > 1000 && y > 240)
    { deseneaza_sageata(240);
        while(nrBuline <= 8)
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if (x < 675 && y < 50 && x > 430 && y > 10) {
            // Verificare pentru butonul "INSTRUCTIUNI"
            instructiuni();
            }else if (x < 420 && y < 50 && x > 220 && y > 10)
            goto restart_mare2;
            else{
                deseneaza_bulina(x, y);
                getmouseclick(WM_RBUTTONDOWN,x,y);
                sterge_bulina(x,y);
            }
        }
    }else if (x < 1150 && y < 350 && x > 1000 && y > 300){
        deseneaza_buline_nivel(nivel_1);
        deseneaza_sageata(300);}
    else if(x < 1150 && y < 410 && x > 1000 && y > 360){
        deseneaza_buline_nivel(nivel_2);
        deseneaza_sageata(360);}
    else if(x < 1150 && y < 470 && x > 1000 && y > 420){
        deseneaza_buline_nivel(nivel_3);
        deseneaza_sageata(420);}
    else if(x < 1150 && y < 530 && x > 1000 && y > 480){
        deseneaza_buline_nivel(nivel_4);
        deseneaza_sageata(480);}
    else if(x < 1150 && y < 590 && x > 1000 && y > 540){
        deseneaza_buline_nivel(nivel_5);
        deseneaza_sageata(540);}
    else if(x < 1150 && y < 650 && x > 1000 && y > 600){
        deseneaza_buline_nivel(nivel_6);
        deseneaza_sageata(600);}
    else if(x < 1150 && y < 710 && x > 1000 && y > 660){
        deseneaza_buline_nivel(nivel_7);
        deseneaza_sageata(660);}
    else if(x < 1150 && y < 770 && x > 1000 && y > 720){
        deseneaza_buline_nivel(nivel_8);
        deseneaza_sageata(720);}
    else
        goto start;

bucla:
    while(true)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);

        // Verificare pentru butonul "SOFT RESET"
        if(x < 210 && y < 50 && x > 10 && y > 10)
        { restart_mic2:
            WIN=0;
                for(int i=1;i<=8;i++)
                    for(int j=1;j<=8;j++)
                    {
                        setfillstyle(SOLID_FILL,0);
                            floodfill(j*50+355,i*50+355,15);
                      if(tabla[i][j] == 1)
                         tabla[i][j] = LIBER;
                       if(tabla[i][j] == 3)
                       {
                          tabla[i][j] = OCUPAT;
                          setfillstyle(SOLID_FILL, 8);
                          floodfill(j*50+375,i*50+375,15);

                    }
                    }
                culoare = 1;
                patrat = 7;
                goto bucla;
        }else if (x < 420 && y < 50 && x > 220 && y > 10) {
            restart_mare2:
            // Verificare pentru butonul "NEW GAME"
            for(int i=1;i<=8;i++)
                    for(int j=1;j<=8;j++)
                        tabla[i][j]=LIBER;
                    setfillstyle(SOLID_FILL,0);
                   floodfill(1, 1, LIGHTRED);   // umple pana cand gaseste acea culoare (culoare pe care noi nu o folosim)
                   nrBuline = 1;
                    goto start;

        }else if (x < 675 && y < 50 && x > 430 && y > 10) {
            // Verificare pentru butonul "INSTRUCTIUNI"
            instructiuni();
        }
else if(x < 800 && y < 800 && x > 400 && y > 400)
{
        linie = (y - 400) / 50 + 1;
        coloana = (x - 400) / 50 + 1;

        if(tabla[linie][coloana] == OCUPAT)
        {   setfillstyle(SOLID_FILL,culoare);
            floodfill((x - 400) / 50 * 50 +425,(y - 400) / 50 * 50 +425, WHITE);
            setcolor(culoare);
            culoare++;
            tabla[linie][coloana] = 3;
            for(int i = 1; i <= 4; i++) {
                rectangle((x - 400) / 50 * 50 + i + 400, (y - 400) / 50 * 50 + i + 400,
                          (x - 400) / 50 * 50 + 50 - i + 400, (y - 400) / 50 * 50 + 50 - i + 400);
            }

            while(patrat)
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);

                if(x < 210 && y < 50 && x > 10 && y > 10)
                    goto restart_mic2;
                if (x < 420 && y < 50 && x > 220 && y > 10)
                    goto restart_mare2;
                if(x > 400 && x < 800 && y > 400 && y < 800) {
                    if(((((x - 400) / 50 + 2 == coloana) || ((x - 400) / 50 == coloana)) && (linie == (y - 400) / 50 + 1)) ||
                       ((((y - 400) / 50 + 2 == linie) || ((y - 400) / 50 == linie)) && (coloana == (x - 400) / 50 + 1))) {
                        if(tabla[(y - 400) / 50 + 1][(x - 400) / 50 + 1] == 0)
                        {
                            for(int i = 1; i <= 4; i++)
                                rectangle((x - 400) / 50 * 50 + i + 400, (y - 400) / 50 * 50 + i + 400,
                                          (x - 400) / 50 * 50 + 50 - i + 400, (y - 400) / 50 * 50 + 50 - i + 400);
                            WIN++;
                            patrat--;
                            linie = (y - 400) / 50 + 1;
                            coloana = (x - 400) / 50 + 1;
                            tabla[linie][coloana] = 1;
                            if(WIN==56)
                               win();
                        } // sfarsit if
                    }   // sfarsit if
                } // sfarsit if
            }   // sfarsit while
        }   // sfarsit if mare
    }
        reseteaza_stil();
        patrat = 7;
    }   // sfarsit while mare

    // "curatare"
    getch();
    closegraph();
    return 0;
}
