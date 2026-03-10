package com.zlup.lab2.task2;

public class Knight extends Piece {

    public Knight(Position a) {
        super(a);
    }

    @Override
    public boolean isLegalMove(Position b) {
        if ((b.x > 8 || b.x < 1) || (b.y > 8 || b.y < 1)) return false;

        return (Math.abs(a.x - b.x) == 1 && Math.abs(a.y - b.y) == 2) || (Math.abs(a.x - b.x) == 2 && Math.abs(a.y - b.y) == 1);
    }
}
