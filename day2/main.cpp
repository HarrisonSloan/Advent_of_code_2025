#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


long sumRange(long start, long end) {
    // resolve start range
    int startDigits = 0;
    long startNumber = start;
    while (startNumber!=0) {
        startNumber = startNumber / 10;
        startDigits++;
    }
    // Find base start range
    // if even
    startNumber = start;
    long baseStart;
    if (startDigits%2==0) {
        baseStart = startNumber / pow(10, startDigits/2);
        //cout << "lowest possible " << long(baseStart*pow(10, startDigits/2) + baseStart) << "\n";
        baseStart*pow(10, startDigits/2) + baseStart < start ? baseStart++ : baseStart;
    // if odd
    } else {
        baseStart = pow(10, (startDigits/2));
        startDigits++;
    }


    // resolve end range
    int endDigits = 0;
    long endNumber = end;
    while (endNumber!=0) {
        endNumber = endNumber / 10;
        endDigits++;
    }
    // Find base start range
    // if even
    endNumber = end;
    long baseEnd;
    if (endDigits%2==0) {
        baseEnd = endNumber / pow(10, endDigits/2);
        (baseEnd*pow(10, endDigits/2) + baseEnd) > end ? baseEnd-- : baseEnd;
    // if odd
    } else {
        baseEnd = pow(10, (endDigits/2)) - 1;
    }

    //cout << "start base " << baseStart << " end " << baseEnd << " multiplier " << long(pow(10,startDigits/2)) << "\n";

    long sum = (((baseEnd*(baseEnd+1))/2) - ((baseStart*(baseStart-1))/2)) * (pow(10,startDigits/2)+1);
    return baseStart<=baseEnd ? sum: 0;  
}

int problem1() {
    long total = 0;
    ifstream inputFile;
    inputFile.open("input.txt", ios::in);
    long long start,end;
    char sep;
    long addition;
    while (inputFile>>start) {
        inputFile >> sep;
        inputFile >> end;
        addition=sumRange(start,end);
        cout << " added " << addition << "\n";
        total+=addition; 
        inputFile>>sep;
    }

    cout << total;

    return 0;
}


int main() {
    long answer = sumRange(7967153617,7967231799);
    cout << "Sum is " << answer << "\n";
    problem1();
    return 0;
}