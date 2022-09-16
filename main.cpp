#include <iostream>
//
// Created by Laurynas on 9/12/2022.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::sort;



struct Duomenys {
    string vardas = "";
    string pavarde= "";
    vector<double> nd; //namu darbai
    double egzaminas = 0;
    double vid = 0;
    double med = 0;
    void Vidurkis(){
        double sum_vid = 0;
        for (int i=0; i < nd.size();i++) sum_vid+= nd[i];
        vid =  ((sum_vid/nd.size())*0.4)+(0.6*egzaminas);
    }
    void Mediana(){
        if (nd.size()>= 1){
            std::sort(nd.begin(), nd.end());
            if (nd.size()% 2 == 0){
            med = nd[nd.size()/2 - 1] + nd[nd.size()/2]/2;
            }
            else{
            med = nd[(nd.size()/2)];}
        }
        else {
            med = 0;
        }
        med = 0.4 * med + 0.6 * egzaminas;
    }

};
void isvestis ();
int studentu_kiekis();
void ivedimas (int i);
int s = studentu_kiekis();
vector <Duomenys> stud;
Duomenys dn;
int main() {

    for(int d = 0;d < s;d++){
        ivedimas(d);
        stud.push_back(dn);
    }
        isvestis();

}


int studentu_kiekis() {

    int studentu_sk = 0;
    cout << "Iveskite studentu kieki: " << endl;cin >> studentu_sk;
    do {

        if (studentu_sk && studentu_sk > 0) {
            return studentu_sk;}
        else {
            cout << "Neteisingai ivestas studentu skaicius, bandykite dar karta\n"
                    "Iveskite studentu kieki: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> studentu_sk;}

    }
    while (!(studentu_sk && studentu_sk > 0));

}
void ivedimas ( int i){
    stud.push_back(Duomenys());
    char ranka_auto;
    cout <<"Iveskite studento varda : "<< endl; cin>> stud[i].vardas;
    cout <<"Iveskite studento pavarde : "<< endl ;cin >> stud[i].pavarde;
    cout << "Kaip ivesite pazymius (jeigu ranka rasykite R, jei auto rasykite A :"<< endl; cin >> ranka_auto;
    do{
        if(ranka_auto and (ranka_auto == 'R' or ranka_auto == 'r' or ranka_auto == 'A' or ranka_auto =='a'  )){
            continue;}
        else{
            cout<< "Irasykite R arba A !"<< endl;cin.clear();
            cin.ignore(10000,'\n'); cin >> ranka_auto;}}
    while(!(ranka_auto and (ranka_auto == 'R' or ranka_auto == 'r' or ranka_auto == 'A' or ranka_auto =='a'  )));
    char tp;
    int uzsibaigimas = 0;
    if (ranka_auto == 'R' or ranka_auto == 'r'){
        while(uzsibaigimas == 0){
            int namu_d = 0;
            int g = stud[i].nd.size();
            do{
            cout << "Iveskite nr. "<< g + 1 <<" pazymi: "<< endl; cin >> namu_d;
            if(namu_d != 0){
                if(namu_d >0 and namu_d <=10 ){
                    stud[i].nd.push_back(namu_d);
                    cout << "Ar bus dar pazymiu ? (T/N)"<< endl ;cin>> tp;
                    do{
                        if(tp and(tp =='T' or tp == 't' or tp == 'n' or tp == 'N')){
                            if(tp == 'T' or tp == 't'){
                                continue;
                            }
                            if(tp == 'n' or tp == 'N'){
                                uzsibaigimas = 1;
                            }
                        }
                        else{
                            cout<< "Iveskite tinkama atsakyma T arba N !"<< endl;cin.clear();
                            cin.ignore(10000, '\n');cin>> tp;
                        }
                    }while(tp !='T' and tp != 't' and tp != 'n' and tp != 'N');
                }
                else{
                    cout<<"Iveskite tinkama skaicius nuo 1 iki 10!"<< endl ;

                }


            }
            else{
                cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;cin.clear();
                cin.ignore(10000, '\n'); cin>> namu_d;

            }

            }

            while( namu_d == 0);
        }
    }
    else{
            int nd_skaicius = 0; int sk = 0;
            // random gen
            cout <<"Iveskite kiek namu darbu noresite sugeneruoti"<< endl; cin>> nd_skaicius;
            do {
                srand((unsigned )time(0));
                if (nd_skaicius and nd_skaicius > 0) {
                        for (int e = 0;e < nd_skaicius; e++){
                           sk = (rand() % 10) + 1;
                            stud[i].nd.push_back(sk);
                        }

                } else {
                    cout << "Iveskite skaiciu didesni nei 1! : " << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cin >> nd_skaicius;
                }
                }
            while(nd_skaicius < 0 or nd_skaicius == 0);

    }
    char egz_ivedimas; int egz = 0 ;
    cout << "Ar norite ranka ivesti egzamina ar auto (R/A)"<<endl; cin>> egz_ivedimas;
    do{
        if(egz_ivedimas and( egz_ivedimas == 'R'|| egz_ivedimas == 'r'|| egz_ivedimas == 'A' || egz_ivedimas == 'a')){
            if (egz_ivedimas=='R' or egz_ivedimas == 'r' )
            {
                cout << "Iveskite egzamino rezultata"<< endl ; cin>> egz;
                do{
                    if(egz and egz > 0 and egz <=10){
                        stud[i].egzaminas = egz;

                    }
                    else{
                        cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;cin.clear();
                        cin.ignore(10000, '\n'); cin>> egz;}}
                while(!egz or egz > 10 or egz <0 );

            }
            else{
                srand((unsigned )time(0));
                egz = (rand() % 10) + 1;
                stud[i].egzaminas = egz;
            }
        }
        else{
            cout<<"Iveskite tinkama pasirinkima (R/A)!"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> egz;

        }


    }while(egz_ivedimas != 'A' && egz_ivedimas != 'a' && egz_ivedimas != 'R' && egz_ivedimas != 'r');



    stud[i].Vidurkis();
    stud[i].Mediana();


}
void isvestis ( ) {



    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl; cin >> pasirinkimas;
    do {
        if (pasirinkimas && (pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)) {



                if (pasirinkimas == 1) {
                    cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(17)<<"Galutinis(vid)"<<endl;
                    for (int i = 0; s > i; i++) {
                    cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud[i].vid << setw(17);}

                } else if (pasirinkimas == 2) {
                    cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<< setw(20)<<"Galutinis(med)"<<endl;
                    for (int i = 0; s > i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].med << endl;
                    }
                } else {
                    cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(17)<<"Galutinis(vid)"<< setw(20)<<"Galutinis(med)"<<endl;
                    for (int i = 0; s > i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].vid << setw(17) << stud[i].med << endl;
                    }
                }


            }
         else {
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 10!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;
         }
        }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);


    }
