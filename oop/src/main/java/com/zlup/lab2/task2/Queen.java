package com.zlup.lab2.task2;

public class Queen extends Piece {

    public Queen(Position a) {
        super(a);
    }

    @Override
    public boolean isLegalMove(Position b) {
        if ((b.x > 8 || b.x < 1) || (b.y > 8 || b.y < 1)) return false;

        if (a.x == b.x || a.y == b.y) return true;

        if (Math.abs(a.x - b.x) == Math.abs(a.y - b.y)) return true;
        return false;
    }
}
