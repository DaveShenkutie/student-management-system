#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct student_Information
{
    int ID;
    int phone_no;
    char name[30];
    float gpa;
    student_Information *next;
}*head=NULL;
int choice;
int menu();
void record_entry();
void search_Entry();
void delete_Entry();
void display_list();
void update_Entry();
int main()
{
    char ans;
    do{
        menu();
       if(choice==1)
       {
        record_entry();
       }
       else if (choice==2)
       {
        search_Entry();
       }
       else if (choice==3)
       {
            update_Entry();
       }
       else if (choice==4)
       {
            display_list();
       }
       else if (choice==5)
       {
            delete_Entry();
       }
       else if (choice==6)
       {
            cout<<"Exit....";
            exit(1);
       }
       else
       {
           cout<<"\nInvalid input";
       }
    cout<<"\n\nwould you like to back to the main menu? [y/n]";
    cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 0;
}
int menu()
{
    cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\n\t\twelcome to student management system\n\n";

    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout<<"\n\n\t\t\tmain menu\n";
    cout<<"\t\t\a====================\n";
    cout<<"\n\n\t1. Create student record\n";
    cout<<"\n\n\t2. Search student record \n";
    cout<<"\n\n\t3. Modify student record\n";
    cout<<"\n\n\t4. Display all student records\n";
    cout<<"\n\n\t5. delete student record\n";
    cout<<"\n\n\t6. Exit\n";
    cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\nchoice: ";
    cin>>choice;
}
void record_entry()
{
system("cls");
char ans;
    do{
         char U_N[30];
         int P_N,id;
         float grade;
        student_Information *newNode=new student_Information;
        cout<<"ID: ";
        cin>>id;
        cin.ignore();
        cout<<"full name: ";
        cin.getline(U_N,30);
        cout<<"Phone number: ";
        cin>>P_N;
        cout<<"GPA: ";
        cin>>grade;
            newNode->ID=id;
            strcpy(newNode->name,U_N);
             newNode->gpa=grade;
             newNode->phone_no=P_N;
        if(head==NULL)
        {
            newNode->next=NULL;
            head=newNode;
        }

        else
            {
                newNode->next=head;
                head=newNode;
            }
        cout<<"\nto add more[y/n] : ";cin>>ans;
        system("cls");
    }while(ans=='y'||ans=='Y');
}


void search_Entry()
{
   system("cls");
    int finder,check=0;
    cout<<"enter the id of the entry that you want to search: ";
    cin>>finder;
     if(head==NULL)
        cout<<"empty list!!\n";
    else
    {
        student_Information *temp=head;
        while(temp!=NULL)
        {
        if(temp->ID==finder)
          {
              cout<<"Element founded...\n";
              check=1;
              break;
          }
          else
                temp=temp->next;
        }

        if(check==1)
        {
            cout<<"\npress any key to display it...";
            system("cls");
            getch();
         cout<<"\nID: "<<temp->ID;
         cout<<"\nName: "<<temp->name;
         cout<<"\nPhone number: "<<temp->phone_no;
         cout<<"\nGPA: "<<temp->gpa;
        }
        else
            cout<<"There is no element in the list that is equal to "<<finder<<endl;
    }
}

void delete_Entry()
{
    system("cls");
    int finder;
    cout<<"enter the ID to be searched: ";
    cin>>finder;
    if(head==NULL)
        cout<<"empty list hence there's nothing will be deleted\n";
    else
    {
        student_Information *temp1=head;
        student_Information *temp2;
        while(temp1->next!=NULL&&temp1->ID!=finder)
         {
             temp2=temp1;
             temp1=temp1->next;
         }

        if(temp1==NULL&&temp1->ID!=finder)
            cout<<"There's no element with such an ID.\n";
        else
        {
            cout<<"Element is founded\n";
            getch();
            if(temp1==head)
            {
                head=NULL;
                delete temp1;
            }
            else if(temp1->next==NULL)
            {
                temp2->next=NULL;
                delete temp1;
            }
            else
            {
            temp2->next=temp1->next;
            delete temp1;
            }
            cout<<"deletion completed!!\n";
        }
    }
}

void display_list()
{
    system("cls");
    if(head==NULL)
        cout<<"empty list!!\n";
    else
    {
        student_Information *temp=head;
        while(temp!=NULL)
        {
         cout<<"\nID: "<<temp->ID;
         cout<<"\nName: "<<temp->name;
         cout<<"\nPhone number: "<<temp->phone_no;
         cout<<"\nGPA: "<<temp->gpa;
         temp=temp->next;

        }
    }
}

void update_Entry()
{
    char newname[30];
    int newid,newphone;
    float newgpa;
   system("cls");
    int finder,check=0;
    cout<<"enter the id of the entry that you want to modify: ";
    cin>>finder;
     if(head==NULL)
        cout<<"empty list!!\n";
    else
    {
        student_Information *temp=head;
        while(temp!=NULL)
        {
        if(temp->ID==finder)
          {
              cout<<"Element founded...\n";
              check=1;
              break;
          }
          else
                temp=temp->next;
        }

        if(check==1)
        {
            cout<<"\nID: "<<temp->ID;
             cout<<"\nName: "<<temp->name;
             cout<<"\nPhone number: "<<temp->phone_no;
             cout<<"\nGPA: "<<temp->gpa;
             cout<<"\npress any key to update it...";
            system("cls");
            getch();
            cout<<"update the following...\n";
         cout<<"\ID: ";
          cin>>newid;
         cout<<"\nName: ";
         cin.ignore(),
          cin.getline(newname,30);
         cout<<"\nPhone number: ";
         cin>>newphone;
         cout<<"\nGPA: ";
         cin>>newgpa;
         temp->ID=newid;
         strcpy(temp->name,newname);
         temp->phone_no=newphone;
         temp->gpa=newgpa;
         cout<<"update completed ...\n";
        }
        else
            cout<<"There is no element in the list that is equal to "<<finder<<endl;
    }
}
