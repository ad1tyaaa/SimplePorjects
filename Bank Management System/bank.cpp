#include <iostream>
#include <vector>

// BANK ACCOUNT IS A STRUCT
struct bankAccount
{
    // std::string accountNo;
    std::string name;
    std::string password;
    int balance;
};

// FUNCTION DECLARATIONS
void homePage();
void createAccount(std::vector<bankAccount> &bankDB);
void login(std::vector<bankAccount> &bankDB);
void bankDebug(std::vector<bankAccount> &bankDB);

// MAIN
int main()
{
    // TITLE
    std::cout << "\nBANK OF SCAMMER" << std::endl;
    std::cout << "================" << std::endl;
    // MAINPAGE
    homePage();
}

// FUNCTION DEFINITIONS

// MAINPAGE
void homePage()
{
    // creating a vector of Bank Accounts for holding details of multiple Bank Accounts.
    std::vector<bankAccount> bankDB;
    while (true)
    {
        char val;
        std::cout << "\n(0) EXIT    (1) LOGIN TO YOUR BANK ACCOUNT    (2) CREATE A NEW BANK ACCOUNT" << std::endl;
        std::cout << "\ninput : ";
        std::cin >> val;
        if (val == '0')
        {
            std::cout << "\n> Bye." << std::endl
                      << std::endl;
            return;
        }
        else if (val == '1')
        {
            // LOGIN PAGE
            std::cout << "\n> \"LOGIN TO YOUR BANK ACCOUNT\" Selected." << std::endl;
            login(bankDB);
        }
        else if (val == '2')
        {
            // CREATE ACCOUNT PAGE
            std::cout << "\n> \"CREATE A NEW BANK ACCOUNT\" Selected." << std::endl;
            createAccount(bankDB);
        }
        // DEBUGGING
        else if (val == '3')
        {
            bankDebug(bankDB);
        }
        else
        {
            std::cout << "Invalid Input. Try Again." << std::endl;
        }
    }
}

// ACCOUNT CREATION PAGE
void createAccount(std::vector<bankAccount> &bankDB)
{
    bankAccount newAcct;
    std::cout << "\nEnter your details to create a new Bank Account." << std::endl;
    std::cout << "\nEnter Account Holder's Name : ";
    std::cin >> newAcct.name;
    std::cout << "\nCreate a strong password : ";
    std::cin >> newAcct.password;
    newAcct.balance = 0;
    // adding the bank account to the accounts database.
    bankDB.push_back(newAcct);
    std::cout << "\nCongratulations! Your new bank account has been created successfully. Welcome to the Bank of Scammers." << std::endl;
    std::cout << "Your current account balance is $" << newAcct.balance << " only." << std::endl;
    std::cout << "\n> Going back to the Main Page." << std::endl;
}

// ACCOUNT LOGIN
void login(std::vector<bankAccount> &bankDB)
{
    int acctNo = -1; // this is index of bankDB
    std::cout << "\nEnter your details to LogIn." << std::endl;
    while (acctNo == -1)
    {
        std::string acctName;
        std::cout << "\nEnter Account Holder's Name : ";
        std::cin >> acctName;
        if (acctName == "-1")
        {
            return;
        }
        for (int i = 0; i < bankDB.size(); i++)
        {
            if (bankDB[i].name == acctName)
            {
                acctNo = i;
            }
        }
        if (acctNo == -1)
        {
            std::cout << "\n> This account doesn't exist. Try Again. Or, Press -1 to return to Main Page." << std::endl;
        }
    }
    std::string acctPassword = "";
    while (acctPassword != bankDB[acctNo].password)
    {
        std::cout << "\nEnter your Password : ";
        std::cin >> acctPassword;
        if (acctPassword == "-1")
        {
            return;
        }
        if (acctPassword != bankDB[acctNo].password)
        {
            std::cout << "\n> Wrong Password. Try Again. Or, Press -1 to return to Main Page." << std::endl;
        }
    }
    std::cout << "\n> Hello " << bankDB[acctNo].name << "." << std::endl;
    std::cout << "> You have successfully Logged Into you Bank Account." << std::endl;
    while (true)
    {
        char val;
        std::cout << "\n(0) LOGOUT    (1) CHECK BALANCE    (2) DEPOSIT MONEY    (3) WITHDRAW MONEY" << std::endl;
        std::cout << "\ninput : ";
        std::cin >> val;
        if (val == '0')
        {
            std::cout << "\n> \"LOGOUT\" selected." << std::endl;
            std::cout << "> You have successfully logged-out. Going back to the Main Page." << std::endl;
            return;
        }
        else if (val == '1')
        {
            std::cout << "\n> \"CHECK BALANCE\" selected." << std::endl;
            std::cout << "\n> Your Current Account Balance = $ " << bankDB[acctNo].balance << " only." << std::endl;
        }
        else if (val == '2')
        {
            std::cout << "\n> \"DEPOSIT MONEY\" selected." << std::endl;
            std::cout << "\n> Enter Amount to deposit : ";
            int depositAmount;
            std::cin >> depositAmount;
            bankDB[acctNo].balance += depositAmount;
            std::cout << "\n> Succesfully deposited $ " << depositAmount << " into your Bank Account." << std::endl;
        }
        else if (val == '3')
        {
            std::cout << "\n> \"WITHDRAW MONEY\" selected." << std::endl;
            int withdrawAmount;
            std::cout << "\n> Enter Amount to withdraw : ";
            std::cin >> withdrawAmount;
            if (bankDB[acctNo].balance - withdrawAmount < 0)
            {
                std::cout << "\n> Cannot complete this transaction. You don't have enough balance currently in your account." << std::endl;
                std::cout << "> Going Back." << std::endl;
            }
            else
            {
                bankDB[acctNo].balance -= withdrawAmount;
                std::cout << "\n> Transaction has successfully completed. You have withdrawn $ " << withdrawAmount << " from your account." << std::endl;
            }
        }
        else
        {
            std::cout << "\n> Invalid Input. Try Again." << std::endl;
        }
    }
}

// DEBUG
void bankDebug(std::vector<bankAccount> &bankDB)
{
    // this lists the contents of the BankDB Vector.
    std::cout << "\nBankDB : " << std::endl;
    for (int i = 0; i < bankDB.size(); i++)
    {
        std::cout << "bankDB.[" << i << "] = " << bankDB[i].name << " | " << bankDB[i].password << std::endl;
    }
}