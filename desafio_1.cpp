#include <iostream>

using namespace std;

class Conta
{
    protected:
        string accountType;
        double balance;

    public:
        Conta(const string &type, double initialBalance)
            : accountType(type), balance(initialBalance) {}
        
        string getAccountType() const { return accountType; }
        double getBalance() const { return balance; }

        virtual bool withdraw(double value)
        {
            if (value <= balance)
            {
                balance -= value;
                return true;
            }

            return false;
        }
};

class ContaCorrente : public Conta
{
    public:
        ContaCorrente(double initialBalance) : Conta("Corrente", initialBalance) {}
};

class ContaPoupanca : public Conta
{
    public:
        ContaPoupanca(double initialBalance) : Conta("Poupanca", initialBalance) {}
};

bool executarComLog(Conta &account, double value)
{
    cout << "Tentativa de saque de R$" << value << " na conta " << account.getAccountType() << "\n";

    if (account.withdraw(value))
    {
        cout << "Saque realizado com sucesso na conta " << account.getAccountType() << "\n\n";

        return true;
    } else {
        cout << "ALERTA: Saldo insuficiente na conta " << account.getAccountType() << "!\n\n";

        return false;
    }
}

int main()
{
    ContaCorrente contacorrente(500);
    ContaPoupanca contapoupanca(300);

    executarComLog(contacorrente, 600);
    executarComLog(contapoupanca, 300);

    return 0;
}