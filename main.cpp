#include <iostream>
#include "read_from_file.h"
#include "compression.h"
int main() {
    read_from_file file;
    file.read_word_freq("..\\test.txt");
    file.get_word_freq();
    map<string, string> top_five = file.get_top_five();
    for(auto i : top_five) {
        cout << i.first << " " << i.second << endl;
    }
    compression comp;
    comp.compress("..\\test.txt", "..\\out.txt", top_five);
    comp.decompress("..\\out.txt", "..\\dectest.txt");
}
