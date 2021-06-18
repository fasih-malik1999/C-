#include <iostream>
#include <conio.h>

using namespace std;

struct node {
    string regNo;
    string fullName;
    string address;
    string phoneNo;
    node* link;
};

node* headNode = NULL;
node* tailNode = NULL;

void sorting();
void display(node* temp);
void traverse();
void updateRecord();
node* searchStudent();
void insertNewStudent();
void deletionAtEnd();
void deletionAtStart();
void deletionOption();

int main() {
    char insertOrNot = 'y', option;

    do {
        system("cls");
        system("color 94");
        cout << "\n\n-----MAIN-MENU-----\n";
        cout << "\n\nEnter your choice\n\n";
        cout << "1 for Insert New Student\n";
        cout << "2 to Search and Display Student Record\n";
        cout << "3 to Update Student Record\n";
        cout << "4 for Deletion of any data\n";
        cout << "5 to Show all Students\n";
        cout << "0 to Exit\n";

        option = getch();
        system("cls");

        switch(option) {
        case '1':
            system("color A1");
            insertNewStudent();
            sorting();
            break;
        case '2':
            system("color 72");
            cout << "\nEnter Registration No of Student: "; searchStudent();
            break;
        case '3':
            system("color 8F");
            cout << "\nEnter Registration No of Student to Update: ";updateRecord();
            break;
        case '4':
            system("color 04");
            deletionOption();
            break;
        case '5':
            system("color E5");
            traverse();
            break;
        case '0':
            system("color 02");
            cout << "\n:)\n";
            exit(0);
            break;
        default:
            cout << "Invalid Selection. Press Enter to try again.";
            getch();
        }
    } while (option != 0);
}

void display(node* temp) {
    cout << "\nStudent's Registration Number: " << temp->regNo;
    cout << "\nStudent's Full Name: " << temp->fullName;
    cout << "\nStudent's Address: " << temp->address;
    cout << "\nStudent's Phone Number: " << temp->phoneNo;
    cout << "\nPress any key to continue..."; getch();
}

void traverse() {
    node* temp = new node;
    temp = headNode;
    if (headNode == NULL) {
        cout << "Currently the list is empty.";
        cout << "\nPress any key to continue..."; getch();
        return;
    }
    cout << endl << "Student Record: " << endl;
    while (temp != NULL) {
        cout << temp->regNo << "     " << temp->fullName << endl;
        temp = temp->link;
    }
    cout << "\nPress any key to continue..."; getch();
}

void insertNewStudent() {
    node* temp = new node;

    cout << "\nEnter Student's Registration Number: "; getline(cin, temp->regNo);
    cout << "\nEnter Student's Full Name: "; getline(cin, temp->fullName);
    cout << "\nEnter Student's Address: "; getline(cin, temp->address);
    cout << "\nEnter Student's Phone Number: "; getline(cin, temp->phoneNo);
    display(temp);

    temp->link = NULL;
    if (headNode == NULL) {
        headNode = temp;
        tailNode = temp;
    } else {
        tailNode->link = temp;
        tailNode = tailNode->link;
    }
}

node* searchStudent() {
    node* temp = new node;
    temp = headNode;
    if (temp == NULL) {
        cout << "Currently the Student Records are empty.";
        cout << "\nPress any key to continue..."; getch();
        return 0;
    }
    char userInput[11];
    cin.get(userInput, 11); cin.get();
    while (temp != NULL) {
        if (temp->regNo == userInput) {
            display(temp);
            break;
        }
        temp = temp->link;
    }
    return temp;
}

void deletionAtEnd() {
    if (headNode == NULL) {
        return;
    } else if (headNode->link == NULL) {
        delete(headNode);
    }

    node* secondLast = new node;
    tailNode = headNode;
    while (tailNode->link != NULL) {
        secondLast = tailNode;
        tailNode = tailNode->link;
    }
    delete(secondLast->link);
    tailNode = secondLast;
    tailNode->link = NULL;
    return;
}

void deletionAtStart() {

    if (headNode == NULL) {
        return;
    } else if (headNode->link == NULL) {
        delete(headNode);
    } else {
        node* tmp = headNode->link;
        delete(headNode);
        headNode = tmp;
    }
}

void deletionOption() {
    char dataUser[12];
    if (headNode == NULL) {
        cout << "Link List is Empty";
        cout << "\nPress any key to continue..."; getch();
        return;
    }
    cout << "Enter Registration Number of Student to delete: "; cin >> dataUser;
    node* location;
    location->fullName = "NaN";
    tailNode = headNode;
    node* trvs = headNode;

    while (tailNode != NULL) {
        if (tailNode->regNo == dataUser) {
            location = tailNode;
            display(location);
            break;
        } else {
            trvs = tailNode;
            tailNode = tailNode->link;
        }
    }

    if (location == headNode) {
        deletionAtStart();
    } else if (location->link == NULL) {
        deletionAtEnd();
    } else {
        delete(trvs->link);
        trvs->link = tailNode->link;
    }
}

void updateRecord() {
    node* temp = searchStudent();

    cout << "\n----------------------------------------\n";
    cout << "\nEnter Updated Registration Number: "; getline(cin, temp->regNo);
    cout << "\nEnter Updated Full Name: "; getline(cin, temp->fullName);
    cout << "\nEnter Updated Address: "; getline(cin, temp->address);
    cout << "\nEnter Updated Phone Number: "; getline(cin, temp->phoneNo);
    display(temp);
}

void sorting() {
    node* first;
    node* second;
    string temp;

    first = headNode;
    while (first != NULL) {
        for (second = first->link; second != NULL; second = second->link) {
            if (first->regNo > second->regNo) {
                //transfer Registration Number
                temp = first->regNo;
                first->regNo = second->regNo;
                second->regNo = temp;

                //Transfer Full Name
                temp = first->fullName;
                first->fullName = second->fullName;
                second->fullName = temp;

                //Transfer Address
                temp = first->address;
                first->address = second->address;
                second->address = temp;

                //Transfer Phone Number
                temp = first->phoneNo;
                first->phoneNo = second->phoneNo;
                second->phoneNo = temp;
            }
        }
        first = first->link;
    }
}
