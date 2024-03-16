#include <iostream>
using namespace std;

void Insert(int);
void Resize();

int* gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

void Insert(int elem) {
    if (gnCount == gnMax)
        Resize();
    gpVect[gnCount++] = elem;
}
void Resize() {
    const int delta = 10;
    gpVect = (int*)realloc(gpVect, sizeof(int) * (gnMax + delta));
    gnMax += delta;
}
void print() {
    cout << "Vector: " << endl;
    for (int* i = gpVect; i < gpVect + gnCount; i++) cout << *i << " ";
    cout << "Conteo: " << gnCount << " , Max: " << gnMax << endl;
}
int main() {
    Insert(5);
    print();
}