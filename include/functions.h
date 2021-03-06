#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

#define LATIME_TABEL 400
#define INALTIME_TABEL 400
#define LINII 9
#define COLOANE 9
#define LIBER 0
#define OCUPAT 9
#define POZITIE_BUTON 15
#define PAGINA_PRINCIPALA 0
#define INSTRUCTIUNI 1
#define NUMAR_BULINE 8

/* Informeaza compilatorul despre existenta acestor variabile, iar acesta va cauta
 * declaratia acestor variabile in fisierele sursa ce includ aceasta librarie */
extern unsigned int tabla[LINII][COLOANE];
extern unsigned int nrBuline;


using namespace std;


/* Creeaza in mod vizual tabla de joc.
 * Tabelul este creat utilizand linii.
 */
void creeaza_tabla()
{
    char numar_linie[2];
    setcolor(15);
    // deseneaza conturul tablei cu linii intrerupte, groase
    setlinestyle(DASHED_LINE, 0x3333, THICK_WIDTH);
    line(LATIME_TABEL, INALTIME_TABEL, 2 * LATIME_TABEL, INALTIME_TABEL);
    line(LATIME_TABEL, INALTIME_TABEL, LATIME_TABEL, 2 * INALTIME_TABEL);
    line(LATIME_TABEL, 2 * INALTIME_TABEL, 2 * LATIME_TABEL, 2 * INALTIME_TABEL);
    line(2 * LATIME_TABEL, 2 * INALTIME_TABEL, 2 * LATIME_TABEL, INALTIME_TABEL);

    // restabileste stilul liniilor la normal pentru a desena celulele tablei
    setlinestyle(SOLID_LINE, 0x3333, NORM_WIDTH);
    settextstyle(10, HORIZ_DIR, 4);

    // numerotare pe verticala
    for (int i = 410, c = 1; c < 9; i += 50, c++) {
        itoa(c, numar_linie, 10);	// converteste variabila c in sir de caractere
        outtextxy(370, i, numar_linie);
    }

    // numerotare pe orizontala
    for (int i = 415, c = 1; c < 9; i += 50, c++) {
        itoa(c, numar_linie, 10);
        outtextxy(i, 365, numar_linie);
    }

    // deseneaza celulele tablei
    for (int i = 50; i <= 400; i += 50)
    {
        line(LATIME_TABEL + i, INALTIME_TABEL, LATIME_TABEL + i, 2 * INALTIME_TABEL);
        line(LATIME_TABEL, INALTIME_TABEL + i, 2 * LATIME_TABEL, INALTIME_TABEL + i);
    }
}


/* Deseneaza o bulina intr-un patrat din tabla de joc */
void deseneaza_bulina(int x, int y)
{
    unsigned int linie, coloana;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    linie = (y - LATIME_TABEL) / 50 + 1;
    coloana = (x - INALTIME_TABEL) / 50 + 1;

    if (x > LATIME_TABEL&& x < 2 * LATIME_TABEL && y > INALTIME_TABEL&& y < 2 * INALTIME_TABEL)
        if (tabla[linie][coloana] == LIBER)
        {
            nrBuline++;
            tabla[linie][coloana] = OCUPAT;
            circle(LATIME_TABEL + coloana * 50 - 25, INALTIME_TABEL + linie * 50 - 25, 20);
            fillellipse(LATIME_TABEL + coloana * 50 - 25, INALTIME_TABEL + linie * 50 - 25, 20, 20);
        }
}

void sterge_bulina(int x,int y)
{
    if(x > 400 && x < 800 && y > 400 && y < 800 && tabla[(y-400)/50+1][(x - 400) / 50 + 1]==OCUPAT)
            {

           nrBuline--;
           setcolor(0);
           circle((x-400)/50*50+425,(y - 400) / 50*50+425,20);
           setfillstyle(SOLID_FILL,0);
           fillellipse((x-400)/50*50+425,(y - 400) / 50*50+425,20,20);
           tabla[(y-400)/50+1][(x - 400) / 50 + 1]=0;
            }
}

