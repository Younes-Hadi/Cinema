/// LIBRARIES:...
#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
#include <string>
#include <cctype>

/// NAMESPACE:...
using namespace std;

/// FUNCTIONS:...
void navbarPack();
void handleAction();
void toLowerCase(string &);
void invalid();
void unknownError(string);
bool navigationText(string);
void moveCursor(int, int);
void reserve();
void branchesDetails();
void moviesDetails();
void contactUs();
void mainPanel();
void loginInput();

/// VARIABLES:...
string action;

/// CLASSES:...
class Movie
{
public:
    Movie(string title="") : title(title) {}
    string getTitle()
    {
        return title;
    }

private:
    string title;
};
class Seat
{
public:
    Seat(int row = 0, int number = 0, bool reserved = false) : row(row), number(number), reserved(reserved) {}
    bool isReserved()
    {
        return reserved;
    }
    void reserve()
    {
        reserved = true;
    }

private:
    int row, number;
    bool reserved;
};
class ShowTime
{
private:
    vector<string> time = {"08:00-10:00", "10:00-12:00", "12:00-14:00", "14:00-16:00", "16:00-18:00", "20:00-22:00"};
    Movie movie;
    vector<Seat> seat;
};
class Hall
{
protected:
    vector<ShowTime> showTimes;

public:
    virtual int getPriceMultiplier() = 0;
};
class VIP_Hall : public Hall
{
public:
    int getPriceMultiplier() override
    {
        return 2;
    }
};
class ordinary_Hall : public Hall
{
public:
    int getPriceMultiplier() override
    {
        return 1;
    }
};
class Branch
{
public:
    Branch(string title = "") : title(title) {}
    string getTitle()
    {
        return title;
    }

private:
    vector<Hall*> halls;
    string title;
};
class Cinema
{
public:
    void displayBranches()
    {
        cout << "Available branches:" << endl;
        int i = 1;
        for (auto b : branches)
        {
            cout << "\t" << i << ". " << b.getTitle() << endl;
            i++;
        }
    }
    void addBranch()
    {
        action = "";
        cout << endl
             << "Please enter a name for your new branch..." << endl;
        string newBranch = "";
        getline(cin, newBranch);
        toLowerCase(newBranch);
        navigationText(newBranch);
        branches.push_back(newBranch);
        system("cls");
        moveCursor(42, 12);
        cout << "New branch added to the list, successfully!" << endl;
        Sleep(4000);
        mainPanel();
    }
    void rmBranch()
    {
        cout << endl
             << "Please enter the number of the branch that you want to remove..." << endl;
        int remove;
        cin >> remove;
        branches.erase(branches.begin() + (remove - 1));
        system("cls");
        moveCursor(42, 12);
        cout << "The selected branch removed successfully!" << endl;
        Sleep(4000);
        mainPanel();
    }
    void displayMovies()
    {
        cout << "Available movies:" << endl;
        int i = 1;
        for (auto m : movies)
        {
            cout << "\t" << i << ". " << m.getTitle() << endl;
            i++;
        }
    }
    void addMovie()
    {
        action = "";
        cout << endl
             << "Please enter a name for your new movie..." << endl;
        string newMovie = "";
        getline(cin, newMovie);
        toLowerCase(newMovie);
        navigationText(newMovie);
        movies.push_back(newMovie);
        system("cls");
        moveCursor(42, 12);
        cout << "New movie added to the list, successfully!" << endl;
        Sleep(4000);
        mainPanel();
    }
    void rmMovie()
    {
        cout << endl
             << "Please enter the number of the movie that you want to remove..." << endl;
        int remove;
        cin >> remove;
        movies.erase(movies.begin() + (remove - 1));
        system("cls");
        moveCursor(42, 12);
        cout << "The selected movie removed successfully!" << endl;
        Sleep(4000);
        mainPanel();
    }

private:
    vector<Movie> movies{
        {"Backrooms"},
        {"The death of the Robin Hood"},
        {"Toy story"},
        {"Obsession"},
        {"Avengers doomsday"},
        {"Spider-Man brand new day"},
        {"The furious"}};
    vector<Branch> branches{
        {"Regal Times Square"},
        {"AMC Lincoln Square"},
        {"AMC Empire 25"},
        {"The Paris Theater"}};
};
class Reserving
{
public:
    void reserving()
    {
    }

private:
    Movie movie;
    vector<Seat> seats;
    ShowTime times;
    string costumerName;
    Cinema cinema;
};
class Ticket
{
private:
    Movie movie;
    vector<Seat> seat;
    ShowTime time;
    Branch branch;
    int price;
    string clientsName;
    string clientsLastName;
};
class User
{
protected:
    string username, password;

public:
    virtual ~User() {};
    virtual bool checkIsAdmin() = 0;
};
class Admin : public User
{
public:
    bool checkIsAdmin() override
    {
        isAdmin = true;
        return isAdmin;
    }

private:
    bool isAdmin;
};
class Customer : public User
{
public:
    bool checkIsAdmin() override
    {
        isAdmin = false;
        return isAdmin;
    }

private:
    bool isAdmin;
};

/// VARIABLES:...
User *currentUser = nullptr;
Cinema appCinema;

User *loginPanel();

