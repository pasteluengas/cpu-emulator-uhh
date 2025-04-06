#include <iostream>
#include <string>
#include <vector>
#include <fstream>

enum OP {
    // CONTROL FLOW
    NOP,
    HLT,
    JMP,
    JZ,
    JNZ,
    JN,
    JNN,
    //DATA FLOW
    LOD,
    STO,
    //ARITHMETIC-LOGIC
    ADD,
    SUB,
    MUL,
    DIV,
    AND,
    CMP,
    NOT,
    // NOT AN OP
    X
};

int acc = 0;
int pc = 0;
std::string ram[17] = {
    /* 0 */ "NOP",
    /* 1 */ "NOP",
    /* 2 */ "NOP",
    /* 3 */ "NOP",
    /* 4 */ "NOP",
    /* 5 */ "NOP",
    /* 6 */ "NOP",
    /* 7 */ "NOP",
    /* 8 */ "NOP",
    /* 9 */ "NOP",
    /* 10 */"NOP",
    /* 11 */"NOP",
    /* 12 */"NOP",
    /* 13 */"NOP",
    /* 14 */"NOP",
    /* 15 */"NOP",
    /* 16 */"NOP"
};

std::vector<std::string> split(std::string str, std::string splitter) {
    std::vector<std::string> result;
    std::string d1 = str.substr(0, str.find(splitter));
    std::string d2 = str.substr(str.find(splitter) + 1, str.find(splitter));
    result.push_back(d1);
    result.push_back(d2);
    return result;
}

void load(std::string toLoad) {
    std::ifstream file(toLoad);
    std::string line;

    int i = 0;
    while(std::getline(file, line)) {
        ram[i] = line;
        i++;
    }
}

OP getOP(int line, int OP) {
    std::vector<std::string> splitted = split(ram[line], " ");
    //switch case splitted bablablbala {
        if (splitted[OP] == "NOP") {
            return NOP;
        } else if (splitted[OP] == "HLT")  {
            return HLT;
        } else if (splitted[OP] == "JMP")  {
            return JMP;
        } else if (splitted[OP] == "JZ")  {
            return JZ;
        } else if (splitted[OP] == "JNZ")  {
            return JNZ;
        } else if (splitted[OP] == "JN")  {
            return JN;
        } else if (splitted[OP] == "JNN")  {
            return JNN;
        } else if (splitted[OP] == "LOD")  {
            return LOD;
        } else if (splitted[OP] == "STO")  {
            return STO;
        } else if (splitted[OP] == "ADD")  {
            return ADD;
        } else if (splitted[OP] == "SUB")  {
            return SUB;
        } else if (splitted[OP] == "MUL")  {
            return MUL;
        } else if (splitted[OP] == "DIV")  {
            return DIV;
        } else if (splitted[OP] == "AND")  {
            return AND;
        } else if (splitted[OP] == "CMP")  {
            return CMP;
        } else if (splitted[OP] == "NOT")  {
            return NOT;
        } else {
            return X;
        }
    //}
}

// int getInt(int line, int num) {
//     return 0;
// }

int main() {
    load("program.bin");
    getOP(0, 0); // obtener la operacion/valor, en este caso, la operacion/valor 0 de la linea 0

    //-----------
    putchar('\n');
    return 0;
}