void deseneaza_buline_nivel(unsigned int v[])
{
    for(int i=0;i<=7;i++)
        {
            tabla[v[i]/10][v[i]%10] = OCUPAT;
            circle(LATIME_TABEL + v[i]%10 * 50 - 25, INALTIME_TABEL + v[i]/10 * 50 - 25, 20);
            setfillstyle(SOLID_FILL, 8);
            fillellipse(LATIME_TABEL + v[i]%10 * 50 - 25, INALTIME_TABEL + v[i]/10 * 50 - 25, 20 , 20);
        }
}

void deseneaza_buline_random()
{
    unsigned int linie, coloana;
    for(int i=0;i<=7;i++)
        {
            linie = rand() % 8 + 1;
            coloana = rand() % 8 + 1;

            while (tabla[linie][coloana] == OCUPAT) {
                linie = rand() % 8 + 1;
                coloana = rand() % 8 + 1;
            }

            tabla[linie][coloana] = OCUPAT;
            circle(LATIME_TABEL + coloana * 50 - 25, INALTIME_TABEL + linie * 50 - 25, 20);
            setfillstyle(SOLID_FILL, 8);
            fillellipse(LATIME_TABEL + coloana * 50 - 25, INALTIME_TABEL + linie * 50 - 25, 20 , 20);
        }
}

/* Reseteaza culoarea fontului, precum si tipul si grosimea liniilor */
void reseteaza_stil() {
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0x3333, NORM_WIDTH);
}

/* Creeaza un buton cu numele "SOFT RESET" care va reseta mersul tuturor bulinelor, utilizatorului
 * resetandui-se progresul, astfel putand sa gaseasca un alt traseu de urmat.
 */
void soft_reset()
{
    outtextxy(POZITIE_BUTON, POZITIE_BUTON, "SOFT RESET");
    setcolor(WHITE);
    setlinestyle(DOTTED_LINE, 0x3333, THICK_WIDTH);
    rectangle(10, 10, 210, 50);

    // Reseteaza stilul liniei si culoarea
    reseteaza_stil();
}


/* Creeaza un buton cu numele "HARD RESET" care va reseta atat bulinele, cat si mersul acestora.
 * Este echivalentul repornirii jocului.
 */
void new_game() {
    outtextxy(POZITIE_BUTON * POZITIE_BUTON, POZITIE_BUTON, " NEW GAME ");
    setcolor(WHITE);
    setlinestyle(DOTTED_LINE, 0x3333, THICK_WIDTH);
    rectangle(220, 10, 420, 50);

    // Reseteaza stilul liniei si culoarea
    reseteaza_stil();
}


/* Creeaza un buton cu numele "INSTRUCTIUNI" care va afisa un set de reguli si informatii ce vor ajuta
 * utilizatorul sa inteleaga mecanismul de functionare al jocului, precum si ce optiuni are acesta.
 */
void buton_afisare_instructiuni() {
    outtextxy(2 * POZITIE_BUTON * POZITIE_BUTON - 10, POZITIE_BUTON, "INSTRUCTIONS");
    setcolor(WHITE);
    setlinestyle(DOTTED_LINE, 0x3333, THICK_WIDTH);
    rectangle(430, 10, 675, 50);

    // Reseteaza stilul liniei si culoarea
    reseteaza_stil();
}


/* Afiseaza instructiunile pe ecran si se ocupa de modul de functionare al butonului.
 * Prima functie afisa grafic butonul, aceasta il face sa functioneze.
 */
