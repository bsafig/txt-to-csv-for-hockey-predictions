#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    for(int season = 2007; season < 2025; season++) {
        ifstream txtFile("./Inputs/" + to_string(season) + ".txt");
        ofstream csvFile("./Outputs/" + to_string(season) + ".csv");

        if(!txtFile.is_open()) {
            cerr << "Error: Could not open ./Inputs/" << to_string(season) << ".txt" << endl;
            continue;
        }
        if(!csvFile.is_open()) {
            cerr << "Error: Could not open ./Outputs/" << to_string(season) << ".csv" << endl;
            txtFile.close();
            continue;
        }

        string line;
        csvFile << "Season,Team,Wins,Points,P%,RW,ROW,S/OW,GF,GA,GF/GP,GA/GP,PP%,PK%,NetPP%,NetPK%,Shots/GP,SA/GP,FOW%,Winner\n";
        while(getline(txtFile, line)) {
            for(char &c : line) {
                if(c == '\t') c = ',';
            }
            csvFile << to_string(season) << "," << line << "\n";
        }
        txtFile.close();
        csvFile.close();
        cout << "Conversion complete: ./Outputs/" << to_string(season) << ".csv" << endl;
    }
    return 0;
}
