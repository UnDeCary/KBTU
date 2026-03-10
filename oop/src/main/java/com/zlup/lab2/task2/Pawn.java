package com.zlup.lab2.task2;

public class Pawn extends Piece {
    public boolean isFirstMove;

    public Pawn(int x, int y) {
        this.position = new Position(x, y);
    }

    @Override
    public boolean isLegalMove(Position b) {
        return true;
//        if (this.position.x == b.x) {
//            if (Math.abs(this.position.y - b.y) == 2 && isFirstMove) {
//
//            }
//        }
    }
}
