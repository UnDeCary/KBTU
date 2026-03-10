package com.zlup.lab2.task3;

import java.util.Vector;

public class Bank {

    private Vector<Account> accounts;

    public Bank() {
        accounts = new Vector<>();
    }

    public void openAccount(Account account) {
        accounts.add(account);
    }

    public void closeAccount(int accountNumber) {
        accounts.removeIf(account ->  account.getAccountNumber() == accountNumber);
    }

    public void update() {

        for (Account account : accounts) {

            if (account instanceof SavingsAccount) {
                ((SavingsAccount) account).addInterest();
            }
            else if (account instanceof CheckingAccount) {
                ((CheckingAccount) account).deductFee();
            }
        }
    }

    public void printAccounts() {
        for (Account account : accounts) {
            account.print();
        }
    }
}
