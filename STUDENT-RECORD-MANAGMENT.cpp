#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
 struct student
       {
              char name[25];
              char reg_no[25];
              int marks[3];
             };
       int main()
       {     
              int i;
              student record[5];

			 for(i=0;i<5;i++)
              {

                cout << "\nEnter details of "  <<i+1<< " student";
                cout<<endl;
				cout << "\n\tEnter Student Name : ";
                cin>> record[i].name;
                cout << "\n\tEnter Student Reg. no : ";
                cin>> record[i].reg_no; 
			
				for(int j=0;j<3;j++)
              {
                     cout << "\n\nEnter Marks " << j+1 << " : ";
                     cin >> record[i].marks[j];
			}
		}
			cout<< "\n\n Details of Students: ";
			
			for ( int i=4; i>=1;i--)
			{
			
                for (int j=0; j<i;j++)
                {
                    if (record[j].name[0] > record[j+1].name[0])
                    {
                        swap(record[j], record[j+1]);
                    }
                }					
			}
			
			for ( int i=0; i<5;i++)
			{
			cout<<"\n"<<record[i].name<<"\t"<<"\t"<<record[i].reg_no<<"\t";
			for (int j=0; j<3;j++)
					cout<<"\t"<<record[i].marks[j];					
				}
				char name[20];
				cout<<endl;
            cout << "Enter student's name to search record: ";
            cin >> name;
            for (int i = 0; i < 5; i++)
            {
                if (!strcmp(record[i].name, name ) )
                {
                    cout<<record[i].name<<"   "<<record[i].reg_no<<endl;
                    cout << "\nEnter details of "  <<i+1<< " student";
 					cout << "\n\tEnter Student Name : ";
                    cin>> record[i].name;

                    cout << "\n\tEnter Student Reg. no : ";
                    cin>> record[i].reg_no; 
                    for(int j=0;j<3;j++)
                    {
                            cout << "\n\nEnter Marks " << j+1 << " : ";
                            cin >> record[i].marks[j];      
                    }
                }     
            }
	}
			
			
			

			
			
		     
              
          
              

            



