#include<iostream>
#include<conio.h>
#include"singlylinklist.cpp"
#include"dubblylinklist.cpp"
class MainLinkList
{
public:
    LinkList l;
    DLinkList dl;
    void MainLinkListModule()
    {
        system("cls");
        cout<<"------ WELCOME MUSIC SYSTEM PROJECT ------\n\n";
        cout<<"1. Singly Link List \n\n";
        cout<<"2. Doubly Link List \n\n";
        cout<<"3. Exit \n\n";
        cout<<"Choose any one of them....";
        char c = getch();
        if ( c == '1'){
            l.MainMenu();
        }
        else if ( c == '2'){
            dl.MainMenu();
        }
        else if ( c == '3'){
            exit(0);
        }
    }
};
int main()
{
    MainLinkList mll;
    mll.MainLinkListModule();
    cout<<"\n\nThank You for Using My App..\m\m";
    cout<<"Design & Coded By -- Akshita Surana .. \n\n";
}

