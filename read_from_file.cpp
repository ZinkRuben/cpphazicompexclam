#include "read_from_file.h"
#include "containment.hpp"
void read_from_file::read_word_freq(std::string filename) {
    //megnyitjuk a file olvasási módban
    std::ifstream file;
    file.open(filename, ios::in);
    if (file.is_open()) {
        std::string curr_word;
        std::string line;
        //a fájlból beolvasunk szavakat fájl végéig
        while(file >> curr_word) {
            //ha a jelenlegi szó mérete nagyobb vagy egyenlo 3 akkor megnoveljuk a map-ben a hozzá tartozó értéket 1-el
            if(curr_word.size()>=3) {
                //mivel operator[]-t használunk ezért, ha nincs benne akkor hozzádja 0-ás értékkel és ezt megnöveli 1-el tehát egy lesz az értéke
                word_freq[curr_word]++;
            }
        }
        file.close();
        }else{
        throw "file can't be opened";
    }
        }
//teszteléshez
void read_from_file::get_word_freq() {
    //kiírja a map-ben lévő szavak gyakoriságát (hany darab volt belőle a szövegben)
    for(auto i = word_freq.begin(); i!=word_freq.end(); i++) {
        //first kiírja a kulcsot (az adott szót) second : kiírja az értéket (hány db volt az adott szóból)
        std::cout << i->first << ":" << i->second << endl;
    }


}
//visszaadja a top 5 leggyakoribb szót a szövegből
map<string, string> read_from_file::get_top_five() {
    //a kulcs a szo, az ertek pedig !szam, amit a helyere irunk majd
    map<string, string> res;
    //kell hogy legyen a szövegben 5 db szó ami legalább 3 betű különben exception-t dobunk, úgy nem lehetne tömöríteni
    if(word_freq.size() < 5) {
        throw "nincs 5 db 3 betunel hosszabb szo";
    } else{
        //hasznaljunk iteratorokat
        //keressunk maxot egymas utan 5x
        int j = 0;
        int max = 0;
        string max_str;
        while(j < 5) {
            //az elejétől a végéig automatikusan megnéi hogy melyik szó fordul elő a legtöbbször
        for(auto i = word_freq.begin(); i != word_freq.end(); i++) {
            if(i->second > max) {
                max = i ->second;
                max_str = i->first;
            }
        }
            //allitsuk 0-ra a max stringet a freq-ben hog a kovetkezo max keresesnel ne legyen benne
            word_freq[max_str] = 0;
            j++;
            string exclam_and_num = "!";
            //elkészítjuk a !1 !2 !3 !4 !5 stringeket és értékül adjuk a hozzájuk tartozó szavaknak a map-ben
            exclam_and_num += (char)(j+'0');
            res[max_str] = exclam_and_num;
            //maxot nullára állítjuk a követketkező keresés miatt
            max = 0;
    }
    }
    return res;
}


