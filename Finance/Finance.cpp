#include <iostream>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

class BankAccount {

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);

private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double bal) {
        this->accountNumber = accNum;
        this->balance = bal;
        this->interestRate = 0;
        cout << "Аккаунт создан.\n";
    }

    double deposit(double money) {
        balance += money;
        cout << "Был внесен депозит на " << accountNumber << " на сумму " << money << " .\n";
        getBalance();
        return balance; }

    double withdraw(double money) {
        if ((balance - money) >= 0) { 
            balance -= money;
            cout << "Были сняты деньги с " << accountNumber << " на сумму " << money << " .\n";
            getBalance();
            return balance; }
        cout << "Недостатоно средств на аккаунте.\n";
        return -1;
    }

    double getBalance() {
        cout << "Текущий баланс: " << balance << "\n";
        return balance; }

    double getInterest() {
        double interest = balance * interestRate * (1.0/12);
        cout << "Процент на " << accountNumber << " равны " << interest << " .\n";
        return balance * interestRate * (1 / 12); }

    double setInterestRate(double interRt) {
        cout << "Была установлена новая ставка на " << accountNumber << " в размере " << interRt << " .\n";
        interestRate = interRt;
        return interestRate;
    }

    int getAccountNumber() {
        cout << "Аккаунт номер: " << accountNumber << "\n";
        return accountNumber; }
};

bool transfer(BankAccount& from, BankAccount& to, double amount)
{
    if (from.withdraw(amount) >= 0) { to.deposit(amount); return true; }
    return false;
}

int main() {
    SetConsoleCP(65001); SetConsoleOutputCP(65001);
    BankAccount account_one(123445623, 32349.73);
    BankAccount account_two(489773525, 743.0);
    transfer(account_one, account_two, 3000);
    transfer(account_one, account_two, 300000);
    account_one.deposit(32143.23);
    account_one.withdraw(321.23);
    account_one.getInterest();
    account_one.setInterestRate(2.6);
    account_one.getInterest();
    return 0;
}

