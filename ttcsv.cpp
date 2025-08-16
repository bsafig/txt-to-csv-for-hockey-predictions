#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    for(int i = 2007; i < 2025; i++) {
        ifstream txtFile("./Inputs/" + to_string(i) + ".txt");
        ofstream csvFile("./Outputs/" + to_string(i) + ".csv");

        if(!txtFile.is_open()) {
            cerr << "Error: Could not open ./Inputs/" << to_string(i) << ".txt" << endl;
            continue;
        }
        if(!csvFile.is_open()) {
            cerr << "Error: Could not open ./Outputs/" << to_string(i) << ".csv" << endl;
            txtFile.close();
            continue;
        }

        string line;
        while(getline(txtFile, line)) {
            for(char &c : line) {
                if(c == '\t') c = ',';
            }
            csvFile << line << "\n";
        }
        txtFile.close();
        csvFile.close();
        cout << "Conversion complete: ./Outputs/" << to_string(i) << ".csv" << endl;
    }
    return 0;
}
