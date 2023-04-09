#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;


vector<string> cities;

int main() {

    ifstream fin("post.in");

    // parse and store cities in array
    int i = 0;

    while (fin) {
        string city;
        fin >> city;
        cities.push_back(city);
        i++;
    }
    fin.close();

    //check if file is empty
    if (i == 1) {
        //exit and store "nothing" in file
        ofstream fout("post.out");
        fout << "nothing";
        fout.close();
        return 0;
    }

    //sort
    stable_sort(cities.begin(), cities.end(),
                [](string a, string b) {
                    return tolower(a[0]) > tolower(b[0]);
                });

    //export
    ofstream fout("post.out");
    i -= 2;
    for (; i >= 0; i--) {
        fout << cities[i] << (i == 0 ? "" : " ");
    }
    fout.close();
    return 0;
}
