#include <iostream>
#include <vector>
#include <utility>

struct user
{
    std::string username, password;
    std::vector<std::string> borrowedBooks = {};
};

struct librarian
{
    std::string username, password;
};

struct book
{
    std::string name, author, category;
    int year;
    bool borrowStatus;
};

void start();
void signin(std::vector<librarian> &librarians, std::vector<user> &users, std::vector<book> &books);
void signup(std::vector<librarian> &librarians, std::vector<user> &users);
std::pair<bool, bool> authentication(std::string username, std::string password, std::vector<librarian> &librarians, std::vector<user> &users);
void librarianPage(std::string username, std::vector<book> &books);
void userPage(std::string username, std::vector<user> &users, std::vector<book> &books);
void seeBooks(std::vector<book> &books);

int main()
{
    std::cout << "\nCLI Library\n"
              << "===========\n"
              << "\n> Welcome to CLI Library.\n";
    start();
}

void start()
{
    std::vector<librarian> librarians;
    std::vector<user> users;
    std::vector<book> books;
    while (true)
    {
        std::cout << "\n(0) Exit    (1) Sign-In    (2) Sign-Up\n";
        std::cout << "\ninput : ";
        char val;
        std::cin >> val;
        switch (val)
        {
        case '0':
            std::cout << "\n> Thank You.\n\n";
            return;
            break;
        case '1':
            std::cout << "\n> \"Sign-In\" selected.\n";
            signin(librarians, users, books);
            break;
        case '2':
            std::cout << "\n> \"Sign-Up\" selected.\n";
            signup(librarians, users);
            break;
        default:
            std::cout << "\n> Invalid Input. Try Again.\n";
        }
    }
}

void signup(std::vector<librarian> &librarians, std::vector<user> &users)
{
    while (true)
    {
        std::cout << "\n(0) Go Back    (1) Sing-Up as a User    (2) Sign-Up as a Librarian\n";
        std::cout << "\ninput : ";
        char val;
        std::cin >> val;
        if (val == '0')
        {
            std::cout << "\n> Going Back.\n";
            return;
        }
        else if (val == '1')
        {
            std::cout << "\n> \"Sign-Up as a User\" selected.\n";
            user newUser;
            std::cout << "\nenter username : ";
            std::cin >> newUser.username;
            std::cout << "\nenter password : ";
            std::cin >> newUser.password;
            users.push_back(newUser);
            std::cout << "\n> User-Account has been successfully created. You can go back and Sign-In.\n";
        }
        else if (val == '2')
        {
            std::cout << "\n> \"Sign-Up as a Librarian\" selected.\n";
            librarian newLibrarian;
            std::cout << "\nenter username : ";
            std::cin >> newLibrarian.username;
            std::cout << "\nenter password : ";
            std::cin >> newLibrarian.password;
            librarians.push_back(newLibrarian);
            std::cout << "\n> Librarian-Account has been successfully created. You can go back and Sign-In.\n";
        }
        else
        {
            std::cout << "\n> Invalid Input.\n";
        }
    }
}

void signin(std::vector<librarian> &librarians, std::vector<user> &users, std::vector<book> &books)
{
    std::string username, password;
    std::cout << "\nEnter Username : ";
    std::cin >> username;
    std::cout << "\nEnter Password : ";
    std::cin >> password;
    std::pair<bool, bool> auth = authentication(username, password, librarians, users);
    if (auth.first)
    {
        std::cout << "\n> Login Successful.\n";
        if (auth.second)
        {
            librarianPage(username, books);
        }
        else
        {
            userPage(username, users, books);
        }
    }
    else
    {
        std::cout << "\n> Invalid Login. Try Again.";
    }
}

std::pair<bool, bool> authentication(std::string username, std::string password, std::vector<librarian> &librarians, std::vector<user> &users)
{
    std::pair<bool, bool> auth;
    auth.first = false;
    auth.first = false;
    for (int i = 0; i < users.size(); i++)
    {
        if ((username == users[i].username) && (password == users[i].password))
        {
            auth.first = true;
            auth.second = false;
            return auth;
        }
    }
    for (int i = 0; i < librarians.size(); i++)
    {
        if ((username == librarians[i].username) && (password == librarians[i].password))
        {
            auth.first = true;
            auth.second = true;
            return auth;
        }
    }
    return auth;
}

