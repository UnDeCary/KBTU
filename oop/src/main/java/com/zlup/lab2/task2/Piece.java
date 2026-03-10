package com.zlup.lab2.task2;

public abstract class Piece {
    public Position position;
    public boolean isWhite;

    public abstract boolean isLegalMove(Position b);

}
