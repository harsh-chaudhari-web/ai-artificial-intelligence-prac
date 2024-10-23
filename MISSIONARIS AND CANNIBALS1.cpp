#include<iostream.h>
#include<conio>
int im=3,ic=3,i,j,fm=0,fc=0,s=0,flag=0,se=0;
void display(char bp1,char bp2)
{
 cout<<"\n";
 for(i=0;i<fm;i++)
 cout<<"M";
 for(i=0;i<fc;i++)
 cout<<"C";
 if(flag==0)
 cout<<" boat at right("<<bp1<<","<<bp2<<") ";
 else
 cout<<" boat at left ("<<bp1<<","<<bp2<<") ";
 for(i=0;i<im;i++)
 cout<<"M";
 for(i=0;i<ic;i++)
 cout<<"C";
}
 int win()
 {
  if(fc==3 && fm==3)
  return 0;
  else
  return 1;
 }
  void solution()
  {
   while(win())
   {
    if(flag==0)
    {
     switch(se)
     {
      case 1:display('C','M');
      ic++;
      break;
      case 2:display('c','M');
      ic++;
      im++;
      break;
     }
     if(((im-2)>=ic && (fm+2)>=fc) || (im-2)==0)
     {
      im=im-2;
      se=1;
      display('M','M');
      flag=1;
     }
     else if((ic-2)<im && (fm==0) || (fc+2)<=fm || im==0)
     {
      ic=ic-2;
      se=2;
      display('C','C');
      flag=1;
     }
     else if(((ic--)<=(im--)) && ((fm++)>=(fc++)))
     {
      ic=ic-1;
      im=im-1;
      display('M','C');
      flag=1;
     }
    }
    else
    {
     switch(se)
     {
      case 1:display('M','M');
      fm=fm+2;
      break;
      case 2:display('C','C');
      fc=fc+2;
      break;
      case 3:display('M','C');
      fc=fc+1;
      fm=fm+1;
      break;
      }
      if(win())
      {
       if(((fc>1) && (fm==0)) || im==0)
       {
        fc--;
        se=1;
        display('C',' ');
        flag=0;
       }
       else if((ic+2)>im)
       {
        fc--;
        fm--;
        se=2;
        display('C','M');
        flag=0;
       }
      }
     }
   }
  }
  void main()
  {
   clrscr();
   cout<<"Missionaries and Cannibals:\n";
   cout<<"Enter the no of of Missionary:";
   cin>>im;
   cout<<"Enter the no of Cannibal:";
   cin>>ic;
   display(' ',' ');
   solution();
   display(' ',' ');
   cout<<"\n";
   getch();
  }

