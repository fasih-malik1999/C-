#include<windows.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
using namespace std;
char st(int a)
{
    cout<<endl;
    for(int i =0;i<a;i++)
    {
        cout<<"\t*";
    }
}
int main()
{
    int a=0,b=0,c=0,d=0,e=0,f=0;
    cout<<"\nenter the number of rocks in each of the three bins";
    cin>>d;
    a=d;b=d;c=d;
    cout<<"\n A "<<st(a);
    cout<<"\n B "<<st(b);
    cout<<"\n C "<<st(c);
    cout<<"\n press any key to continue";
    getch();
    while(a+b+c!=0)
    {
        system("cls");
         cout<<"\n A "<<st(a);
    cout<<"\n B "<<st(b);
    cout<<"\n C "<<st(c);
        f++;
        if(f%2!=0)
        {
            cout<<"\n ITS PLAYER ONE\'S TURN";
            }
        else
        {
            cout<<"\n ITS PLAYER TWO\'S TURN";
        }
        chose:
        cout<<"\n CHOSE THE BUCKET YOU WISH TO TAKE ROCKS FROM\n\t PRESS 1 FOR BIN a\n\t PRESS 2 FOR BIN B \n\t PRESS 3 FOR BIN C";
        cin>>e;
        switch(e)
        {
        case 1:
            {
                if(a<=0)
                {
                    cout<<"\n\t THE BIN IS EMPTY CHOSE AGAIN";
                    goto chose;
                }
                else
                {
                    _1:
                    cout<<"\n A is "<<st(a);
                    cout<<"\n ENYTER THE NUMBER OF ROCKS BETWEEN 1 AND "<<a;
                    cin>>e;
                    if(e<=0||e>a)
                    {
                        cout<<"\n NOT ENOUGH ROCKS CHOSE AGAIN";
                        goto _1;
                    }
                    a=a-e;
                    cout<<"\n A is "<<st(a);
                }
                break;
            }
        case 2:
            {
                if(b<=0)
                {
                    cout<<"\n\t THE BIN IS EMPTY CHOSE AGAIN";
                    goto chose;
                }
                else
                {
                    _2:
                    cout<<"\n B is "<<st(b);
                    cout<<"\n ENYTER THE NUMBER OF ROCKS BETWEEN 1 AND "<<b;
                    cin>>e;
                    if(e<=0||e>b)
                    {
                        cout<<"\n NOT ENOUGH ROCKS CHOSE AGAIN";
                        goto _2;
                    }
                    b=b-e;
                    cout<<"\n B is "<<st(b);
                }
                break;
            }
        case 3:
            {
                if(c<=0)
                {
                    cout<<"\n\t THE BIN IS EMPTY CHOSE AGAIN";
                    goto chose;
                }
                else
                {
                    _3:
                    cout<<"\n C is "<<st(c);
                    cout<<"\n ENYTER THE NUMBER OF ROCKS BETWEEN 1 AND "<<c;
                    cin>>e;
                    if(e<=0||e>c)
                    {
                        cout<<"\n NOT ENOUGH ROCKS CHOSE AGAIN";
                        goto _3;
                    }
                    c=c-e;
                    cout<<"\n C is "<<st(c);
                }
                break;
            }
        default:
            {
                cout<<"\n WRONG CHOICE SELECT AGAIN ";
                goto chose;
                break;
            }
        }
          cout<<"\n press any key to continue";
    getch();
            }
        if(f%2==0)
        {
            cout<<"\n\t CONGRATULATIONS...!!!!!\n PLAYER 1 HAS WON.\n A BIG THANKS OF PLAYER 2 FOR PLAYING";
        }
        else
        {
             cout<<"\n\t CONGRATULATIONS...!!!!!\n PLAYER 2 HAS WON.\n A BIG THANKS OF PLAYER 1 FOR PLAYING";
        }
}
