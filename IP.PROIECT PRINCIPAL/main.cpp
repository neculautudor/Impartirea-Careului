#include <iostream>
#include<graphics.h>
#include<winbgim.h>

using namespace std;
unsigned NRBULINE=1,patrat=7,x1,y1,culoare=1;
unsigned tabla[9][9],linie,coloana;
int x,y;
void TABLA()
{
    int x=400,y=400;
    line(x,y,2*x,y);
    line(x,y,x,2*y);
    line(x,2*y,2*x,2*y);
    line(2*x,2*y,2*x,y);
    settextstyle(10,HORIZ_DIR,4);
    outtextxy(375,410,"1");
    outtextxy(375,460,"2");
    outtextxy(375,510,"3");
    outtextxy(375,560,"4");
    outtextxy(375,610,"5");
    outtextxy(375,660,"6");
    outtextxy(375,710,"7");
    outtextxy(375,760,"8");
    outtextxy(415,369,"1");
    outtextxy(465,369,"2");
    outtextxy(515,369,"3");
    outtextxy(565,369,"4");
    outtextxy(615,369,"5");
    outtextxy(665,369,"6");
    outtextxy(715,369,"7");
    outtextxy(765,369,"8");


    for(int i=50;i<=400;i+=50)
    {
        line(x+i,y,x+i,2*y);
        line(x,y+i,2*x,y+i);
    }
}
int DESENEAZA_BULINA(int x,int y)
{
     setcolor(8);
setfillstyle(SOLID_FILL,8);
  linie=(y-400)/50+1;
  coloana=(x-400)/50+1;
   if(x>400 && x<800 && y>400 && y<800)
         if(tabla[linie][coloana]==0)
          {
            NRBULINE++;
            tabla[linie][coloana]=2;
     circle(400+coloana*50-25,400+linie*50-25,20);
     fillellipse(400+coloana*50-25,400+linie*50-25,20,20);
          }
}


int main()
{

  for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
     tabla[i][j]=0;


    initwindow(1000,1000);
    TABLA();
    while(NRBULINE<=8)
    {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        DESENEAZA_BULINA(x,y);
    }

while(true)
{
getmouseclick(WM_LBUTTONDOWN,x,y);
linie=(y-400)/50+1;
coloana=(x-400)/50+1;

if(tabla[linie][coloana]==2)
{
    setcolor(culoare);
    culoare++;
    for(int i=1;i<=4;i++)
        rectangle((x-400)/50*50+i+400,(y-400)/50*50+i+400,(x-400)/50*50+50-i+400,(y-400)/50*50+50-i+400);
while(patrat)
{
    getmouseclick(WM_LBUTTONDOWN,x,y);
    if(x>400 && x<800 && y>400 && y<800)
     if(((((x-400)/50+2==coloana) || ((x-400)/50==coloana)) && (linie==(y-400)/50+1)) || ((((y-400)/50+2==linie) || ((y-400)/50==linie)) && (coloana==(x-400)/50+1)))
      if(tabla[(y-400)/50+1][(x-400)/50+1]==0)
      {

       for(int i=1;i<=4;i++)
        rectangle((x-400)/50*50+i+400,(y-400)/50*50+i+400,(x-400)/50*50+50-i+400,(y-400)/50*50+50-i+400);
     patrat--;
     tabla[linie][coloana]=1;
     linie=(y-400)/50+1;
     coloana=(x-400)/50+1;


      }
}

}
patrat=7;
}

getch();
closegraph();
    return 0;
}
