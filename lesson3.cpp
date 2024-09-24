#include <iostream>
using namespace std;
#include <string> 
class Data {
public:
    int dayy;
    int monthh;
    int yearr;
    Data() :dayy{ 0 }, monthh{ 0 }, yearr{ 0 } {}
    Data(int day, int month ,int year) :dayy{ day }, monthh{ month }, yearr{ year } {}
    void print() { cout << dayy << "/" << monthh << "/" << yearr << endl; }
};
class  Human {
    int index;
    char* Prizv;
    char* name;
    char* Pobatkovi;
    Data birth;
    static int plus;
public:
    Human() :index{ 0 }, Prizv{ nullptr }, name{ nullptr },Pobatkovi{nullptr}, birth{0,0,0} {
        plus += 1;
    }
    Human() = delete;
    Human(int ind, const char* Prizvv, const char* nam, const char* Po, int day, int month, int year) :index{ind}, birth{day,month,year} {
        Pobatkovi = new char[20];
        Prizvv = new char[20];
        name = new char[20];
        strcpy_s(Pobatkovi, 20, Po);
        strcpy_s(Prizv, 20, Prizvv);
        strcpy_s(name, 20, nam);
        plus += 1;
    }
    Human(const Human&& human) 
        :index{ human.index }, Prizv{ human.Prizv }, name{ human.name }, Pobatkovi{ human.Pobatkovi }, birth{ human.birth } {
        human.index = 0;
        human.Prizv = nullptr;
        human.name= nullptr;
        human.Pobatkovi = nullptr;
        human.birth = { nullptr };
    }
    Human operator=(Human&& human)  {
        if (!(this == &human)) {
            delete Prizv;
            delete name;
            delete Pobatkovi;
            
            index = human.index;
            Prizv = human.Prizv;
            name = human.name;
            Pobatkovi = human.Pobatkovi;
            birth = human.birth;

            human.index = 0;
            human.Prizv = nullptr;
            human.name = nullptr;
            human.Pobatkovi = nullptr;
        }
        return *this;
    }
    void Print(){
        cout << index<<" , " << Prizv << " , " << name << " , " << Pobatkovi << " , ";
        birth.print();
    }
    ~Human() {
        delete[] Prizv;
        delete[] name;
        delete[] Pobatkovi;
        plus-= 1;
    }
    int Count() {
        return plus;
    }
};
class Flat {
    int kil;
    Human *Kvart;
public:
    Flat():kil{0},Kvart{nullptr}{}
    Flat(Human humans[], int num) : kil{num} {
        Kvart = new Human[kil];
        for (short i = 0; i < kil; i++) {
            Kvart[i] = humans[i];
        }
    }
    Flat(const Flat&& flatt) :kil{ flatt.kil }, Kvart{ flatt.Kvart } {
        flatt.kil = 0;
        flatt.Kvart = nullptr;
    }
    Flat operator=(Flat&& flatt) {
        if (!(this == &flatt)) {
            delete Kvart;

            kil = flatt.kil;
            Kvart = flatt.Kvart;

            flatt.kil = 0;
            flatt.Kvart = nullptr;
        }
        return *this;
    }
    ~Flat() {
        delete[] Kvart;
    }
    void Prrint() {
        for (short i = 0; i < kil; i++) {
            Kvart[i].Print();
        }
    }
};
class Building {
    int num;
    Flat *flats;
public:
    Building(Flat* flatss, int numm) : num{ numm } {
        flats = new Flat[num];
        for (int i = 0; i < num; i++) {
            cout<<endl << "Flat " << i + 1 << ": "<<endl;
            flats[i] = flatss[i];
             flats[i].Prrint();
            cout << endl;
        }
    }
    ~Building() {
        delete[] flats; 
    }
};
int Human::plus = 0;
int main() {
    Human Humans1[] = { {48,"Julas","Roman","Olegovich",28,01,1978} };

    Human Humans2[] = { {28,"Polyanin","Illya","Volodimirovich",02,03,1996},{ 31,"Lickov","Fil","Yanovich",06,9,1992 } };

    Human Humans3[] = { {24,"Kopad","Lolita","Victorovna",04,06,2001},  
                        { 24,"Kopad","Tom","Romanovich",15,10,2000 },
                        {3,"Kopad","Koralina","Tomovna",25,07,2021 } };

    Human Humans4[] = { {57,"Litiy","Lola","Genadiivna",17,8,1967},
                        { 68,"Litiy","Lars","Ulrihovich",21,04,1958 },
                        {36,"Litiy","Yaroslav","Larsovich",25,07,1988 },
                        {29,"Litiy","Marta","Larsovich",25,07,1995 } };

    Human Humans5[] = { {26,"Nokil","Lora","Yaroslavovna",3,2,1998},
                        { 30,"Nokil","Svyatoslav","Nikonorovich",21,04,1993 },
                        {6,"Nokil","Lev","Svyatoslavovich",4,12,2018 },
                        {4,"Nokil","Margarita","Svyatoslavovich",13,11,2020 },
                        {4,"Nokil","Pavel","Svyatoslavovich",13,11,2020 } };
    Flat Kvar1{ Humans1,1 };
    Flat Kvar2{ Humans2,2};
    Flat Kvar3{ Humans3,3 };
    Flat Kvar4{ Humans4,4 };
    Flat Kvar5{ Humans5,5 };
    Flat Kvar6{ Kvar4 };
    Flat kvar7{ Kvar1 };
    Flat Kvar8{  Kvar5 };
    Flat Kvar9 { Kvar3 };
    Flat Kvar10{ Kvar2 };
    Flat Kvar11{ Kvar1 };
    Flat Kvar12{ Kvar1 };
    Flat Kvar13{ Kvar3 };
    Flat Kvar14{ Kvar4 };
    Flat Kvar15{ Kvar2 };
    Flat Kvar16{ Kvar5 };
    Flat Kvar17{ Kvar3 };
    Flat Kvar18{ Kvar2 };
    Flat Kvar19{ Kvar3 };
    Flat Kvar20{ Kvar2 };
    Flat flats[] = { Kvar1,Kvar2,Kvar3,Kvar4,Kvar5,Kvar6,Kvar7,Kvar8,Kvar9,Kvar10,Kvar11,
        Kvar12,Kvar13,Kvar14,Kvar15,Kvar16,Kvar17,Kvar18,Kvar19,Kvar20 };
    Building home{ flats, 20 };
    return 0;
}