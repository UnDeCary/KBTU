package com.zlup.lab2.task2;

public class Test {
    public static void main(String[] args) {
        Piece rook = new Rook(new Position(1,1));

        Position move1 = new Position(1,8);
        Position move2 = new Position(5,5);

        System.out.println(rook.isLegalMove(move1));
        System.out.println(rook.isLegalMove(move2));
    }
}
