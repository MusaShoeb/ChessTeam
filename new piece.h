#include <iostream>
#include <cmath>
using namespace std;


enum piece {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, BLANK}; // TYPE OF PIECES
enum color {BLACK, WHITE, NONE}; // COLOR OF PIECE 

class Pieces{
    private:
        piece pieceType;
        color colorType;
        int piece_Number;
        int current_column;
        int current_row;
        bool has_moved;
    public:      
        Pieces::Pieces(color the_Color, int number_Of_Piece, piece type_Of_Piece , int starting_ROW , int starting_column);        
        piece getPiece();        
        color getColor();       
        int getNumber();       
        int getColumn();       
        int getRow();        
        void setRow(int desired_Row);       
        void setColumn(int desired_Column);       
        void setPiece(piece desired_Piece);        
        void setColor(color desired_Color);
        void setHas_moved(bool moved);
        bool getHas_moved();
};
