
#pragma once
#ifndef OBJ2_UZDUOTIS_FUNKCIJOS_H
#define OBJ2_UZDUOTIS_FUNKCIJOS_H
#include "studentai.h"

void isvestis (int s);
int studentu_kiekis();
void ivedimas (int i);
unsigned int countWordsInString(std::string const& str);
void FailoNuskaitymas( int &studentu_counter);
bool vardas_sort(const Duomenys& a, const Duomenys& b);


int st = 0;
vector<Duomenys> stud;
Duomenys dn;

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
    cout <<"Iveskite studento varda : "<< endl; cin>> stud.at(i).vardas;
    cout <<"Iveskite studento pavarde : "<< endl ;cin >> stud.at(i).pavarde;
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
            int g = stud.at(i).nd.size();
            do{
                cout << "Iveskite nr. "<< g + 1 <<" pazymi: "<< endl; cin >> namu_d;
                if(namu_d != 0){
                    if(namu_d >0 and namu_d <=10 ){
                        stud.at(i).nd.push_back(namu_d);
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
                    cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10! "<<endl ;cin.clear();
                    cin.ignore(10000, '\n');

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
                    stud.at(i).nd.push_back(sk);
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
                        stud.at(i).egzaminas = egz;

                    }
                    else{
                        cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;cin.clear();
                        cin.ignore(10000, '\n'); cin>> egz;}}
                while(!egz or egz > 10 or egz <0 );

            }
            else{
                srand((unsigned )time(0));
                egz = (rand() % 10) + 1;
                stud.at(i).egzaminas = egz;
            }
        }
        else{
            cout<<"Iveskite tinkama pasirinkima (R/A)!"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> egz;

        }


    }while(egz_ivedimas != 'A' && egz_ivedimas != 'a' && egz_ivedimas != 'R' && egz_ivedimas != 'r');



    stud.at(i).Vidurkis();
    stud.at(i).Mediana();


}
void isvestis ( int s) {




    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl; cin >> pasirinkimas;
    do {
        if (pasirinkimas && (pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)) {



            if (pasirinkimas == 1) {
                cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(17)<<"Galutinis(vid)"<<endl;
                for (int i = 0; i < s; i++) {
                    cout << setw(20) << stud.at(i).vardas << setw(20) << stud.at(i).pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud.at(i).vid << setw(17);}

            } else if (pasirinkimas == 2) {
                cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<< setw(20)<<"Galutinis(med)"<<endl;
                for (int i = 0; i< s; i++) {
                    cout << setw(20) << stud.at(i).vardas << setw(20) << stud.at(i).pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud.at(i).med << endl;
                }
            } else {
                cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(17)<<"Galutinis(vid)"<< setw(20)<<"Galutinis(med)"<<endl;
                for (int i = 0; i < s; i++) {
                    cout << setw(20) << stud.at(i).vardas << setw(20) << stud.at(i).pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud.at(i).vid << setw(17) << stud.at(i).med << endl;
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
void FailoNuskaitymas(int &studentu_counter){
    try {
        stud.push_back(Duomenys());
        int pazymiu_sk = 0;
        int student_counter = 0;
        int temp;
        ifstream nuskaiFailas;
        string buff;
        nuskaiFailas.open("kursiokai.txt");
        nuskaiFailas.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        if (nuskaiFailas.is_open()) {
            getline(nuskaiFailas >> std::ws, buff);
            pazymiu_sk = countWordsInString(buff) - 3;
            while (true) {

                stud.resize(stud.size() + 1);
                nuskaiFailas >> stud.at(student_counter).vardas;

                if (nuskaiFailas.eof()) {
                    stud.pop_back();
                    break;
                }
                nuskaiFailas >> stud.at(student_counter).pavarde;

                for (int i = 0; i < pazymiu_sk; i++) {
                    nuskaiFailas >> temp;
                    stud.at(student_counter).nd.push_back(temp);
                }
                nuskaiFailas >> stud.at(student_counter).egzaminas;

                stud.at(student_counter).Mediana();
                stud.at(student_counter).Vidurkis();
                stud.push_back(dn);
                st = student_counter;
                student_counter++;

            }

        }


        }
    catch(std::exception const& e){
        cout << "Ivyko problema nuskaitant faila" << endl;
    }

}

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());

}
bool vardas_sort(const Duomenys& a, const Duomenys& b)
{
    if (a.vardas != b.vardas)
        return a.vardas > b.vardas;
    if (a.pavarde != b.pavarde)
        return a.pavarde > b.pavarde;

}
#endif //OBJ2_UZDUOTIS_FUNKCIJOS_H