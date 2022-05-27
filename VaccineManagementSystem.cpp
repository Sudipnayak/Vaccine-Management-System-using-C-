#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <string_view>
#include <regex>
#include <stdio.h>
#include <time.h>
using namespace std;
int count1 = 0, baseamt1 = 200;
class vaccine
{
private:
    string name, aadharNo, age, address, emailId, contactNo;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    int manageSlots();
    void addSlots();
};
void vaccine::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| VACCINE MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Vaccine Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void vaccine::insert() // add vaccine details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Vaccine Details ---------------------------------------------" << endl;

    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Aadhar No.: ";
    cin >> aadharNo;
    cout << "\t\t\tEnter Age: ";
    cin >> age;
    cout << "\t\t\tEnter Email Id: ";
    cin >> emailId;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contactNo;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    count1++;
    baseamt1 = baseamt1 - count1;
    file.open("vaccineRecord.txt", ios::app | ios::out);
    file << " " << name << " " << aadharNo << " " << age << " " << emailId << " " << contactNo << " " << address << " " << baseamt1 << "\n";
    file.close();
}
void vaccine::display() // display vaccine details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Applicant Record Table --------------------------------------------" << endl;
    file.open("vaccineRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Applicant No.: " << total++ << endl;
            cout << "\t\t\t Applicant Name: " << name << endl;
            cout << "\t\t\t Applicant Aadhar No.: " << aadharNo << endl;
            cout << "\t\t\t Applicant age: " << age << endl;
            cout << "\t\t\t Applicant Email Id.: " << emailId << endl;
            cout << "\t\t\t Applicant Contact No.: " << contactNo << endl;
            cout << "\t\t\t Applicant Address: " << address << endl;
            file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void vaccine::modify() // Modify Vaccine Details
{
    system("cls");
    fstream file, file1;
    string tempAadharNo;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Vaccine Modify Details ------------------------------------------" << endl;
    file.open("vaccineRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Aadhar No. of person which you want to Modify: ";
        cin >> tempAadharNo;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
        while (!file.eof())
        {
            if (tempAadharNo != aadharNo)

                file1 << " " << name << " " << aadharNo << " " << age << " " << emailId << " " << contactNo << " " << address << " " << baseamt1 << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Aadhar No.: ";
                cin >> aadharNo;
                cout << "\t\t\tEnter age: ";
                cin >> age;
                cout << "\t\t\tEnter Email Id: ";
                cin >> emailId;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contactNo;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << aadharNo << " " << age << " " << emailId << " " << contactNo << " " << address << " " << baseamt1 << "\n";
                found++;
            }
            file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Aadhar No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("vaccineRecord.txt");
        rename("record.txt", "vaccineRecord.txt");
    }
}
void vaccine::search() // search data of vaccine
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("vaccineRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Vaccine Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string tempAadharNo;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Vaccine Search Data ------------------------------------------" << endl;
        cout << "\n Enter Aadhar No. of Person Which You Want to Search: ";
        cin >> tempAadharNo;
        file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
        while (!file.eof())
        {
            if (tempAadharNo == aadharNo)
            {
                cout << "\n\t\t\t Applicant Name: " << name << endl;
                cout << "\t\t\t Applicant Aadhar No.: " << aadharNo << endl;
                cout << "\t\t\t Applicant age: " << age << endl;
                cout << "\t\t\t Applicant Email Id.: " << emailId << endl;
                cout << "\t\t\t Applicant Address: " << address << endl;
                found++;
            }
            file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tAadhar No. Not Found...";
        }
        file.close();
    }
}
void vaccine::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string tempAadharNo;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Vaccine Details ------------------------------------------" << endl;
    file.open("vaccineRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Aadhar No. of person which you want Delete Data: ";
        cin >> tempAadharNo;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1; // selfincrement operator
        while (!file.eof())
        {
            if (tempAadharNo != aadharNo)
            {
                file1 << " " << name << " " << aadharNo << " " << age << " " << emailId << " " << contactNo << " " << address << " " << baseamt1 << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1; // for self incrementing
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Aadhar No. Not Found....";
        }
        file1.close();
        file.close();
        remove("vaccineRecord.txt");
        rename("record.txt", "vaccineRecord.txt");
    }
}
int vaccine::manageSlots()
{
    ifstream file1;
    file1.open("vaccineRecord.txt", ios::app | ios::in);
    // file1.seekg(0, ios::end);
    // file1 >> baseamt1;
    while (!file1.eof())
    {
        file1 >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
    }
    return baseamt1;
}
void vaccine::addSlots()
{
    fstream file1;
    file1.open("vaccineRecord.txt", ios::app | ios::out);
    // file1.seekg(0, ios::end);
    while (!file1.eof())
    {
        file1 >> name >> aadharNo >> age >> emailId >> contactNo >> address >> baseamt1;
    }
    // file1 >> baseamt1;
    cout << "\t\t\t\t\tThe amount to be added: ";
    int temp1;
    cin >> temp1;
    baseamt1 = baseamt1 + temp1;
    cout << "\n\t\t\t\t\tSlot Amount updated succesfully" << endl;
    file1 << " " << name << " " << aadharNo << " " << age << " " << emailId << " " << contactNo << " " << address << baseamt1 << "\n";
    return;
}
int main()
{
    system("cls");
    vaccine temp2;
    temp2.manageSlots();
    string uName, tempName, guestName;
    uName = "uname1";
    guestName = "guest";
    int pass, tempPass, guestPass;
    pass = 12345;
    guestPass = 67890;
    cout << "\n\n\t\t\t\t\tEnter the username to enter the domain: ";
    cin >> tempName;
    cout << "\n\t\t\t\t\tEnter the password to enter the system: ";
    cin >> tempPass;

    if ((uName != tempName || pass != tempPass) && (guestName != tempName || guestPass != tempPass))
    {
        cout << "\n\t\t\t\t\tInvalid details. Please try again after exiting...";
        return 0;
    }
    else
    {
        int tempCaptcha;
        srand(time(0));
        int randomNumber = rand();
        cout << "\n\t\t\t\t\tCaptcha Code:  " << randomNumber;
        cout<< "\n\n\t\t\t\t\tInput:  ";
        cin>>tempCaptcha;
        if (!(tempCaptcha == randomNumber))
        {
            cout<<"\n\t\t\t\t\tWrong Captcha...";
            return 0;
        }
        
        cout << "\n\t\t\t\t\tSuccessfully Entered the Management... \n";
        if ((uName == tempName || pass == tempPass))
        {
            cout << "\n\t\t\t\t\tDo you wish to see the number of slots of vaccine avaialbe (Y/N)  ";
            char x;
            cin >> x;
            if (x == 'Y' || x == 'y')
            {
                cout << "\n\t\t\t\t\tThe available slots are: " << temp2.manageSlots() << endl;
                cout << "\n\t\t\t\t\tDo you wish to add slots of vaccine avaialbe (Y/N)  ";
                cin >> x;
                if (x == 'Y' || x == 'y')
                {
                    temp2.addSlots();
                }
            }
        }
    }
    cout << "\n\t\t\t\t\tDo you wish to continue:  ";
    char opt;
    cin >> opt;
    if (opt == 'Y' || opt == 'y')
    {
        vaccine project;
        project.menu();
        return 0;
    }

    return 0;
}
