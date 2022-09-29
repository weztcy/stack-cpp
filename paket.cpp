#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;
int datake=0;
int datamaks=3;
struct paket{
    char item[30];
    int weight;
    char destination[30];
};

struct paket kirim[50];

void bersihlayar(){
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b); cout << " ";
        }
    }
}

void tambahdata(int x){
    if(datake<datamaks){
        gotoxy(20,15); cout << "Inputkan nama produk:  :";
            cin >> kirim[x].item;
        gotoxy(20,16); cout << "Inputkan weight         :";
            cin >> kirim[x].weight;
        gotoxy(20,17); cout << "Inputkan destination tujuan   :";
            cin >> kirim[x].destination;
    }
    else{
        gotoxy(40,19);
        cout << "Data full, cant add any data!";
        gotoxy(40,20);
        cout << "Press any key...";
        getch();
    }
}

void tampildata(int x){
    gotoxy(40,10); cout << "Daftar Kiriman Paket" << endl;
    for(int a=0; a<datake; a++){
        gotoxy(40,19-a);
        cout << a+1 << " ";
        cout << kirim[a].item << " ";
        cout << kirim[a].weight << " ";
        cout << kirim[a].destination << endl;
    }
    gotoxy(40,20);
    cout << "Press any key...";
    getch();
    /*Perlu #include<conio.h>*/
}

void hapusdata(int x)
{
    if(datake>0){
        gotoxy(40,12); cout << "Data Terakhir yang anda Hapus Adalah :" << endl;
        gotoxy(40,13); cout << kirim[x].item<<" ";
        cout << kirim[x].weight<<" Kg ";
        cout << kirim[x].destination << endl << endl;

        gotoxy(40,15); cout << "Press any key...";
        getch();
    }
    else{
        gotoxy(40,19);
        cout << "Data empty, cant delete any data";
        gotoxy(40,20);
        cout << "Press any key...";
        getch();
    }
}

int main()
{
    int pilih;
    do{
        bersihlayar();
        gotoxy(1,1); cout << "Menu Option";
        gotoxy(1,2); cout << "1. Add data";
        gotoxy(1,3); cout << "2. Delete last data" << endl;
        gotoxy(1,4); cout << "3. Show data" << endl;
        gotoxy(1,5); cout << "9. Exit" << endl;
        gotoxy(1,7); cout << "Pilihan Anda [1-9] : ";
            cin >> pilih;
        if(pilih==1){
            tambahdata(datake);
            datake++;
        }
        if(pilih==2){
            hapusdata(datake-1);
            datake--;
        }
        if(pilih==3)
            tampildata(datake);
    }
    while(pilih!=9);
    return 0;
}
