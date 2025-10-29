#include "chess_game.h"

ChessGame::ChessGame() {
    // clear board
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            board[row][col] = static_cast<PieceType>(-1); // have to use this to represent empty square, random pieces were showing
        }
    }
    // pawns
    for (int c = 0; c < 8; ++c) {
        board[1][c] = BLACK_PAWN; // black pawns (top)
        board[6][c] = WHITE_PAWN; // white pawns (bottom)
    }

    // black back rank (top)
    board[0][0] = BLACK_ROOK;   board[0][7] = BLACK_ROOK;
    board[0][1] = BLACK_KNIGHT; board[0][6] = BLACK_KNIGHT;
    board[0][2] = BLACK_BISHOP; board[0][5] = BLACK_BISHOP;
    board[0][3] = BLACK_QUEEN;  board[0][4] = BLACK_KING;

    // white back rank (bottom)
    board[7][0] = WHITE_ROOK;   board[7][7] = WHITE_ROOK;
    board[7][1] = WHITE_KNIGHT; board[7][6] = WHITE_KNIGHT;
    board[7][2] = WHITE_BISHOP; board[7][5] = WHITE_BISHOP;
    board[7][3] = WHITE_QUEEN;  board[7][4] = WHITE_KING;
}

ChessGame::~ChessGame() {
    // destructor
}

PieceType ChessGame::getPieceAt(int row, int col) {
    return board[row][col];
}

bool ChessGame::makeMove(int srcRow, int srcCol, int destRow, int destCol) {
    PieceType srcPiece = board[srcRow][srcCol];
    PieceType destPiece = board[destRow][destCol];

    if (srcPiece == static_cast<PieceType>(-1)) {
        return false;
    }

    if (srcRow == destRow && srcCol == destCol) {
        return false;
    }

    board[destRow][destCol] = board[srcRow][srcCol];
    board[srcRow][srcCol] = static_cast<PieceType>(-1); // empty square
    whiteTurn = !whiteTurn;
    return true;
}

GameStatus ChessGame::getGameStatus() const {
    return status;
}

bool ChessGame::isWhiteTurn() const {
    return whiteTurn;
}

