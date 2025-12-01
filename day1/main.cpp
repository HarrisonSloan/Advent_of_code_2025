#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


int problem1() {
    ifstream inputFile; 
    string line;
    inputFile.open("input.txt", ios::in);

    vector<int> intructions;
    intructions.push_back(50);

    char dir;
    int degree;
    int total = 0;

    while(getline(inputFile,line)) {
        stringstream ss(line);
        ss >> dir;
        ss >> degree;
        degree = degree % 100;
        if (dir == 'L') {
            intructions.push_back((intructions[intructions.size()-1]+(100-degree)) % 100);
        } else if (dir == 'R') {
            intructions.push_back((intructions[intructions.size()-1]+degree)%100);
        }
        intructions[intructions.size()-1] == 0 ? total+=1 : total=total;
    }
    cout << total;
    return 0;
}

int problem2() {
    ifstream inputFile; 
    string line;
    inputFile.open("input.txt", ios::in);

    vector<int> intructions;
    intructions.push_back(50);

    char dir;
    int degree;
    int total = 0;
    int clicks;
    int newPos;
    while(getline(inputFile,line)) {
        stringstream ss(line);
        ss >> dir;
        ss >> degree;
        if (dir == 'L') {
            total+= (((100-intructions.back())%100)+degree) / 100;
            newPos = (100 - (((100-intructions.back())+degree) % 100)) % 100;
            intructions.push_back(newPos);

        } else if (dir == 'R') {
            total+=(intructions.back()+degree)/100;
            newPos = (intructions.back()+degree)%100;
            intructions.push_back(newPos);
        }
        cout << intructions[intructions.size()-2] << "->" << intructions[intructions.size()-1] << "\n";
        cout << "total " << total << "\n";
    }
    cout << total;
    return 0;
}




int main() {
    problem1();
    cout << "\n";
    problem2();
    return 0;
}