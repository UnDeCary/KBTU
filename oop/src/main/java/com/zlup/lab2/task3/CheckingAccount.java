package com.zlup.lab2.task3;

public class CheckingAccount extends Account {

    private int transactionCount;
    private static final int FREE_TRANSACTIONS = 3;

    public CheckingAccount(int accountNumber) {
        super(accountNumber);
        transactionCount = 0;
    }

    @Override
    public void deposit(double amount) {
        super.deposit(amount);
        transactionCount++;
    }

    @Override
    public void withdraw(double amount) {
        super.withdraw(amount);
        transactionCount++;
    }

    public void deductFee() {
        if (transactionCount > FREE_TRANSACTIONS) {

            int extra = transactionCount - FREE_TRANSACTIONS;
            double fee = extra * 0.02;

            super.withdraw(fee);
        }

        transactionCount = 0;
    }

    @Override
    public String toString() {
        return "Checking " + super.toString() +
                " transactions=" + transactionCount;
    }
}
