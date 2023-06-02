//
// Created by Zear on 6/2/2023.
#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class read_from_file {
private:
    // a 3 betus szavak gyakorisagat egy map-ben taroljuk, ahol a kulcs a szo, az ertek pedig az hogy hany van belole
    //statikus tehát az osztályhoz tartozik nem csak az adott obijektumhoz
    static map<string, int> word_freq;
public:
    //beolvas egy fajlból hogy melyik szóból hány darab van
    void read_word_freq(string filename);

    void get_word_freq();


    //visszaadja hogy melyik a top 5 leggyakoribb szó a szövegben
    // a visszaadott map kulcsa a szó értéke a szó helyére írandó !szam
    map<string, string> get_top_five();
};


