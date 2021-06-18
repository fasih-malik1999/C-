#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
d(char arr[4][4])
{int i,j;
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			cout<<setw(3)<<arr[i][j];
		}
		cout<<endl;
	}
}
check(char arr[4][4])
{
	if((arr[1][1]=='x'&&arr[1][2]=='x'&&arr[1][3]=='x')||(arr[2][1]=='x'&&arr[2][2]=='x'&&arr[2][3]=='x')||(arr[3][1]=='x'&&arr[3][2]=='x'&&arr[3][3]=='x')||(arr[1][1]=='x'&&arr[2][1]=='x'&&arr[3][1]=='x')||(arr[1][2]=='x'&&arr[2][2]=='x'&&arr[3][2]=='x')||(arr[1][3]=='x'&&arr[2][3]=='x'&&arr[3][3]=='x')||(arr[1][1]=='x'&&arr[2][2]=='x'&&arr[3][3]=='x')||(arr[1][3]=='x'&&arr[2][2]=='x'&&arr[3][1]=='x'))
{
		cout<<"PLAYER 1 HAS WON";
		exit(0);}
	else if((arr[1][1]=='o'&&arr[1][2]=='o'&&arr[1][3]=='o')||(arr[2][1]=='o'&&arr[2][2]=='o'&&arr[2][3]=='o')||(arr[3][1]=='o'&&arr[3][2]=='o'&&arr[3][3]=='o')||(arr[1][1]=='o'&&arr[2][1]=='o'&&arr[3][1]=='o')||(arr[1][2]=='o'&&arr[2][2]=='o'&&arr[3][2]=='o')||(arr[1][3]=='o'&&arr[2][3]=='o'&&arr[3][3]=='o')||(arr[1][1]=='o'&&arr[2][2]=='o'&&arr[3][3]=='o')||(arr[1][3]=='o'&&arr[2][2]=='o'&&arr[3][1]=='o'))
{
		cout<<"PLAYER 2 HAS WON";
		exit(0);}	
}

int main()
{
	char arr[4][4]={{' ','1','2','3'},{'1','1','2','3'},{'2','4','5','6'},{'3','7','8','9'}};
	d(arr);
	cout<<"\nTHE GAME BEGINS....!!!!";
	int a,b;
	for(int i=0;i<4;i++)
	{   c:
		cout<<"\nPLAYER 1 PLACE YOU X BY CHOSING COORDINATES";
		cout<<"\na=";cin>>a;cout<<"\nb=";cin>>b;
		if(arr[a][b]!='x'&&arr[a][b]!='o')
		{arr[a][b]='x';
		d(arr);}
		else
		{
			cout<<"\nU CHOSE THE WRONG SPACE";
			goto c;
		}
		check(arr);
		d:
		cout<<"\nPLAYER 2 PLACE YOUR O BY CHOSING COORDINATES";
		cout<<"\na=";cin>>a;cout<<"\nb=";cin>>b;
		if(arr[a][b]!='x'&&arr[a][b]!='o')
		{arr[a][b]='o';
		d(arr);}
		else
		{
			cout<<"\nU CHOSE THE WRONG SPACE";
			goto d;
		}	
		check(arr);
		if(i==3
		)
		{
			z:
		cout<<"\nPLAYER 1 PLACE YOU X BY CHOSING COORDINATES";
		cout<<"\na=";cin>>a;cout<<"\nb=";cin>>b;
		if(arr[a][b]!='x'&&arr[a][b]!='o')
		{arr[a][b]='x';
		d(arr);}
		else
		{
			cout<<"\nU CHOSE THE WRONG SPACE";
			goto z;
		}
		check(arr);
		}
	}
	cout<<"IT WAS A DRAW";
	getch();
	return 0;
}
