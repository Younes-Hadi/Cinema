/// LIBRARIES:...
#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
#include <string>
#include <cctype>
#include <memory>

/// NAMESPACE:...
using namespace std;

/// FUNCTIONS:...
void navbarPack();
void handleAction();
void toLowerCase(string &);
void invalid();
void invalidNumber();
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
    Movie(string title = "", int number = 0) : title(title), number(number) {}
    string getTitle()
    {
        return title;
    }
    void setTitle(string name)
    {
        title = name;
    }

private:
    string title;
    int number;
};
class Seat
{
public:
    Seat(int number = 0, bool reserved = false) : number(number), reserved(reserved) {}
    void reserve()
    {
        reserved = true;
    }
    bool reserveStatus()
    {
        return reserved;
    }
    int getSeats()
    {
        return number;
    }

private:
    int number;
    bool reserved;
};
class ShowTime
{
public:
    ShowTime(string time = "") : time(time) {}
    string getTime() const
    {
        return time;
    }

private:
    string time;
};
class Hall
{
public:
    virtual ~Hall() = default;
    virtual int getPriceMultiplier() = 0;
    void displayTime()
    {
        cout << "Available times:" << endl;
        int i = 1;
        for (const auto &t : times)
        {
            cout << "\t" << i << ". " << t.getTime() << endl;
            i++;
        }
    }
    const ShowTime &getTime(int index)
    {
        return times[index];
    }
    void displaySeats()
    {
        cout << "Available seats: (The 'X' means that the seat has already reserved!)" << endl;
        int i = 0;
        for (auto s : seats)
        {
            if (i % 5 == 0)
                cout << endl
                     << "\t";
            if (s.reserveStatus())
            {
                cout << " X" << "   ";
                i++;
                if (i == 15)
                    cout << endl;
                continue;
            }
            cout << s.getSeats() << "   ";
            i++;
            if (i == 15)
                cout << endl;
        }
    }
    Seat &getSeat(int index)
    {
        return seats[index];
    }
    int timesCount()
    {
        return times.size();
    }
    int seatsCount()
    {
        return seats.size();
    }

protected:
    vector<ShowTime> times{
        {"08:00-10:00"},
        {"10:00-12:00"},
        {"12:00-14:00"},
        {"14:00-16:00"},
        {"16:00-18:00"},
        {"20:00-22:00"}};
    vector<Seat> seats{
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}};
};
class VIPHall : public Hall
{
public:
    int getPriceMultiplier() override
    {
        return 2;
    }
};
class OrdinaryHall : public Hall
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

    Branch(string title = "") : title(title)
    {
        halls.push_back(new OrdinaryHall);
        halls.push_back(new VIPHall);
    }
    string getTitle()
    {
        return title;
    }
    void setTitle(string name)
    {
        title = name;
    }
    Hall *getHall(int index)
    {
        return halls[index];
    }

