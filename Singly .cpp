#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class NODE
{
public:
    string ID;
    string UNAME;
    string CAP;
    NODE *NEXT;
    NODE(string x, string y, string z)
    {
        ID = x;
        UNAME = y;
        CAP = z;
        NEXT = nullptr;
    }
};
class LinkList
{
public:
    string IID;
    int ICNT;
    string UName, UCAP;
    NODE *START,*END;
    int countNode;
    LinkList(){
        ICNT = 1001;
        countNode = 0;
        START = nullptr;
        END = nullptr;
    }
    void getData()
    {
        IID = "song"+ to_string(ICNT);
        cout<<"\GENERATE SONG ID -- "<<IID<<endl;
        cout<<"Enter ARTIST NAME  -- ";
        getline(cin,UName);
        cout<<"Enter SONG NAME -- ";
        getline(cin,UCAP);
    }
    char continueCheck()
    {
        char c;
        cout<<"\n\nAre you.. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Previous Menu\n";
        cout<<"3. Go to Main Menu..\n";
        cout<<"4. Exit\n";
        c = getch();
        if ( c == '4'){
            thanksLine();
            exit(0);
        }else{
            return (c);
        }
    }
    int insertNode(int opr)
    {
        system("cls");
        if ( opr == 1){
            cout<<"\n\nInsert SONG At Beginning . \n\n";
            getData();
            NODE *TEMP = new NODE(IID,UName, UCAP);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = START;
                START = TEMP;
            }
            countNode++;
            ICNT++;
        }
        else if ( opr == 2){
            cout<<"\n\nInsert  SONG At End . \n\n";
            getData();
            NODE *TEMP = new NODE(IID,UName, UCAP);

            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                END->NEXT = TEMP;
                END = TEMP;
            }
            countNode++;
            ICNT++;
        }
        else if ( opr == 3){
            cout<<"\n\nInsert SONG At Given Position . \n\n";
            cout<<"Total Songs -- "<<countNode<<"\n\n";
            int pos;
            getData();
            cout<<"Enter Position Between 0 to "<<countNode<<" -- ";
            cin>>pos;

            NODE *TEMP = new NODE(IID,UName, UCAP);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            int i;
            NODE *TEMP1 = START;
            for ( i = 2 ; i < pos ; i++){
                TEMP1 = TEMP1->NEXT;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT = TEMP;
                if ( TEMP1 == END){
                    END = TEMP1->NEXT;
                }
            }
            countNode++;
            ICNT++;
        }
        char c = continueCheck();
        if (c == '1')
            insertNode(opr);
        else if ( c == '2')
            insertionOperation();
        else if ( c == '3')
            MainMenu();
    }
    void showNode()
    {
        cout<<"\n\nPLAY LIST -- \n\n";
        cout<<"* Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"null \n\nPlay List is empty\n";
        }
        else{
            while ( TEMP!= nullptr){
                cout<<"["<<TEMP->ID<<", ";
                cout<<TEMP->UNAME<<", ";
                cout<<TEMP->CAP<<"] -> ";
                TEMP = TEMP->NEXT;
            }
            cout<<"Null";
        }
    }
    void countNodes()
    {
        system("cls");
        cout<<"Count Song Module --\n\n";
        cout<<"Total Number of Songs -- "<<countNode<<" Songs Available\n\n"
;    }
    int insertionOperation()
    {
        system("cls");
        cout<<"\nInsertion Operation..\n\n";
        cout<<"1. Insert SONG At Beginning\n";
        cout<<"2. Insert SONG At End\n";
        cout<<"3. Insert SONG After Data\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            insertNode(1);
        }
        else if ( c == '2'){
            insertNode(2);
        }
        else if ( c == '3'){
            insertNode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }
    }

    int deleteNode(int opr)
    {
        NODE *TEMP;
        if ( opr == 1){
            cout<<"\n\nDelete SONG From Beginning . \n\n";
            if ( START == nullptr)
            {
                cout<<"PlayList is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                START = START->NEXT;
            }
            countNode--;
            delete(TEMP);
            cout<<"\nSONG Deleted Successfully\n\n";
        }
        else if ( opr == 2){
            cout<<"\n\nDelete SONG From End . \n\n";
            if ( START == nullptr)
            {
                cout<<"PlayList is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                int c = 1;
                while ( TEMP->NEXT != END)
                {
                    cout<<c++<<endl;
                    TEMP = TEMP->NEXT;
                }
                NODE *T1 = END;
                TEMP->NEXT = nullptr;
                END = TEMP;
                cout<<END->UNAME<<endl;
                delete(T1);
            }
            countNode--;
            cout<<"\nSONG Deleted Successfully\n\n";
        }
        else if ( opr == 3){
            cout<<"\n\nDelete SONG From Given Position . \n\n";

            if ( START == nullptr)
            {
                cout<<"PlayList is Empty.. \n\n";
                return 0;
            }
            int pos;
            cout<<"Enter Position for Delete (1 - "<<countNode<<") - ";
            cin>>pos;
            if ( pos == 1 && START == END)
            {
                TEMP = START;
                START = END = nullptr;
            }
            else{
                TEMP = START;
                for (int i = 2 ; i < pos ; i++)
                {
                    TEMP = TEMP->NEXT;
                }
                if (TEMP->NEXT == END){
                    NODE *T1 = END;
                    TEMP->NEXT = nullptr;
                    END = TEMP;
                }
                else{
                    NODE *T1 = TEMP->NEXT;
                    TEMP->NEXT = T1->NEXT;
                    delete(T1);
                }
            }
            countNode--;
            cout<<"\nSONG Deleted Successfully\n\n";
        }
        char c = continueCheck();
        if (c == '1')
            deleteNode(opr);
        else if ( c == '2')
            deleteOperation();
        else if ( c == '3')
            MainMenu();
            return 0;
    }
    int deleteOperation()
    {
        system("cls");
        cout<<"\nDeletion Operation..\n\n";
        cout<<"1. Delete SONG From Beginning\n";
        cout<<"2. Delete SONG From End\n";
        cout<<"3. Delete SONG From Given Position\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            deleteNode(1);
        }
        else if ( c == '2'){
            deleteNode(2);
        }
        else if ( c == '3'){
            deleteNode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }

    }
    /*search module start*/

    int searchTweetInNode()
    {
        cout<<"\n\nSearch SONG in playList -- \n\n";
        cout<<"* Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"null \n\nPlaylist is empty\n";
            return 0;
        }
        else{
            cout<<"\n\nEnter ARTIST Name To Find SONG -- ";
            string uname;
            int counter = 0;
            getline(cin,uname);
            while ( TEMP!= nullptr){
                if (TEMP->UNAME == uname)
                {
                    cout<<"\n["<<TEMP->ID<<", ";
                    cout<<TEMP->UNAME<<", ";
                    cout<<TEMP->CAP<<"]\n";
                    counter++;
                }
                TEMP = TEMP->NEXT;
            }
            if ( counter == 0){
                cout<<"\nNo SONG Found..\n\n";
            }
        }
        char c;
        cout<<"\n\nAre you .. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Menu..\n";
        cout<<"3. Exit\n";
        c = getch();
        if (c == '1')
            searchTweetInNode();
        else if ( c == '2')
            MainMenu();
        else if ( c == '3'){
            thanksLine();
            exit(0);

        }
        return 0;
    }

    /*Search Module End*/
    int MainMenu()
    {
        system("cls");
        cout<<"========== LinkList Operation ==========\n\n";
        cout<<"1. Insertion Operation\n";
        cout<<"2. Traversal Operation\n";
        cout<<"3. Delete Operation\n";
        cout<<"4. Search Operation\n";
        cout<<"5. Count SONG\n";
        cout<<"6. Exit\n";
        cout<<"Choose One of them -- ";
        char c = getch();
        if ( c == '1'){
            insertionOperation();
        }
        else if ( c == '2'){
            showNode();
        }
        else if ( c == '3'){
            deleteOperation();
        }
        else if ( c == '4'){
            searchTweetInNode();
        }
        else if ( c == '5'){
            countNodes();
        }
        else if ( c == '6'){
            thanksLine();
            exit(0);
        }
        cout<<"\n\nDo you want to continue .. press 1 else any key..";
        c = getch();
        if ( c == '1'){
            MainMenu();
        }
    }
    void thanksLine()
    {
        cout<<"\n\nThanks for Using My APP\n\n";
    }
};
int main()
{
    LinkList l;
    l.MainMenu();
    cout<<"\n\nThanks for Using My APP\n\n";
}





