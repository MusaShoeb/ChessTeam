#include <iostream>
#include <cmath>
using namespace std;


enum piece {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, BLANK}; // TYPE OF PIECES
enum color {BLACK, WHITE, NONE}; // COLOR OF PIECE

class Pieces{
    
    public:

        Pieces(color the_Color, int number_Of_Piece, piece type_Of_Piece , int starting_ROW , int starting_column){
            pieceType = type_Of_Piece;
            colorType = the_Color;
            piece_Number = number_Of_Piece;
            current_row = starting_ROW;
            current_column = starting_column;
            has_moved = false;
        }
        
        piece getPiece(){
            return pieceType;
        }
        
        color getColor(){
            return colorType;
        }
        
        int getNumber(){
            return piece_Number;
        }
        
        int getColumn(){
            return current_column;
        }
        
        int getRow(){
            return current_row;
        }
        
        void setRow(int desired_Row){
            current_row = desired_Row;
        }
        
        void setColumn(int desired_Column){
            current_column = desired_Column;
        }
        
        void setPiece(piece desired_Piece){
            pieceType = desired_Piece;
        }
        
        void setColor(color desired_Color){
            colorType = desired_Color;
        }

        /*Copy constructor
        Pieces(Pieces& sample){
            pieceType = sample.pieceType;
            colorType = sample.colorType;
            piece_Number = sample.piece_Number;
            current_column = sample.current_column;
            current_row = sample.current_column;
        }
        */
       
    bool has_moved;
    private:
        piece pieceType;
        color colorType;
        int piece_Number;
        int current_column;
        int current_row;
        
};
