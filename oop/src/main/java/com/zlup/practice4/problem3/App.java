package com.zlup.practice4.problem3;

public class App {

    public static void getStatistics(Game g) {
        g.a();
        g.b();
        g.c();

        if (g instanceof IGame) {
            ((IGame) g).d();
        }
    }

    public static void main(String[] args) {
        Game game1 = new LogicGame();
        Game game2 = new MemoryGame();

        getStatistics(game1);
        getStatistics(game2);
    }
}
