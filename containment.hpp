#pragma once
#include <map>

//visszadja hogy egy adott map tartalmazza-e az adott kulcsot
using namespace std;
//T a kulcs típusa, C az értéknek a típusa ezt nem használjuk
template <typename T,typename C>
bool contain(map<T, C> map, T key) {
    //iterátorokkal végigmegyünk a map kulcsain
    for(auto i = map.begin(); i!=map.end(); i++) {
        //first a kulcsot adja vissza
        //ha a kulcs megegyezik a paraméterrel kapott értékkel akkor igazat ad vissza
        if(i->first == key) {
            return true;
        }
    }
    return false;
}

