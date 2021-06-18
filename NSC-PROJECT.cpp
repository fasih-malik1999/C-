//NSC Project BHAI and Teddy
#include<iomanip>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cmath>

using namespace std;

double f(double x);
void printer();
int calc(float arr[][2],float n)
{
    int c;
    for(int i=0;i<10;i++)
    {
        if(n==arr[i][0])
        {
            c=i;
            break;
        }
    }
    return c;
}
int main() {
main:
    cout << "---NSC PROJECT 1 BY FASIH MALIK AND TALHA SALMAN---\n\n";

    cout << "What operation do you want to perform?\n";
    cout << "1.Aitken's Method\n";
    cout << "2.Integration\n";
    cout << "3.Exit\n";

    char select;

    select = getch();

    switch (select) {
        case '1': {
            system("cls");
            cout << "---NSC PROJECT 1 BY FASIH MALIK AND TALHA SALMAN---\n\n";
            cout << "AITKEN'S METHOD\n\n";
            int n;
            double step;
            cout << "Enter the number of values: "; cin >> n;
            double myArrayX[n], myArrayD[n][n], xp, fp;

            cout << "Enter value of Xo: "; cin >> myArrayX[0];
            cout << "Enter step value: ";  cin >> step;

            for (int i = 0; i < n; i++) {
                myArrayX[i] += step*i;
            } //Initialized values of x

            cout << "Enter values of f(x): ";
            for (int i = 0; i < n; i++) {
                cin >> myArrayD[i][0];
            } //Initialize values of f(x)

            cout << "\nEnter value to find: "; cin >> xp;
            double p, h, array1[n];
            for (int p = 0; p < n; p++) {
                array1[p] = xp - myArrayX[p];
                cout << "xp - x" << p << " = " << array1[p] << endl;
            }
            double fx[n][n];
            fx[0][1]=1/(myArrayX[1]-myArrayX[0]) *(((array1[0] * myArrayD[1][0]) - (array1[1] * myArrayD[0][0])));
            fx[0][2]=1/(myArrayX[2]-myArrayX[0]) *(((array1[0] * myArrayD[2][0]) - (array1[2] * myArrayD[0][0])));
            fx[0][3]=1/(myArrayX[3]-myArrayX[0]) *(((array1[0] * myArrayD[3][0]) - (array1[3] * myArrayD[0][0])));
            fx[1][1]=1/(myArrayX[2]-myArrayX[1]) *(((array1[1] * fx[0][2]) - (array1[2] * fx[0][1])));
            fx[1][2]=1/(myArrayX[3]-myArrayX[1]) *(((array1[1] * fx[0][3]) - (array1[3] * fx[0][1])));
            fx[2][1]=1/(myArrayX[3]-myArrayX[2]) *(((array1[2] * fx[1][2]) - (array1[3] * fx[1][1])));

            for (int j = 1; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    myArrayD[i][j] = fx[i][j];
                }
            }

            int k = n;
            cout << "\nAitken's Table is as follows: \n";
            for (int i = 0; i < n; i++) {
                cout << myArrayX[i] << " ";
                for (int j = 0; j < k; j++) {
                    cout << myArrayD[i][j] << "  ";
                }
                cout << endl;
                k--;
            }
            goto main;
        }
            break;
        case '2': {
            printer();
            cout << "What operation do you want to perform?\n";
            cout << "1.Newton Cot's Formulas\n";
            cout << "2.Romberg Integration\n";
            cout << "3.Exit\n";

            select = getch();

            int n;
            double a, b, h, sum = 0, integral;

            switch (select) {
                case '1': {
                    printer();
                    cout << "What operation do you want to perform?\n";
                    cout << "1.Trapezoidal Rule\n";
                    cout << "2.Simpson's 1/3rd Rule\n";
                    cout << "3.Simpson's 3/8th Rule\n";
                    cout << "4.Boole's Rule\n";
                    cout << "5.Weddle's Rule\n";
                    cout << "6.Exit\n";

                    select = getch();

                    switch (select) {
                        case '1': {
                            printer();
                            cout << "TRAPEZOIDAL RULE\n\n";
                            cout << "Lower Limit: "; cin >> a;
                            cout << "Upper Limit: "; cin >> b;
                            cout << "Enter the number of subintervals: "; cin >> n;

                            double x[n+1], y[n+1];
                            h = (b - a) / n;

                            for (int i = 0; i <= n; i++) {
                                x[i] = a + i*h;
                                y[i] = f(x[i]);
                            }

                            for (int i = 1; i <= n; i++) {
                                sum += h*y[i];
                            }

                            integral = (h/2.0)*(y[0] + y[n]) + sum;
                        }
                            break;
                        case '2': {
                            printer();
                            cout << "SIMPSON'S 1/3RD RULE\n\n";

                            cout << "Lower Limit: "; cin >> a;
                            cout << "Upper Limit: "; cin >> b;
                            cout << "Enter the number of subintervals: "; cin >> n;
                            while (n%2 != 0) {
                                cout << "Odd number of subintervals cannot be executed.\n";
                                cout << "Try Again or enter 0 to exit.\n";
                                cin >> n;
                                if (n == 0) {
                                    exit(0);
                                }
                            }

                            double x[n+1], y[n+1];
                            h = (b - a) / n;

                            for (int i = 0; i <= n; i++) {
                                x[i] = a + i*h;
                                y[i] = f(x[i]);
                            }

                            for (int i = 1; i < n; i += 2) {
                                sum += 4.0*y[i];
                            }

                            for (int i = 2; i < n - 1; i += 2) {
                                sum += 2.0*y[i];
                            }

                            integral = (h/3.0)*(y[0] + y[n] + sum);
                        }
                            break;
                        case '3': {
                            printer();
                            cout << "SIMPSON'S 3/8RD RULE\n\n";

                            cout << "Lower Limit: "; cin >> a;
                            cout << "Upper Limit: "; cin >> b;
                            cout << "Enter the number of subintervals: "; cin >> n;
                            while (n%3 != 0) {
                                cout << "Number of subintervals should be a multiple of 3.\n";
                                cout << "Try Again or enter 0 to exit.\n";
                                cin >> n;
                                if (n == 0) {
                                    exit(0);
                                }
                            }

                            double x[n+1], y[n+1];
                            h = (b - a) / n;

                            for (int i = 0; i <= n; i++) {
                                x[i] = a + i*h;
                                y[i] = f(x[i]);
                            }

                            for (int i = 1; i < n; i++) {
                                if (i%3 == 0) {
                                    sum += 2*y[i];
                                } else {
                                    sum += 3*y[i];
                                }
                            }

                            integral = (3*h/8)*(y[0] + y[n] + sum);
                        }
                            break;
                        case '4': {
                            printer();
                            cout << "BOOLE'S RULE\n\n";

                            cout << "Lower Limit: "; cin >> a;
                            cout << "Upper Limit: "; cin >> b;
                            cout << "Enter the number of subintervals: "; cin >> n;
                            while (n%4 != 0) {
                                cout << "Number of subintervals should be a multiple of 4.\n";
                                cout << "Try Again or enter 0 to exit.\n";
                                cin >> n;
                                if (n == 0) {
                                    exit(0);
                                }
                            }

                            double x[n+1], y[n+1];
                            h = (b - a) / n;

                            for (int i = 0; i <= n; i++) {
                                x[i] = a + i*h;
                                y[i] = f(x[i]);
                            }

                            for (int i = 1; i < n; i++) {
                                if (i%2 == 0) {
                                    sum += 12*y[i];
                                } else {
                                    sum += 32*y[i];
                                }
                            }

                            integral = (2*h/45)*(7*(y[0] + y[n]) + sum);
                        }
                            break;
                        case '5': {
                            printer();
                            cout << "WEDDLE'S RULE\n\n";

                            cout << "Lower Limit: "; cin >> a;
                            cout << "Upper Limit: "; cin >> b;
                            cout << "Enter the number of subintervals: "; cin >> n;
                            while (n%6 != 0) {
                                cout << "Number of subintervals should be a multiple of 6.\n";
                                cout << "Try Again or enter 0 to exit.\n";
                                cin >> n;
                                if (n == 0) {
                                    exit(0);
                                }
                            }

                            double x[n+1], y[n+1];
                            h = (b - a) / n;

                            for (int i = 0; i <= n; i++) {
                                x[i] = a + i*h;
                                y[i] = f(x[i]);
                            }

                            for (int i = 1; i < n; i++) {
                                if (i%2 == 0) {
                                    sum += y[i];
                                } else if (i%3 == 0) {
                                    sum += 6*y[i];
                                } else if (i%6 == 0) {
                                    sum += 2*y[i];
                                } else {
                                    sum += 5*y[i];
                                }
                            }

                            integral = (3*h/10)*(y[0] + y[n] + sum);
                        }
                            break;
                        case '6':
                            exit(0);
                            break;
                        default:
                            break;
                    }
                    goto main;
                }
                    break;
                case '2': {
                    system("cls");
                    cout << "ROMBERG INTEGRATION\n\n";

                    int v,n=0;
	float l=0,u=0,I11=0,T11=0,h1=0,h=0,I12=0,T12=0,I13=0,T13=0,I14=0,T14=0,T22=0,T23=0,T24=0,T33=0,T34=0,T44=0;

	cout<<"\n\n\tENTER LOWER LIMIT"<<endl;
	cin>>l;
	cout<<"\n\tENTER UPPER LIMIT"<<endl;
	cin>>u;
	cout<<"\n\tENTER THE INTERVALS"<<endl;
	cin>>n;
	float f[n+1];
	cout<<"\n\tENTER FUNCTIONAL VALUES"<<endl;
	for(int i=0;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=0;i<=n;i++)
	{
	cout<<"\n\tf["<<i<<"]= "<<f[i]<<endl;
	}
	h=(u-l)/n;
	cout<<"\n\th= "<<h<<endl;
	h1=(u-l);
	cout<<"\n\th1= "<<h1<<endl;
	I11=0.5*(f[0]+f[n]);
	cout<<"\n\tI11= "<<I11<<endl;
	T11=h1*I11;
	cout<<"\n\tT11= "<<T11<<endl;
	I12=(I11+(f[4]));
	cout<<"\n\tI12= "<<I12<<endl;
	T12=(h1/2)*I12;
	cout<<"\n\tT12= "<<T12<<endl;
	I13=(I12+f[2]+f[6]);
	cout<<"\n\tI13= "<<I13<<endl;
	T13=((h1/4)*I13);
	cout<<"\n\tT13= "<<T13<<endl;
	I14=(I13+f[1]+f[3]+f[5]+f[7]);
	cout<<"\n\tI14= "<<I14<<endl;
	T14=h1/8*I14;
	cout<<"\n\tT14= "<<T14<<endl;
	T22=T12+0.34*(T12-T11);
	cout<<"\n\tT22= "<<T22<<endl;
	T23=T13+0.34*(T13-T12);
	cout<<"\n\tT23= "<<T23<<endl;
	T24=T14+0.34*(T14-T13);
	cout<<"\n\tT24= "<<T24<<endl;
	T33=T23+0.067*(T23-T22);
	cout<<"\n\tT33= "<<T33<<endl;
	T34=T24+0.067*(T24-T23);
	cout<<"\n\tT34= "<<T34<<endl;
	T44=T34+0.016*(T34-T33);
	cout<<"\n\tT34= "<<T34<<endl;
	cout<<"\n\n\t\t\tTHE BEST ESTIMATE IS= "<<T44<<endl<<endl;

                }
                goto main;
                    break;
                case '3':
                    exit(0);
                    break;
                default:
                    break;
            }
            cout << "\nThe definite integral is " << integral << endl;
        }
            break;
        case '3':
            exit(0);
            break;
        default:
            break;
    }
}

double f(double x) {
    double a = 1 / (1 + x*x);
    return a;
}

void printer() {
    system("cls");
    cout << "---NSC PROJECT 1 BY FASIH MALIK AND TALHA SALMAN---";
    cout << "\n\nf(x) = 1 / (1 + x*x)\n\n";
}
