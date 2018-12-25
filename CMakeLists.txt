cmake_minimum_required(VERSION 3.13)
project(exe3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(exe3 Shunting_yard.cpp Shunting_yard.h Solver.cpp Solver.h Plus.cpp Plus.h Expression.h BinaryExpression.cpp BinaryExpression.h Num.cpp Num.h Mult.cpp Mult.h Div.cpp Div.h Minus.cpp Minus.h Pow.cpp Pow.h Expression.cpp Parser.cpp Parser.h Command.h ConnectCommand.h ConnectCommand.cpp DataClient.cpp DataClient.h DataReaderServer.cpp DataReaderServer.h DefineVarCommand.cpp DefineVarCommand.h Lexer.cpp Lexer.h LoopCommand.cpp LoopCommand.h main.cpp OpenServerCommand.cpp OpenServerCommand.h PrintCommand.cpp PrintCommand.h EnterCCommand.cpp EnterCCommand.h Sleep.cpp Sleep.h)