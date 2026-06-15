/// LIBRARIES:...
#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
#include <string>
#include <cctype>

/// NAMESPACE:...
using namespace std;

/// CLASSES:...
class Cinema
{
public:
    Cinema(string branch = "", string name = "", string hall = "") : branch(branch), name(name), hall(hall) {}
    // string showBranch() {};

private:
    string branch, name, hall;
};
class Movie
{
public:
    Movie(string title = "", int duration = 0) : title(title), duration(duration) {}

private:
    string title;
    int duration;
};
class ShowTime
{
public:
    ShowTime(string reserved = "") : reserved(reserved) {}
    void printTimes()
    {
        for (auto &t : time)
        {
            cout << t << endl;
        }
    }

private:
    vector<string> time = {"08:00-10:00", "10:00-12:00", "12:00-14:00", "14:00-16:00", "16:00-18:00", "20:00-22:00"};
    string reserved;
};
class Seat
{
public:
    Seat(int row = 0, int number = 0, bool reserved = false) : row(row), number(number), reserved(reserved) {}

private:
    int row, number;
    bool reserved;
};
class Reserving
{
public:
    Reserving(string movie = "", string seat = "", string time = "") : movie(movie), seat(seat), time(time) {}

private:
    vector<Movie> movies;
    vector<Seat> seats;
    vector<ShowTime> times;
    string movie, seat, time;
};
class Ticket
{
public:
    Ticket(Movie movie, Seat seat, ShowTime time, Cinema cinema, int price) : movie(movie), seat(seat), time(time), cinema(cinema), price(price) {}

private:
    Movie movie;
    Seat seat;
    ShowTime time;
    Cinema cinema;
    int price;
    string clientsName;
    string clientsLastName;
};

/// FUNCTIONS:...
void navbarPack();
void toLowerCase(string &);
void moveCursor(int, int);
int main()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void navbarPack()
{
    vector<string> navbar = {"Home", "Cinemas", "movies", "reserve", "contact us"};
    system("cls");
    moveCursor(0, 0);
    int i = 0;
    for (auto n : navbar)
    {
        if (i == 0)
            cout << "\t";
        if (i == 4)
            cout << endl;
        cout << n << "\t|";
    }
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  = {"Regal Times square", "AMC Lincoln square", "Roof Top Cinema Club Midtown", "AMC 84th Street 6", "Regal Battery Park", "AMC Empire 25", "AMC Village 7", "Angelika Film Cinema And Cofe", "IFC Center", "The Paris Theater", "Quad Cinema"};