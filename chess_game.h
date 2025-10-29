#pragma once

// create enum for piece types and colors
// enum for chess pieces:
enum PieceType {
    WHITE_PAWN,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK,
    WHITE_QUEEN,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_ROOK,
    BLACK_QUEEN,
    BLACK_KING
};

enum class GameStatus {
    ONGOING,
    WHITE_WIN,
    BLACK_WIN,
    DRAW
};

class ChessGame {
public:
    ChessGame();
    ~ChessGame();

    PieceType getPieceAt(int row, int col);
    // make a move from (srcRow, srcCol) to (destRow, destCol)
    bool makeMove(int srcRow, int srcCol, int destRow, int destCol);

    //query the state of the game
    GameStatus getGameStatus() const;

    bool isWhiteTurn() const;
private:
    // for the internal representation of the chessboard
    PieceType board[8][8];
    bool whiteTurn;
    GameStatus status;
};