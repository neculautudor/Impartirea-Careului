#ifndef HEADER_FILE
#define HEADER_FILE

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
    outtextxy(2 * POZITIE_BUTON * POZITIE_BUTON - 10, POZITIE_BUTON, "INSTRUCTIUNI");
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
    outtextxy(POZITIE_BUTON, 6 * POZITIE_BUTON, "- Pai, e simplu. Dai play si aia e.");

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

#endif