int main()
{
    currentUser = loginPanel();
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainPanel()
{
    navbarPack();
    moveCursor(42, 7);
    cout << "Welcome" << endl;
    moveCursor(1, 15);
    cout << "Please enter an action to do..." << endl;
    handleAction();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void handleAction()
{
    getline(cin, action);
    toLowerCase(action);
    navigationText(action);
    if (navigationText(action))
        return;
    else if (action == "1" || action == "home")
        mainPanel();
    else if (((action == "2" || action == "reserve") && !(currentUser->checkIsAdmin())))
        reserve();
    else if (((action == "3" || action == "contact us") && !(currentUser->checkIsAdmin())) || ((currentUser->checkIsAdmin()) && (action == "4" || action == "contact us")))
        contactUs();
    else if (action == "contact us" || action == "4")
        contactUs();
    else if ((action == "2" || action == "movies") && (currentUser->checkIsAdmin()))
        moviesDetails();
    else if ((action == "3" || action == "branches") && (currentUser->checkIsAdmin()))
        branchesDetails();
    else
        invalid();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void navbarPack()
{
    vector<string> navbar = {"Home", "Reserve", "Movies", "Branches", "Contact Us"};
    system("cls");
    moveCursor(0, 0);
    int i = -1;
    for (auto n : navbar)
    {
        i++;
        if (i == 5)
        {
            cout << endl;
            break;
        }
        else if (i == 1 && (currentUser->checkIsAdmin()))
            continue;
        else if ((i == 3 || i == 2) && !(currentUser->checkIsAdmin()))
            continue;
        cout << "\t" << n << "\t|";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reserve()
{
    action = "";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void moviesDetails()
{
    system("cls");
    appCinema.displayMovies();
    action = "";
    cout << "If you want to add or remove a movie, please type 'add' or 'delete'... " << endl;
    while (true)
    {
        getline(cin, action);
        toLowerCase(action);
        navigationText(action);
        if (action == "add")
        {
            appCinema.addMovie();
            break;
        }
        else if (action == "delete")
        {
            appCinema.rmMovie();
            break;
        }
        else
            invalid();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void branchesDetails()
{
    system("cls");
    appCinema.displayBranches();
    action = "";
    cout << "If you want to add or remove a branch, please type 'add' or 'delete'... " << endl;
    while (true)
    {
        getline(cin, action);
        toLowerCase(action);
        navigationText(action);
        if (action == "add")
        {
            appCinema.addBranch();
            break;
        }
        else if (action == "delete")
        {
            appCinema.rmBranch();
            break;
        }
        else
            invalid();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void contactUs()
{
    action = "";
    system("cls");
    moveCursor(35, 11);
    cout << "Please contact with youneshadi07@gmail.com, in email!" << endl;
    Sleep(5000);
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
User *loginPanel()
{
    string username, pass;
    bool valid = false;
    string situation = "login";
    while (true)
    {
        loginInput();
        moveCursor(30, 9);
        getline(cin, username);
        toLowerCase(username);
        moveCursor(30, 13);
        getline(cin, pass);
        moveCursor(0, 26);
        if ((username == "a" || username == "c") && pass == "pass")
        {
            if (username == "a")
            {
                return new Admin();
            }
            else if (username == "c")
            {
                return new Customer();
            }
            else
                unknownError(situation);
            valid = true;
            mainPanel();
        }
        else
        {
            system("cls");
            moveCursor(35, 11);
            cout << "Please enter a valid username or password...";
            Sleep(4000);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool navigationText(string text)
{
    if (text == "exit")
    {
        system("cls");
        delete currentUser;
        exit(0);
    }
    else if (text == "logout")
    {
        delete currentUser;
        currentUser = loginPanel();
        return true;
    }
    else if (text == "back")
    {
        text = "";
        mainPanel();
        return true;
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toLowerCase(string &text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
            text[i] = tolower(text[i]);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void moveCursor(int x, int y)
{
    COORD position;

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void unknownError(string situation)
{
    system("cls");
    moveCursor(35, 11);
    cout << "An unknown error caused in " << situation << "  checking, please try again later..." << endl;
    Sleep(4000);
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void invalid()
{
    system("cls");
    moveCursor(35, 11);
    cout << "Please enter a valid action..." << endl;
    Sleep(3000);
    mainPanel();
}
void loginInput()
{
    system("cls");
    moveCursor(0, 2);
    for (int i = 0; i <= 21; i++)
    {
        if (i == 0 || i == 21)
        {
            cout << "                    ---------------------------------------                    " << endl;
        }
        else if (i == 3)
        {
            cout << "                   |                WELCOME                |                    " << endl;
        }
        else if (i == 5)
            cout << "                   |      Please enter your username       |                    " << endl;
        else if (i == 9)
            cout << "                   |      Please enter your password       |                    " << endl;
        else if (i == 6 || i == 10 || i == 14)
        {
            cout << "                   |       _________________________       |                    " << endl;
        }
        else if (i == 7 || i == 11)
        {
            cout << "                   |      |                         |      |                    " << endl;
        }
        else if (i == 8 || i == 12)
        {
            cout << "                   |      |_________________________|      |                    " << endl;
        }
        else if (i == 15)
        {
            cout << "                   |      (_________SUBMIT__________)      |                    " << endl;
        }
        else
        {
            cout << "                   |                                       |                    " << endl;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////