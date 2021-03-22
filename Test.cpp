#include "doctest.h"
#include "Board.hpp"
#include <string>
#include<stdexcept>
using namespace ariel;
using namespace std;

ariel:: Board board ;
const int big_board = 1000000 ;

TEST_CASE("empty board"){

    CHECK(board.read(0,0,Direction::Horizontal,3) == "___");
    CHECK(board.read(0,0,Direction::Horizontal,4) == "____");
    CHECK(board.read(1,0,Direction::Horizontal,3) == "___");
    CHECK(board.read(1,0,Direction::Horizontal,4) == "____");
}

TEST_CASE("board post and then check read"){
    board.post(10 , 20 , Direction::Horizontal,"Hey there");
    CHECK(board.read(10,20,Direction::Horizontal,9) =="Hey there");
    CHECK(board.read(10,18,Direction::Horizontal,13) =="__Hey there__");
}

TEST_CASE("run over Horizontal "){
    board.post(10,20 , Direction::Horizontal,"Hii there"); // post "Hii" instead of "Hey"
    CHECK(board.read(10,20,Direction::Horizontal,9) =="Hii there"); // check run over
    CHECK(board.read(10,18,Direction::Horizontal,13) =="__Hii there__"); // chcek run over on the limits
    board.post(10, 30,Direction::Horizontal,"my name is oz");
    CHECK(board.read(10,18,Direction::Horizontal,25) =="__Hii there_my name is oz");

}
TEST_CASE("test Vertical"){
    CHECK(board.read(10,19,Direction::Vertical,5) =="_____");
    CHECK(board.read(10,20,Direction::Vertical,5) =="H____");
    CHECK(board.read(10,21,Direction::Vertical,5) =="i____");
    CHECK(board.read(10,22,Direction::Vertical,5) =="i____");
    CHECK(board.read(10,23,Direction::Vertical,5) ==" ____");
    CHECK(board.read(10,24,Direction::Vertical,5) =="t____");
    CHECK(board.read(10,25,Direction::Vertical,5) =="h____");
    CHECK(board.read(10,26,Direction::Vertical,5) =="e____");
    CHECK(board.read(10,27,Direction::Vertical,5) =="r____");
    CHECK(board.read(10,28,Direction::Vertical,5) =="e____");
    
}

TEST_CASE("run over Vertical"){
    board.post(10,20,Direction::Vertical,"Hey");
    CHECK(board.read(10,20,Direction::Vertical,3) =="Hey");
    board.post(10,20,Direction::Vertical,"bye");
    CHECK(board.read(10,20,Direction::Vertical,3) =="bye");
    board.post(10,20,Direction::Vertical,"die");
    CHECK(board.read(10,20,Direction::Vertical,3) =="die");
}

TEST_CASE("random cases"){
    srand(time(0));
    int count = 10 ;
    for (size_t i = 0; i < 10 ; i++)
    {
        uint rand_row = rand() % 10000 ;
        uint rand_col = rand() % 10000 ;
        board.post(rand_row,rand_col,Direction::Horizontal,"rand");
        CHECK(board.read(rand_row,rand_col,Direction::Horizontal,4) =="rand");
    }
}
TEST_CASE("big board case"){
     CHECK(board.read(big_board,big_board,Direction::Horizontal,3) == "___");
     board.post(big_board,big_board,Direction::Horizontal,"million");
     CHECK(board.read(big_board,big_board,Direction::Horizontal,7) == "million");

    CHECK(board.read(3*big_board,3*big_board,Direction::Horizontal,3) == "___");
    board.post(3*big_board,3*big_board,Direction::Horizontal,"big");
    CHECK(board.read(3*big_board,3*big_board,Direction::Horizontal,3) == "big");
}
