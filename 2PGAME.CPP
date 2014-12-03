#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
void printbox(int limx, int limy)
{
 int i;
 clrscr();
 cout<<(char)209;
 for (i=2;i<limx;i++)
  cout<<(char)205;
 cout<<(char)209;
 for (i=2;i<limy;i++)
 {
   gotoxy(limx,i);
   cout<<(char)179;
 }
 gotoxy(limx,i);
 cout<<(char)207;
 for (i=limx;i>=1;i--)
  cout<<"\b\b"<<(char)205;
 cout<<"\b\b"<<(char)207;
 for (i=limy-1; i>1;i--)
 {
  gotoxy(1,i);
  cout<<(char)179;
 }
}
int printbar(int y, int limy, int len, int x)
{
 int i;
 if (y>limy-len)
  return -1;
 else if (y<2)
  return 1;
 else
 {
  if (y!=2)
  {
  gotoxy(x,y-1);
  cout<<' ';
  }
  for (i=1;i<=len;i++)
  {
    gotoxy(x,y++);
    cout<<(char)179;
  }
  if (y!=limy)
  {
  gotoxy(x,y);
  cout<<' ';
  }
 }
 return 0;
}
void printscore(int points1, int points2, int limy, int limx)
{
 gotoxy(limx/2-5,limy+1);
 cout<<"SCORECARD\n";
 cout<<"Player 1 ="<<points1<<'\n';
 cout<<"Player 2 ="<<points2<<'\n';
}
void main()
{
 clrscr();
 int limx,limy,points;
 randomize();
 cout<<"Enter horizontal limit:"; cin>>limx;
 cout<<"Enter vertical limit:"; cin>>limy;
 limy=limy-4;
 cout<<"\n\nEnter points required to win:";
 cin>>points;
 cout<<"\n\nPlayer 1:\nUse \'a\' and \'z\' to move the bar\n\nPlayer 2:\nUse \'k\' ans \'m\' to move the bar";
 getch();
 clrscr();
 int i,chanx,chany,x,y,yl=limy/2, yr=limy/2,len=limy/4,points1=0,points2=0,sp=4;
 if (len%2==0)
  len++;
 printbox(limx,limy);
 printbar(yl,limy,len,2);
 printbar(yr,limy,len,limx-1);
 printscore(points1, points2, limy, limx);
 cout<<"Points required:"<<points;
 char in;
 while (points1!= points && points2!=points)
 {
  x=limx/2+(points1-points2);
  y=limy/2+random(limy/10);
  chany=random(3);
  if (chany==2)
   chany=-1;
  chanx=random(2);
  if (chanx==0)
   chanx=-1;
  sp=0;
  gotoxy(x,y);
  for (i=3;i>=1;i--)
  {
   cout<<i<<'\b';
   delay(1000);
  }
  cout<<'\a';
  while (1)
  {
   gotoxy(x,y);
   cout<<"*\b";
   if (kbhit())
   {
    in=getch();
    if (in=='z')
     yl=yl+printbar(++yl,limy,len,2);
    else if (in=='a')
     yl=yl+printbar(--yl,limy,len,2);
    else if (in=='m')
     yr=yr+printbar(++yr,limy,len,limx-1);
    else if (in=='k')
     yr=yr+printbar(--yr,limy,len,limx-1);
    in=NULL;
    if (sp!=50)
     sp++;
   }
   if (kbhit())
   {
    in=getch();
    if (in=='z')
     yl=yl+printbar(++yl,limy,len,2);
    else if (in=='a')
     yl=yl+printbar(--yl,limy,len,2);
    else if (in=='m')
     yr=yr+printbar(++yr,limy,len,limx-1);
    else if (in=='k')
     yr=yr+printbar(--yr,limy,len,limx-1);
    in=NULL;
   }
   if (x==3)
   {
    chanx=1;
    if (y>=yl && y<(yl+len/2))
     chany=-1;
    else if (y>(yl+len/2) && y<=(yl+len))
     chany=1;
    else if (y==yl+len/2)
     chany=0;
    else
    {
     points2++;
     break;
    }
   }
   else if (x==limx-2)
   {
    chanx=-1;
    if (y>=yr && y<(yr+len/2))
     chany=1;
    else if (y>(yr+len/2) && y<=(yr+len))
     chany=-1;
    else if (y==yr+len/2)
     chany=0;
    else
    {
     points1++;
     break;
    }
   }
   else if (y==2 || y==limy-1)
   {
    chany=-chany;
   }
   delay(100-sp);
   gotoxy(x,y);
   cout<<' ';
   x=x+chanx;
   y=y+chany;
  }
  printscore(points1, points2, limy, limx);
  delay(2000);
  getch();
  gotoxy(x,y);
  cout<<' ';
 }
 gotoxy((limx/2)-5,(limy+4)/2);
 if (points1==points)
  cout<<"Player 1 wins by "<<points1-points2<<" point(s)";
 else
  cout<<"Player 2 wins by "<<points2-points1<<" point(s)";
  delay(1000);
 getch();
}

