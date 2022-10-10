#pragma once
#include <bits/stdc++.h>
#include <iostream>

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "fstream"
#include "sstream"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::sort;
using std::ifstream;






struct Duomenys {
    string vardas = "";
    string pavarde= "";
    vector<double> nd; //namu darbai
    double egzaminas = 0;
    double vid = 0;
    double med = 0;
    void Vidurkis(){
        double sum_vid = 0;
        for (int i=0; i < nd.size();i++) sum_vid+= nd.at(i);
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