void instructiuni() {
    setactivepage(INSTRUCTIUNI);
    setvisualpage(INSTRUCTIUNI);

    // Butonul "INAPOI"
    outtextxy(POZITIE_BUTON, POZITIE_BUTON, "<-- INAPOI");
    setcolor(WHITE);
    setlinestyle(DOTTED_LINE, 0x3333, THICK_WIDTH);
    rectangle(10, 10, 210, 50);
    reseteaza_stil();

    outtextxy(0, 4 * POZITIE_BUTON, "[x] Cum se joaca acest joc?");
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(POZITIE_BUTON, 6 * POZITIE_BUTON, "-Pentru a incepe jocul, alegeti ce tip de joc doriti, folosind butoanele din dreapta.");
    outtextxy(POZITIE_BUTON, 8 * POZITIE_BUTON, "Acestea sunt: CUSTOM, RANDOM sau NIVELE.");
    outtextxy(POZITIE_BUTON, 12 * POZITIE_BUTON, "CUSTOM--- ofera optiunea crearii propriului nivel,plasand manual bulinele pe tabla");
    outtextxy(2 * POZITIE_BUTON, 14 * POZITIE_BUTON, "Click stanga=desenarea bulinei");
    outtextxy(2 * POZITIE_BUTON, 16 * POZITIE_BUTON, "Click dreapta=stergerea bulinei");
    outtextxy(POZITIE_BUTON, 18 * POZITIE_BUTON, "RANDOM--- genereaza pozitii aleatorii ale bulinelor pe tabla");
    outtextxy(POZITIE_BUTON, 20 * POZITIE_BUTON, "(exista posibilitatea de a fi imposibil de rezolvat)");
    outtextxy(POZITIE_BUTON, 22 * POZITIE_BUTON, "NIVELE--- genereaza pozitii preconcepute ale bulinelor(toate sunt rezolvabile)");
    outtextxy(POZITIE_BUTON, 24 * POZITIE_BUTON, "NEW GAME---incepe un joc nou");
    outtextxy(POZITIE_BUTON, 26 * POZITIE_BUTON, "SOFT RESET---reseteaza patratele");
    outtextxy(POZITIE_BUTON, 28 * POZITIE_BUTON, "Cand jocul incepe, selectati o bulina si ocupati 8 spatii continue cu Click stanga.");
    outtextxy(POZITIE_BUTON, 30 * POZITIE_BUTON, "Scopul jucatorului este completarea careului.");

    while (true) {
        int x, y;
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if(x < 210 && y < 50 && x > 10 && y > 10) {
            setactivepage(PAGINA_PRINCIPALA);
            setvisualpage(PAGINA_PRINCIPALA);
            return;
        }
    }
}
void win()
{
    setcolor(WHITE);
    outtextxy(400,300,"YOU WIN!");
}

void butoane_nivele()
{
    settextstyle(10, HORIZ_DIR, 4);
    setlinestyle(DOTTED_LINE, 0x3333, THICK_WIDTH);

    rectangle(1000, 180, 1150, 230);
    outtextxy(1010, 190, "RANDOM");

    rectangle(1000,240,1150,290);
    outtextxy(1010,250,"CUSTOM");

    rectangle(1000,300,1150,350);
    outtextxy(1010,310,"LEVEL 1");

    rectangle(1000,360,1150,410);
    outtextxy(1010,370,"LEVEL 2");

    rectangle(1000,420,1150,470);
    outtextxy(1010,430,"LEVEL 3");

    rectangle(1000,480,1150,530);
    outtextxy(1010,490,"LEVEL 4");

    rectangle(1000,540,1150,590);
    outtextxy(1010,550,"LEVEL 5");

    rectangle(1000,600,1150,650);
    outtextxy(1010,610,"LEVEL 6");

    rectangle(1000,660,1150,710);
    outtextxy(1010,670,"LEVEL 7");

    rectangle(1000,720,1150,770);
    outtextxy(1010,730,"LEVEL 8");

    reseteaza_stil();
}
void deseneaza_sageata(int y)
{setlinestyle(DOTTED_LINE, 0x3333, THICK_WIDTH);
 line(950,y+25,995,y+25);
 line(980,y+15,995,y+25);
 line(980,y+35,995,y+25);
reseteaza_stil();
}


#endif
