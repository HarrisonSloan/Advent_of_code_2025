#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int problem1() {
    ifstream inputFile;
    inputFile.open("input.txt", ios::in);
    string line;
    int firstDigit;
    int secondDigit;
    long sum = 0;
    while(getline(inputFile,line)) {
        firstDigit = line[0]-'0';
        secondDigit = line[1]-'0';
        for (int i = 1; i<line.size()-1; i++) {
            if (secondDigit<line[i+1]-'0') {
                secondDigit=line[i+1]-'0';
            }
            if (firstDigit<line[i]-'0') {
                firstDigit = line[i]-'0';
                secondDigit= line[i+1]-'0';
            }
        }
        sum += firstDigit*10 + secondDigit;
    }
    cout << "Sum is " << sum;
    return 0;
}


int problem2() {
    ifstream inputFile;
    inputFile.open("input.txt", ios::in);
    string line;
    int firstDigit;
    int secondDigit;
    long sum = 0;
    while(getline(inputFile,line)) {
        vector<int> digits(12,0);
        vector<int> positions(12,0);
        for (int i=0 ; i<12; i++){
            //cout << "Looking at digit " << i << "\n";
            digits[i] = line[positions[i]]-'0';
            for (int j = positions[i]; j<line.size()-11+i; j++) {
                if (digits[i]<line[j]-'0') {
                    //cout<< "Update digt " << i << "to " << 
                    digits[i]=line[j]-'0';
                    positions[i]=j;
                    //cout<< "Update digit to " << digits[i] << " at position " << j << "\n";
                }
            }
            if (i!=11) {
                positions[i+1] = positions[i]+1;
                //cout<< "start position of digit " << i+1 << " is " << positions[i+1] << "\n";
            }
            sum += digits[i]*pow(10,11-i);
        }
        //cout << " my numbers " << digits[0] << "," << digits[1] << "," << digits[2] << ","<< digits[3] << ","<< digits[4] << ","<< digits[5] << ","<< digits[6] << ","<< digits[7] << ","<< digits[8] << ","<< digits[9] << ","  << digits[10] << digits[11] << "\n";
    }
    cout << "Sum is " << sum;
    return 0;
}




int main() {
    problem1();
    problem2();
    return 0;
}