void librarianPage(std::string username, std::vector<book> &books)
{
    std::cout << "\n> Logged in as " << username << ".\n";
    while (true)
    {
        std::cout << "\n(0) Sign-Out    (1) Add Books    (2) Remove Books    (3) See Books\n";
        std::cout << "\ninput : ";
        char val;
        std::cin >> val;
        switch (val)
        {
        case '0':
        {
            std::cout << "\n> Signed-Out successfully. Going Back.\n";
            return;
            break;
        }
        case '1':
        {
            std::cout << "\nEnter book details - \n";
            book newBook;
            std::cout << "\nEnter Name : ";
            std::cin >> newBook.name;
            std::cout << "Enter Author : ";
            std::cin >> newBook.author;
            std::cout << "Enter Year of Publication : ";
            std::cin >> newBook.year;
            std::cout << "Enter category : ";
            std::cin >> newBook.category;
            newBook.borrowStatus = 0;
            books.push_back(newBook);
            std::cout << "\n> \"" << newBook.name << "\" has been added to the Library's collection.\n";
            break;
        }
        case '2':
        {
            std::cout << "\nEnter book name : ";
            std::string bookName;
            std::cin >> bookName;
            for (int i = 0; i < books.size(); i++)
            {
                if (bookName == books[i].name)
                {
                    auto iter = books.begin() + i;
                    books.erase(iter);
                }
            }
            std::cout << "\n> \"" << bookName << "\" has been removed from the Library's collection.\n";
            break;
        }
        case '3':
        {
            seeBooks(books);
            break;
        }
        default:
        {
            std::cout << "\n> Invalid Input. Try Again.\n";
            break;
        }
        }
    }
}

void userPage(std::string username, std::vector<user> &users, std::vector<book> &books)
{
    std::cout << "\n> Logged in as " << username << ".\n";
    while (true)
    {
        int userId = 0;
        for (int i = 0; i < users.size(); i++)
        {
            if (username == users[i].username)
            {
                userId = i;
            }
        }
        std::cout << "\n(0) Sign-Out    (1) See Books    (2) Checkout a Book    (3) Borrow a Book    (4) Return a Book\n";
        std::cout << "\ninput : ";
        char val;
        std::cin >> val;
        switch (val)
        {
        case '0':
        {
            std::cout << "\n> Signed-Out successfully. Going Back.\n";
            return;
            break;
        }
        case '1':
        {
            seeBooks(books);
            break;
        }
        case '2':
        {
            std::cout << "\nEnter book name : ";
            std::string bookName;
            std::cin >> bookName;
            bool bookExists = 0;
            for (int i = 0; i < books.size(); i++)
            {
                if (bookName == books[i].name)
                {
                    bookExists = 1;
                    std::cout << "\n> Requested Book's details are as follows :\n";
                    std::cout << "\nBook Name : " << books[i].name;
                    std::cout << "\nAuthor : " << books[i].author;
                    std::cout << "\nYear of Publication : " << books[i].year;
                    std::cout << "\nCategory : " << books[i].category << "\n";
                }
            }
            if (!bookExists)
            {
                std::cout << "\n> The book you are looking for isn't present in the Library.\n";
            }
            break;
        }
        case '3':
        {
            std::cout << "\n> NOTE : You are only allowed to borrow 2 books at a time.\n";
            if (users[userId].borrowedBooks.size() < 2)
            {
                std::cout << "\nEnter Book Name for borrowing : ";
                std::string bookName;
                std::cin >> bookName;
                for (int i = 0; i < books.size(); i++)
                {
                    if (bookName == books[i].name)
                    {
                        books[i].borrowStatus = 1;
                        users[userId].borrowedBooks.push_back(books[i].name);
                    }
                }
                std::cout << "\n> You have borrowed \"" << bookName << "\" successfully.\n";
            }
            else
            {
                std::cout << "\n> You have already borrowed 2 books. You can't borrow more books.\n";
            }
            break;
        }
        case '4':
        {
            std::cout << "\nBorrowed Books : ";
            for (int i = 0; i < users[userId].borrowedBooks.size(); i++)
            {
                std::cout << users[userId].borrowedBooks[i] << "; ";
            }
            std::cout << "\n\nEnter bookname for returning : ";
            std::string bookName;
            std::cin >> bookName;
            for (int i = 0; i < users[userId].borrowedBooks.size(); i++)
            {
                if (bookName == users[userId].borrowedBooks[i])
                {
                    auto iter = users[userId].borrowedBooks.begin() + i;
                    users[userId].borrowedBooks.erase(iter);
                }
            }
            for (int i = 0; i < books.size(); i++)
            {
                if (bookName == books[i].name)
                {
                    books[i].borrowStatus = 0;
                }
            }
            std::cout << "\n> You have returned \"" << bookName << "\" successfully.\n";
            return;
        }
        default:
        {
            std::cout << "\n> Invalid Input. Try Again.\n";
            break;
        }
        }
    }
}

void seeBooks(std::vector<book> &books)
{
    std::cout << "\nBooks : \n";
    std::cout << "\n| Book | Author | Year | Category | Borrow Status |\n";
    for (int i = 0; i < books.size(); i++)
    {
        std::cout << "| " << books[i].name << " | " << books[i].author << " | " << books[i].year << " | " << books[i].category << " | " << books[i].borrowStatus << " |\n";
    }
}