/**
 * @file Date.cpp
 * @author  Janssens Emmanuel, Lamrani soulaymane
 * @brief 
 * @version 0.1
 * @date 2019-02-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Date.h"

using namespace std;



Date::Date() 
    : m_day(1),m_month(1),m_year(1970),m_correct(true)
{
    createMonthString();
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
    m_day = day;
    m_month = month;
    m_year = year;
    m_correct = validateMonth(month) && validateDay(day, month);

    createMonthString();

}

Date::Date(unsigned day, Date::Month month, unsigned year)
    :m_day(day),m_month((unsigned)month),m_year(year)
{
    m_correct = validateMonth(m_month) && validateDay(m_day, m_month);
    createMonthString();
}

void Date::createMonthString()
{
    m_stringMonth[0] = "Janvier";
    m_stringMonth[1] = "Fevrier";
    m_stringMonth[2] = "Mars";
    m_stringMonth[3] = "Avril";
    m_stringMonth[4] = "Mai";
    m_stringMonth[5] = "Juin";
    m_stringMonth[6] = "Juillet",
    m_stringMonth[7] = "Aout";
    m_stringMonth[8] = "Septembre";
    m_stringMonth[9] = "Octobre";
    m_stringMonth[10] = "Novembre";
    m_stringMonth[11] = "Decembre";
}

bool Date::isCorrect() const
{
    return m_correct;
}
void Date::setDay(unsigned day)
{
    m_day = day;
    m_correct = validateDay(m_day, m_month);
}

void Date::setMonth(unsigned month)
{
    m_month = month;
    m_correct = validateMonth(m_month);
}

void Date::setMonth(string month)
{
    for(size_t i = 0; i < MONTHS; i++)
    {
        if(m_stringMonth[i] == month)
        {
            m_month = (unsigned)i+1;
            break;
        }
    }
    m_correct = validateMonth(m_month);
}

void Date::setMonth(Date::Month month)
{
    m_month = (unsigned)month;
    m_correct = validateMonth(m_month);
}

void Date::setYear(unsigned year)
{
    m_year = year;
}

unsigned Date::getDay() const
{
    return m_day;
}

unsigned Date::getMonth() const
{
    return m_month;
}

unsigned Date::getYear() const
{
    return m_year;
}

Date::Month Date::getMonthEnum() const
{
    return (Month)m_month;
}

string Date::getMonthString() const
{
    return m_stringMonth[(unsigned)(m_month-1)];
}

bool Date::isBissextile(int year) const
{
    
    return !(year%100) ? !(year%400) : !(year%4);
}

int Date::getNumDaysInMonth(Date::Month month) const
{
    int numDays = 0;

    switch(month)
    {
        case Month::OCTOBRE:
        case Month::DECEMBRE:
        case Month::JANVIER:
        case Month::MARS:
        case Month::MAI:
        case Month::JUILLET:
        case Month::AOUT:
            numDays = 31;
            break;
        case Month::FEVRIER:
            numDays = isBissextile((int)m_year) ? 29 : 28;
         break;
      default:
            numDays = 30;
         break;         
    }    
   
    return numDays;
}

bool Date::validateMonth(unsigned int month)
{
    return (month >= 1 && month <= 12);
}

bool Date::validateDay(unsigned int day, unsigned int month)
{
    return ((day >= 1 && day <= (unsigned)getNumDaysInMonth((Month) month)));
}

bool Date::operator<(const Date& date) const
{
    
    if(this->m_year == date.getYear() && this->m_month == date.getMonth() && this->m_day == date.getDay())
        return false;
        
    return (this->isCorrect() && date.isCorrect()) && (this->m_year < date.getYear() || this->m_month < date.getMonth() || this->m_day < date.getDay());
}
bool Date::operator>(const Date& date) const
{
    if(this->m_year == date.getYear() && this->m_month == date.getMonth() && this->m_day == date.getDay())
        return false;

    return (date < *this);  
}
bool Date::operator<=(const Date& date) const
{
    return !(*this > date);
}

bool Date::operator>=(const Date& date) const
{
    return !(*this < date);
}

bool Date::operator==(const Date& date) const
{
    return (this->isCorrect() && date.isCorrect() ) && (this->m_year == date.getYear() && this->m_month == date.getMonth() && this->m_day == date.getDay());
}



void Date::substractDay(int val)
{
    int days_until_previous_month =  (int)m_day;

    if(val > days_until_previous_month)
    {

        val -= days_until_previous_month;
        
        for(int i = val; i > 0; i -= days_until_previous_month )
        {
            m_day = (unsigned)getNumDaysInMonth((Date::Month)(m_month-1));

            m_month--;

            if(m_month < 1)
            {
                m_year--;
                m_month = 12;
            }

            days_until_previous_month = getNumDaysInMonth((Date::Month)(m_month-1)) ;

            m_day -= (unsigned)i;

        }
    }
    else
    {
        m_day -= (unsigned)val;
    }
   
}

void Date::addDay(int val)
{
    int days_until_next_month = (int)getNumDaysInMonth((Date::Month)(m_month-1)) - (int)m_day;

    if(val > days_until_next_month)
    {
        //to get to the end of the month 
        val -= days_until_next_month;
        
        for(int i = val; i > 0; i -= days_until_next_month )
        {
            m_day = 0;

            m_month++;

            if(m_month > 12)
            {
                m_year++;
                m_month = 1;
            }

            days_until_next_month = (int)getNumDaysInMonth((Date::Month)(m_month-1)) - (int)m_day;

            m_day += (unsigned)i;
        }
    }
    else
    {
        m_day += (unsigned)val;
    }

}
Date Date::operator+(int val)
{
    Date date(m_day,m_month,m_year);

    date.addDay( val);

    return date;
}

Date Date::operator-(int val)
{
   Date date(this->m_day,this->m_month,this->m_year);

    date.substractDay( val);

    return date;
}

Date& Date::operator++()
{
    this->addDay(1);
    return *this;
}

Date& Date::operator--()
{
    this->substractDay(1);
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    temp.addDay(1);
    return temp;
}

Date Date::operator--(int)
{
    Date temp = *this;
    temp.substractDay(1);
    return temp;
}

ostream& operator<<(ostream& os, const Date& d)
{

    if((d.isCorrect()))
        os<<d.m_day<<"."<<d.m_month<<"."<<d.m_year;
    else
        os<<"Incorrect";

    return os;
}

Date Date::operator>>( string &date)
{
    
    cin>>date;

    //Separate string in date
    istringstream ss(date);
    string value;
    
    unsigned int data[3];
    int i = 0;
    while(getline(ss,value,'.'))
    {
        data[i] = (int)stoi(value,nullptr,10);
        i++;

    }

    this->m_day = data[0];
    this->m_month = data[1];
    this->m_year = data[2];
 
    return *this;

}
