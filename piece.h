#include <iostream>
using namespace std;
#include <cmath>
#include "board.h"

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
        void moveRook(piece rookToMove, int numOfSpaces, bool direction){
            if(direction){
              rookToMove.current_column += y_spaces;  
            }
            else{
                rookToMove.current_row  += x_spaces;
            }
        }
        void moveBishop(&Piece bishopToMove, int x_spaces, int y_spaces, bool direction){
            if(abs(x_spaces) == abs(y_spaces)){
                bishopToMove.current_column += y_spaces;
                bishopToMove.current_row += x_spaces;
            }
        }
        void movePawn(&Piece pawnToMove, int x_spaces, int y_spaces, bool direction){
            if((pawnToMove.getColor() == WHITE) && (pawnToMove.getRow() == 2)){
                if(int x_spaces <= 2){
                    pawnToMove.current_column += x_spaces;
                }
            }
            if((pawnToMove.getColor() == BLACK) && (pawnToMove.getRow() == 7)){
                if(int x_spaces >= -2){
                    pawnToMove.current_column += x_spaces;
                }
            }
            /*if(check_If_Piece_at_location){
                if(pawnToMove.getColor() == WHITE)){
                    if(x_spaces == 1 && (y_spaces == 1 || y_spaces == -1)){
                        pawnToMove += x_spaces;
                        pawnToMove += y_spaces;
                    }
                    
                }
            }*/
        }
    private:
        piece pieceType;
        color colorType;
        int piece_Number;
        int current_column;
        int current_row;
};
