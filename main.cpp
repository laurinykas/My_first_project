
#include "funkcijos.h"
int main() {
    int pasirinkimas;
    cout << "Irasykite 1, jei norite duomenis rasyti ranka.\nIrasykite 2, jei duomenis nuskaityti is failo.\n";
    do {
        cin >> pasirinkimas;
        switch (pasirinkimas) {

            case 1:
                st = studentu_kiekis();
                for (int d = 0; d < st; d++) {
                    ivedimas(d);
                    stud.push_back(dn);
                }
                isvestis(st);
                break;
            case 2:

                FailoNuskaitymas(st);
                sort(stud.begin(), stud.end(), vardas_sort);
                isvestis(st);
                break;

            default:

                cout << "Neteisinga ivestis. Iveskite 1 arba 2. " << endl;
                cin.clear(); //isvaloma neteisinga ivestis
                cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties
                break;

        }

    } while (pasirinkimas != 1 && pasirinkimas != 2);
}