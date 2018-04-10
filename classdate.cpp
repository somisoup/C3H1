#include <iostream>

class date
{
    public:
    date(int monthToSet, int dayToSet, int yearToSet);

    void setMonth(int monthToSet);
    int getMonth();

    void setDay(int dayToSet);
    int getDay();

    void setYear(int yearToSet);
    int getYear();

    void display();

    private:
    int month;
    int day;
    int year;

    const int default_month = 1;

    bool isMonthValid(int monthToCheck);
};

date::date(int monthToSet, int dayToSet, int yearToSet)
{
    if (isMonthValid(monthToSet))
    {
        month = monthToSet;
    }
    else
    {
        month = default_month;
    }

    day = dayToSet;
    year = yearToSet;
}

void date::setMonth(int monthToSet)
{
    if (isMonthValid(monthToSet))
    {
        month = monthToSet;
    }
    else
    {
        month = default_month;
    }
}

int date::getMonth()
{
    return month;
}

void date::setDay(int dayToSet)
{
    day = dayToSet;
}

int date::getDay()
{
    return day;
}

void date::setYear(int yearToSet)
{
    year = yearToSet;
}

int date::getYear()
{
    return year;
}

void date::display()
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

bool date::isMonthValid(int monthToCheck)
{
    if (monthToCheck > 12 || monthToCheck < 1)
    {
        std::cerr << "Invalid month entered\n";
        return false;
    }

    return true;
}

int main()
{
    int myMonth = 0, myDay = 0, myYear = 0;
    std::cout << "Enter month: ";
    std::cin >> myMonth;
    std::cout << "\nEnter day: ";
    std::cin >> myDay;
    std::cout << "\nEnter year: ";
    std::cin >> myYear;
    
    date myDate(myMonth, myDay, myYear);
    myDate.display();

    std::cout << "Enter new month: ";
    std::cin >> myMonth;
    myDate.setMonth(myMonth);
    std::cout << "\nNew month is: " << myDate.getMonth() << "\n";

    std::cout << "Enter new day: ";
    std::cin >> myDay;
    myDate.setDay(myDay);
    std::cout << "\nNew day is: " << myDate.getDay() << "\n";

    std::cout << "Enter new year: ";
    std::cin >> myYear;
    myDate.setYear(myYear);
    std::cout << "\nNew year is: " << myDate.getYear() << "\n";

    myDate.display();

    return 0;   
}