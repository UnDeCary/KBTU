package com.zlup.lab2.task3;

public class SavingsAccount extends Account {

    private double interestRate;

    public SavingsAccount(int accountNumber, double rate) {
        super(accountNumber);
        this.interestRate = rate;
    }

    public void addInterest() {
        double interest = getBalance() * this.interestRate / 100;
        deposit(interest);
    }

    @Override
    public String toString() {
        return "Savings " + super.toString() + " rate=" + interestRate + "%";
    }
}
