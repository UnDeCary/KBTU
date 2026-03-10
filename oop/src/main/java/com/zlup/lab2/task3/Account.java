package com.zlup.lab2.task3;

public class Account {
    private double balance;
    private int accountNumber;

    public Account(int accountNumber) {
        this.balance = 0.0;
        this.accountNumber = accountNumber;
    }

    public void deposit(double amount) {
        if (amount < 0) return;
        this.balance += amount;
    }

    public void withdraw(double amount) {
        if (amount < 0 || this.balance < amount) return;
        this.balance -= amount;
    }

    public double getBalance() {
        return this.balance;
    }

    public int getAccountNumber() {
        return this.accountNumber;
    }

    public void transfer(double amount, Account other) {
        if (amount > 0 && balance >= amount) {
            withdraw(amount);
            other.deposit(amount);
        }
    }

    @Override
    public String toString() {
        return "Account [balance=" + balance + ", accountNumber=" + accountNumber + "]";
    }

    public final void print() {
        System.out.println(this.toString());
    }
}
