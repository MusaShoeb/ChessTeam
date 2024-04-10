#include "piece.h"
Pieces::Pieces(color the_Color, int number_Of_Piece, piece type_Of_Piece , int starting_ROW , int starting_column){
        pieceType = type_Of_Piece;
        colorType = the_Color;
        piece_Number = number_Of_Piece;
        current_row = starting_ROW;
        current_column = starting_column;
        has_moved = false;
    }
        
    piece Pieces :: getPiece(){
        return pieceType;
    }
    
    color Pieces :: getColor(){
        return colorType;
    }
    
    int Pieces :: getNumber(){
        return piece_Number;
    }
    
    int Pieces :: getColumn(){
        return current_column;
    }
    
    int Pieces :: getRow(){
        return current_row;
    }
    
    void Pieces :: setRow(int desired_Row){
        current_row = desired_Row;
    }
    
    void Pieces :: setColumn(int desired_Column){
        current_column = desired_Column;
    }
    
    void Pieces :: setPiece(piece desired_Piece){
        pieceType = desired_Piece;
    }
    
    void Pieces :: setColor(color desired_Color){
        colorType = desired_Color;
    }
    void Pieces :: setHas_moved(bool moved){
        has_moved = moved;
    }
    bool Pieces :: getHas_moved(){
        return has_moved;
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
    
    // I dont feel like making gets and sets so has_moved is public - H
