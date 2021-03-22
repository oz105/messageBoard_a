#include<stdexcept>
#include "Board.hpp"
#include<iostream>
#include<map>
using namespace std;

namespace ariel {

    //this will post on the board the msg we put in int the location we will give (row,col) and decide the direction of the msg Vertical or Horizontal.
    void Board::post(uint row, uint col, Direction direc, string msg) {
        //for loop on the string to put every char on his place
        for (size_t i = 0; i < msg.length(); i++)
        {
            this->max_row = max(this->max_row,row);
            this->max_col = max(this->max_col,col);
            this->min_row = min(this->min_row,row);    
            this->min_col = min(this->min_col,col);
            msg_board[make_pair(row,col)] = msg.at(i); // put the char in the place according to row and col
            if(direc == Direction::Horizontal) { // if the direction is Horizontal than move col +1 for next char
                col ++ ;
            }
            else{
                row ++ ; //if the direction is Vertical than move row +1
            }
        }
    }

    string Board::read(uint row,uint col, Direction direc, uint len) {
        string msg;
        char c ='_';
    
        //for loop on the len we want to read
        for (size_t i = 0; i < len; i++)
        {
            if(msg_board.count((make_pair(row,col))) > 0 ){ // check if the key is exists 
                c = msg_board[make_pair(row,col)]; // pull the char in it 
            }
            else { // give the defult the key not exists
                c = '_' ;
            }
            // add the char to the string we will return 
            msg += c ;

            if(direc == Direction::Horizontal) { // if the direction is Horizontal than move col +1 for next char
                col ++ ;
            }
            else{
                row ++ ; //if the direction is Vertical than move row +1
            } 
        }
        return msg;
    }
    void Board::show() {
        for (uint i = (this->min_row)-1; i <=(this->max_row); i++){
            cout << i << ": " ;
            for (uint j = (this->min_col); j <= (this->max_col+1); j++){
                if(this->msg_board.count((make_pair(i,j))) > 0 ){ // check if the key is exists 
                cout << msg_board[make_pair(i,j)];
            }
                else { // give the defult the key not exists
                    cout << '_' ;
                }
            }
            cout << "\n";
        }
    }
}