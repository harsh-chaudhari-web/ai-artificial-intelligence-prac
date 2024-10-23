#include<iostream.h>
#include<conio.h>

int n;
void tower(int n,char from,char aux,char to)
{
	if(n==1)
   {
   	cout<<"move disc 1 from tower "<<from<<" to tower "<<to<<endl;
      return;
   }
   else
   {
   	tower(n-1,from,to,aux);
      cout<<"move disc "<<n<<" from tower "<<from<<" to tower "<<to<<endl;
      tower(n-1,aux,from,to);
   }
}

void main()
{
	clrscr();
   cout<<"enter the no of disc's: ";
   cin>>n;
   tower(n,'A','B','C');
   getch();
}
