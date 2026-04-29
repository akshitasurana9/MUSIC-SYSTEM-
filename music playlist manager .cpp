#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class NODE
{
public:
    string SID;
    string SONG;
    string ARTIST;
    NODE *NEXT;

    NODE(string id, string s, string a)
    {
        SID = id;
        SONG = s;
        ARTIST = a;
        NEXT = nullptr;
    }
};

class LinkList
{
public:
    string SID;
    int SCNT;
    string SongName, ArtistName;
    NODE *START, *END;
    int countNode;

    LinkList(){
        SCNT = 1001;
        countNode = 0;
        START = nullptr;
        END = nullptr;
    }

    void getData()
    {
        SID = "SONG" + to_string(SCNT);
        cout<<"\nGenerated Song ID -- "<<SID<<endl;

        cout<<"Enter Song Name -- ";
        getline(cin, SongName);

        cout<<"Enter Artist Name -- ";
        getline(cin, ArtistName);
    }

    char continueCheck()
    {
        char c;
        cout<<"\n\n1. Continue Same\n";
        cout<<"2. Previous Menu\n";
        cout<<"3. Main Menu\n";
        cout<<"4. Exit\n";

        c = getch();

        if (c == '4'){
            thanksLine();
            exit(0);
        }
        return c;
    }

    int insertNode(int opr)
    {
        system("cls");

        if (opr == 1)
            cout<<"\nInsert Song At Beginning\n";
        else if (opr == 2)
            cout<<"\nInsert Song At End\n";

        getData();
        NODE *TEMP = new NODE(SID, SongName, ArtistName);

        if (START == nullptr){
            START = END = TEMP;
        }
        else if (opr == 1){
            TEMP->NEXT = START;
            START = TEMP;
        }
        else if (opr == 2){
            END->NEXT = TEMP;
            END = TEMP;
        }

        countNode++;
        SCNT++;

        cout<<"\nSong Added Successfully!\n";

        char c = continueCheck();
        if (c == '1') insertNode(opr);
        else if (c == '2') insertionOperation();
        else if (c == '3') MainMenu();
    }

    void showNode()
    {
        system("cls");
        cout<<"\n🎵 Playlist:\n\n";

        NODE *TEMP = START;

        if (START == nullptr){
            cout<<"Playlist Empty\n";
        }
        else{
            while (TEMP != nullptr){
                cout<<"["<<TEMP->SID<<" | "<<TEMP->SONG<<" | "<<TEMP->ARTIST<<"] -> ";
                TEMP = TEMP->NEXT;
            }
            cout<<"NULL\n";
        }
    }

    void countNodes()
    {
        cout<<"\nTotal Songs: "<<countNode<<"\n";
    }

    int insertionOperation()
    {
        system("cls");

        cout<<"\nAdd Songs\n\n";
        cout<<"1. Add at Beginning\n";
        cout<<"2. Add at End\n";
        cout<<"3. Main Menu\n";
        cout<<"4. Exit\n";

        char c = getch();

        if (c == '1') insertNode(1);
        else if (c == '2') insertNode(2);
        else if (c == '3') MainMenu();
        else if (c == '4'){
            thanksLine();
            exit(0);
        }
    }

    int deleteNode(int opr)
    {
        NODE *TEMP;

        if (START == nullptr){
            cout<<"\nPlaylist Empty\n";
            return 0;
        }

        if (opr == 1){
            TEMP = START;
            START = START->NEXT;
            if (START == nullptr) END = nullptr;
        }
        else if (opr == 2){
            TEMP = START;
            while (TEMP->NEXT != END){
                TEMP = TEMP->NEXT;
            }
            delete END;
            END = TEMP;
            END->NEXT = nullptr;
        }

        countNode--;
        cout<<"\nSong Deleted Successfully\n";

        char c = continueCheck();
        if (c == '1') deleteNode(opr);
        else if (c == '2') deleteOperation();
        else if (c == '3') MainMenu();
    }

    int deleteOperation()
    {
        system("cls");

        cout<<"\nDelete Songs\n\n";
        cout<<"1. Delete From Beginning\n";
        cout<<"2. Delete From End\n";
        cout<<"3. Main Menu\n";
        cout<<"4. Exit\n";

        char c = getch();

        if (c == '1') deleteNode(1);
        else if (c == '2') deleteNode(2);
        else if (c == '3') MainMenu();
        else if (c == '4'){
            thanksLine();
            exit(0);
        }
    }

    int searchSong()
    {
        system("cls");

        cout<<"\nSearch Song\n\n";

        if (START == nullptr){
            cout<<"Playlist Empty\n";
            return 0;
        }

        string name;
        cout<<"Enter Song Name: ";
        getline(cin, name);

        NODE *TEMP = START;
        int found = 0;

        while (TEMP != nullptr){
            if (TEMP->SONG == name){
                cout<<"\nFound: "<<TEMP->SID<<" | "<<TEMP->SONG<<" | "<<TEMP->ARTIST<<"\n";
                found++;
            }
            TEMP = TEMP->NEXT;
        }

        if (found == 0)
            cout<<"\nSong Not Found\n";

        char c = continueCheck();
        if (c == '1') searchSong();
        else if (c == '3') MainMenu();
    }

    void playSongs()
    {
        system("cls");

        NODE *TEMP = START;

        if (START == nullptr){
            cout<<"Playlist Empty\n";
            return;
        }

        cout<<"\n🎧 Playing Playlist...\n\n";

        while (TEMP != nullptr){
            cout<<"Now Playing: "<<TEMP->SONG<<" - "<<TEMP->ARTIST<<"\n";
            getch();
            TEMP = TEMP->NEXT;
        }
    }

    int MainMenu()
    {
        system("cls");

        cout<<"====== 🎵 Playlist Manager ======\n\n";
        cout<<"1. Add Songs\n";
        cout<<"2. Show Playlist\n";
        cout<<"3. Delete Songs\n";
        cout<<"4. Search Song\n";
        cout<<"5. Play Playlist\n";
        cout<<"6. Count Songs\n";
        cout<<"7. Exit\n";

        char c = getch();
        cin.ignore();

        if (c == '1') insertionOperation();
        else if (c == '2'){ showNode(); getch(); }
        else if (c == '3') deleteOperation();
        else if (c == '4') searchSong();
        else if (c == '5') playSongs();
        else if (c == '6'){ countNodes(); getch(); }
        else if (c == '7'){
            thanksLine();
            exit(0);
        }

        MainMenu();
    }

    void thanksLine()
    {
        cout<<"\n\n🎵 Thanks for Using Playlist Manager 🎵\n";
    }
};

int main()
{
    LinkList l;
    l.MainMenu();
}
