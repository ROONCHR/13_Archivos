#ifndef STRUCT_H
#define STRUCT_H


using namespace std;

const int MAX = 80;
struct tRegistro {
    int codigo;
    char item[MAX];
    double valor;
};

int ZIZE = sizeof(tRegistro);

#endif