private:
    vector<Hall *> halls;
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
    }
    void rmBranch()
    {
        int remove;
        while (true)
        {
            cout << endl
                 << "Please enter the number of the branch that you want to remove..." << endl;
            cin >> remove;
            if (remove < 1 || remove > branches.size())
                invalidNumber();
            else if (remove <= branches.size() && remove > 0)
                break;
        }
        branches.erase(branches.begin() + (remove - 1));
        system("cls");
        moveCursor(42, 12);
        cout << "The selected branch removed successfully!" << endl;
        Sleep(4000);
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
    }
    void rmMovie()
    {
        int remove;
        while (true)
        {
            cout << endl
                 << "Please enter the number of the movie that you want to remove..." << endl;
            cin >> remove;
            if (remove < 1 || remove > movies.size())
                invalidNumber();
            else if (remove <= movies.size() && remove > 0)
                break;
        }
        movies.erase(movies.begin() + (remove - 1));
        system("cls");
        moveCursor(42, 12);
        cout << "The selected movie removed successfully!" << endl;
        Sleep(4000);
    }
    const Movie &getMovie(int index)
    {
        return movies[index];
    }
    Branch &getBranch(int index)
    {
        return branches[index];
    }
    int moviesCount()
    {
        return movies.size();
    }
    int branchesCount()
    {
        return branches.size();
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
Cinema appCinema;
class Reservation
{
public:
    Reservation(int price = 10) : price(price) {}
    void chooseMovie()
    {
        system("cls");

        int n;
        while (true)
        {
            appCinema.displayMovies();
            cout << "Please enter the number of the movie that you want to choose..." << endl;
            cin >> n;
            if (n < 1 || n > appCinema.moviesCount())
                invalidNumber();
            else
                break;
        }

        movie = appCinema.getMovie(n - 1);
    }
    void chooseBranch()
    {
        system("cls");

        int n;
        while (true)
        {
            appCinema.displayBranches();
            cout << "Please enter the number of the branch that you want to choose..." << endl;
            cin >> n;
            if (n < 1 || n > appCinema.branchesCount())
                invalidNumber();
            else
                break;
        }

        branch = &appCinema.getBranch(n - 1);
    }
    void chooseHall()
    {
        system("cls");
        int n;
        while (true)
        {
            cout << "1. Ordinary\n2. VIP\n";
            cin >> n;
            if (n < 1 || n > 2)
                invalidNumber();
            else
                break;
        }
        hall = branch->getHall(n - 1);
    }
    void chooseTime()
    {
        system("cls");
        int n;
        while (true)
        {
            hall->displayTime();
            cout << "Please enter the number of the time that you want to choose..." << endl;
            cin >> n;
            if (n < 1 || n > hall->timesCount())
                invalidNumber();
            else
                break;
        }
        time = hall->getTime(n - 1);
    }
    void chooseSeat()
    {
        system("cls");
        int n;
        while (true)
        {
            while (true)
            {
                hall->displaySeats();
                cout << "Please enter the number of the seat that you want to choose..." << endl;
                cin >> n;
                if (n < 1 || n > hall->seatsCount())
                    invalidNumber();
                break;
            }
            seat = &hall->getSeat(n - 1);
            if (seat->reserveStatus())
            {
                system("cls");
                moveCursor(35, 11);
                cout << "This seat is already reserved!" << endl;
                Sleep(3000);
                system("cls");
                continue;
            }
            break;
        }
        seat->reserve();
    }
    void enterName()
    {
        cout << "Please enter your first and last name: ";
        cin.ignore();
        getline(cin, customerName);
    }
    void calculatePrice()
    {
        price *= hall->getPriceMultiplier();
        cout << "Total price: " << price << "$" << endl;
    }
    void reservingFlow()
    {
        chooseBranch();
        chooseMovie();
        chooseHall();
        chooseTime();
        chooseSeat();
        enterName();
        calculatePrice();
        Sleep(4000);
        system("cls");
        moveCursor(35, 11);
        cout << "Reservation complete successfully!" << endl;
        Sleep(4000);
    }

private:
    Movie movie;
    Seat *seat = nullptr;
    ShowTime time;
    Branch *branch;
    Hall *hall = nullptr;
    string customerName;
    int price;
};
// class Ticket
// {
// private:
//     Movie movie;
//     vector<Seat> seat;
//     ShowTime time;
//     Branch branch;
//     int price;
//     string clientsName;
//     string clientsLastName;
// };
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
        return true;
    }
};
class Customer : public User
{
public:
    bool checkIsAdmin() override
    {
        return false;
    }
};

/// VARIABLES:...
User *currentUser = nullptr;
vector<Reservation> currentReserve;

User *loginPanel();

int main()
{
    currentUser = loginPanel();
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainPanel()
{
    while (true)
    {
        navbarPack();
        moveCursor(42, 7);
        cout << "Welcome" << endl;
        moveCursor(1, 15);
        cout << "Please enter an action to do..." << endl;
        handleAction();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void handleAction()
{
    getline(cin, action);
    toLowerCase(action);
    if (navigationText(action))
        return;
    else if (action == "1" || action == "home")
        return;
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
    Reservation thisReserve;
    thisReserve.reservingFlow();
    currentReserve.push_back(thisReserve);
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
        if (navigationText(action))
            return;
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
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
User *loginPanel()
{
    string username, pass;
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
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void invalidNumber()
{
    system("cls");
    moveCursor(35, 11);
    cout << "Please enter a valid number..." << endl;
    Sleep(3000);
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void invalid()
{
    system("cls");
    moveCursor(35, 11);
    cout << "Please enter a valid action..." << endl;
    Sleep(3000);
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