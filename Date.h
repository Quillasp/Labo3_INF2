/**
 * @file Date.h
 * @author Janssens emmanuel, Lamrani soulaymane 
 * @brief déclaration de toutes les foncitons, et utilités 
 *          pour manipuler des dates
 * @version 0.1
 * @date 2019-02-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef DATE_H
#define DATE_H

#define MONTHS 12

#include <iostream>
#include<sstream>
#include <string>

/**
 * @brief 
 * 
 */
class Date
{
    public:

        /**
         * @brief Enumeration that contains the months in a year
         * 
         */
        enum class Month{JANVIER,FEVRIER,MARS,AVRIL,MAI,JUIN,JUILLET,AOUT,SEPTEMBRE,OCTOBRE,NOVEMBRE,DECEMBRE};

        /**
         * @brief Construct a new Date object (Default constructor)
         * 
         */
        Date();

        /**
         * @brief Construct a new Date object
         * 
         * @param day 
         * @param month 
         * @param year 
         */
        Date(unsigned day,unsigned month,unsigned year);

        /**
         * @brief Construct a new Date object
         * 
         * @param day 
         * @param month 
         * @param year 
         */
        Date(unsigned day, Month month, unsigned year);


        /******Muttateurs********/
        
        /**
         * @brief Set the Day object
         * 
         * @param day 
         */
        void setDay(unsigned day);

        /**
         * @brief Set the Month object
         * 
         * @param month 
         */
        void setMonth(unsigned month);

        /**
         * @brief Set the Month object
         * 
         * @param month 
         */
        void setMonth(std::string month);

        /**
         * @brief Set the Month object
         * 
         * @param month 
         */
        void setMonth(Month month);

        /**
         * @brief Set the Year object
         * 
         * @param year 
         */
        void setYear(unsigned year);

        /******Accesseurs*******/
        
        /**
         * @brief Get the Day object
         * 
         * @return unsigned 
         */
        unsigned getDay() const;

        /**
         * @brief Get the Month object
         * 
         * @return unsigned 
         */
        unsigned getMonth( ) const;

        /**
         * @brief Get the Month String object
         * 
         * @return string 
         */
        std::string getMonthString() const;

        /**
         * @brief Get the Month Enum object
         * 
         * @return Month 
         */
        Month getMonthEnum() const;

        /**
         * @brief Get the Year object
         * 
         * @return unsigned 
         */
        unsigned getYear() const;

        /**
         * @brief display date as dd.mm.yyyy
         * 
         * @param date 
         * 
         * @return ostream
         */
        friend std::ostream &operator<<(std::ostream& os,const Date& date);

        /**
         * @brief inputs a date in format dd.mm.yyyy
         * 
         * @param date 
         * @return Date 
         */
        Date operator>>( std::string& date);

        /**
         * @brief compare two dates
         * 
         * @param date 
         * @return true 
         * @return false 
         */
        bool operator>( const Date& date)const;

        /**
         * @brief Compare two dates
         * 
         * @param date 
         * @return true 
         * @return false 
         */
        bool operator<(const Date& date)const;

        /**
         * @brief Compare two dates
         * 
         * @param date 
         * @return true 
         * @return false 
         */
        bool operator>=(const Date& date)const;

        /**
         * @brief Compare two dates
         * 
         * @param date 
         * @return true 
         * @return false 
         */
        bool operator<=(const Date& date)const;

        /**
         * @brief Compare two dates
         * 
         * @param date 
         * @return true 
         * @return false 
         */
        bool operator==(const Date& date)const;

        /**
         * @brief adds an amount of days to the date
         * 
         * @param val 
         * @return Date 
         */
        Date operator+(int val);
        friend Date operator+(int val, const Date& date);

        /**
         * @brief Substract an amount of days to the date
         * 
         * @param val 
         * @return Date 
         */
        Date operator-(int val);


        
        /**
         * @brief Add one day to a day
         * 
         * @return Date 
         */
        Date &operator++();


        Date operator++(int);


        /**
         * @brief substract one day to a day
         * 
         * @return Date 
         */
        Date &operator--();

        Date operator--(int);

    private:

       /**
         * @brief Contains all the algorithmic to add days to a date
         * 
         * @param val amount of days to be added to the date
         */
        void addDay(int val);

        /**
         * @brief Substracts a certain value to a date
         * 
         * @param val value to be substracted
         */
        void substractDay(int val);

        /**
         * @brief Insert date in tho the month string array
         * 
         */
        void createMonthString();

        /**
         * @brief Needed to check if the date is valid
         * 
         * @return true 
         * @return false 
         */
        bool isCorrect() const;

        /**
         * @brief Determines if a year bissextile or not
         * 
         * @param year 
         * @return true 
         * @return false 
         */
        bool isBissextile(int year)const;

        /**
         * @brief Get the Num Days In Month object
         * 
         * @param month 
         * @return int 
         */
        int getNumDaysInMonth(Month month)const;

        /**
         * @brief Determines if a month is correctly set or not
         *
         */
        bool validateMonth(unsigned int month);

        /**
         * @brief Determines if a day is correctly set or not
         *
         */
         bool validateDay(unsigned int day, unsigned int month);
        
        /**
         * @brief An array of strings containing the string value of the monthts
         * 
         */
        std::string m_stringMonth[MONTHS];

        /**
         * @brief day of the date
         * 
         */
        unsigned int m_day;

        /**
         * @brief month of the date
         * 
         */
        unsigned int m_month;

        /**
         * @brief year of the date
         * 
         */
        unsigned int m_year;

       /**
         * @brief defines if a date is correct
         * 
         */
        bool m_correct;
};

#endif //DATE_H