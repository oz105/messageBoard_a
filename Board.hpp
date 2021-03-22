#include <string>
#include "Direction.hpp"
#include <map>
#include<iostream>
#include<stdexcept>
#include <limits.h>

using namespace std;

namespace ariel {
    class Board {
    private :
        //define object holds the raw and the col on the borad
        typedef pair<uint , uint > row_col ;
        map <row_col , char> msg_board;
        uint max_row;
        uint min_row;
        uint max_col;
        uint min_col;
    public:
        Board(){
            max_row = max_col = 0;
            min_row = min_col = UINT_MAX;
        }
        ~Board(){ }

        void post(uint row, uint col, Direction direction, std::string msg);
        
        string read(uint row, uint col, Direction direction, uint len);

        void show();
    };
}