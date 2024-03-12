#include <iostream>
using namespace std;

enum piece {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, BLANK}; // TYPE OF PIECES
enum color {BLACK, WHITE}; // COLOR OF PIECE

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
    private:
        piece pieceType;
        color colorType;
        int piece_Number;
        int current_column;
        int current_row;
};

class gameManager{

    public:
        // constructor
        gameManager(){
            // hard code every piece of the board, that isn't blank
            Pieces board[8][8];
            est obj[] = { Test(1, 1), Test(2, 2), Test(3, 3) }
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++){
                       // board[i][j].setRow(i);
                        //board[i][j].setColumn(j);
                        //board[i][j].setPiece(BLANK);
                        //cout << board[i][j].getPiece() ;
                    }
                    cout << endl;
                }

        }
        
    private:

};