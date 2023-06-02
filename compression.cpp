//
// Created by Zear on 6/2/2023.
//

#include "compression.h"
#include "containment.hpp"
//sima fájlból !-es tömörített fájlt csinál
void compression::compress(string read_from, string write_to, map<string, string> replacement) {
    std::ifstream in_file;
    std::ofstream out_file;
    in_file.open(read_from, ios::in);
    out_file.open(write_to, ios::out);
    //irjuk ki a tomorites jelenteset
    for(auto i = replacement.begin(); i != replacement.end(); i++) {
        out_file << i->second << ' ' << i->first << endl;
    }
    //the current word, we either replace it or not
    string curr_word;
    while(in_file >> curr_word) {
        if(contain(replacement, curr_word)) {
            out_file << replacement.at(curr_word);
            out_file << ' ';
        }else{
            out_file << curr_word << " ";
        }
    }

    in_file.close();
    out_file.close();

}
//felkiáltójeles tömörített fájlból sima fájlt csinál
void compression::decompress(string read_from, string write_to)  {
    //itt a kulcs lesz a !szam és az ertek a szo amivel kicsereljuk
    map<string, string> replacement;

    std::ifstream in_file;
    std::ofstream out_file;
    in_file.open(read_from, ios::in);
    out_file.open(write_to, ios::out);
    string curr_word;

    //elso 5 sorban kell lennie a cserelendo adatoknak
    for(int i = 0; i < 5; i++) {
        string key;
        string value;
        in_file >> key;
        in_file >> value;
        replacement[key] = value;
    }
    while(in_file >> curr_word) {
        if(contain(replacement, curr_word)) {
            out_file << replacement.at(curr_word);
            out_file << ' ';
        }else{
            out_file << curr_word << " ";
        }
    }
    in_file.close();
    out_file.close();
}


