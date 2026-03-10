package com.zlup.lab2.task2;

public class Rook extends Piece {

    public Rook(Position a) {
        super(a);
    }

    @Override
    public boolean isLegalMove(Position b) {
        if ((b.x > 8 || b.x < 1) || (b.y > 8 || b.y < 1)) return false;

        return a.x == b.x || a.y == b.y;
    }
}
