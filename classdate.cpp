// Sheel Kumar
// CSE-40477 HW1
// April 10, 2018

#include <iostream>

// Class that carries month, day, and year
class Date
{
public:
    // Default and only constructor
    Date(int month, int day, int year);

    // Public set and get for each private member variable
    void setMonth(int month);
    int getMonth();
    void setDay(int day);
    int getDay();
    void setYear(int year);
    int getYear();

    // Displays date in MM/DD/YYYY format
    void display();

private:
    int month;
    int day;
    int year;
};

// Constructor - takes in month, day, and year and assigns to appropriate private member
Date::Date(int month, int day, int year)
{
    // Use function to set month to eliminate duplicate code
    setMonth(month);

    this->day = day;
    this->year = year;
}

// Change month value to passed-in parameter
void Date::setMonth(int month)
{
    // Needed for potential month input violation checks
    const int default_month = 1;
    const int maxMonth = 12;
    const int minMonth = 1;

    // Check if month is valid. If not, assign to 1
    if (month > maxMonth || month < minMonth)
    {
        std::cerr << "Invalid month entered\n";
        this->month = default_month;
    }
    else
    {
        this->month = month;
    }
}

// Return current month value
int Date::getMonth()
{
    return month;
}

// Change day value to passed-in parameter
void Date::setDay(int day)
{
    this->day = day;
}

// Return current day value
int Date::getDay()
{
    return day;
}

// Change year value to passed-in parameter
void Date::setYear(int year)
{
    this->year = year;
}

// Return current year value
int Date::getYear()
{
    return year;
}

// Display date using MM/DD/YYYY format
void Date::display()
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

int main()
{
    int myMonth = 0, myDay = 0, myYear = 0;

    // Prompt user to enter values
    std::cout << "Enter month: ";
    std::cin >> myMonth;
    std::cout << "\nEnter day: ";
    std::cin >> myDay;
    std::cout << "\nEnter year: ";
    std::cin >> myYear;

    // Create object with user-input values and display
    Date myDate(myMonth, myDay, myYear);
    myDate.display();

    // Prompt user to change month and return new month value
    std::cout << "Enter new month: ";
    std::cin >> myMonth;
    myDate.setMonth(myMonth);
    std::cout << "\nNew month is: " << myDate.getMonth() << "\n";

    // Prompt user to change day and return new day value
    std::cout << "Enter new day: ";
    std::cin >> myDay;
    myDate.setDay(myDay);
    std::cout << "\nNew day is: " << myDate.getDay() << "\n";

    // Prompt user to change year and return new year value
    std::cout << "Enter new year: ";
    std::cin >> myYear;
    myDate.setYear(myYear);
    std::cout << "\nNew year is: " << myDate.getYear() << "\n";

    // Display new date with changed values
    myDate.display();

    return 0;
}