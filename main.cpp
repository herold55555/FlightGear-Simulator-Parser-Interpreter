#include <iostream>
#include <algorithm>
#include "Parser.h"
#include "DataReaderServer.h"
#include "Lexer.h"
#include "Solver.h"

using namespace std;

int main(int argc, char* argv[]) {
    Lexer lexer;
    Parser parser;
    parser.parse(lexer.lexer(argv[1]));
    return 0;
}