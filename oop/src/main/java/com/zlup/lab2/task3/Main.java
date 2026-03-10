package com.zlup.lab2.task3;

public class Main {

    public static void main(String[] args) {

        Bank bank = new Bank();

        SavingsAccount s1 = new SavingsAccount(1, 5);
        CheckingAccount c1 = new CheckingAccount(2);
        CheckingAccount c2 = new CheckingAccount(3);

        bank.openAccount(s1);
        bank.openAccount(c1);
        bank.openAccount(c2);

        s1.deposit(1000);

        c1.deposit(500);
        c1.withdraw(100);
        c1.withdraw(50);
        c1.withdraw(50);

        bank.update();

        bank.printAccounts();
    }

}
