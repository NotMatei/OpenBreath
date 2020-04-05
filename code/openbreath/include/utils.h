#pragma once

class Date
{
public:
    Date( unsigned int day, unsigned int month, unsigned int year ):
        day( day > 31 ? 31 : day), 
        month( month > 12 ? ( month < 1 ? 1 : month) : month ),
        year( year < 2020 ? 2020 : year )
    {};

    Date( const Date &date )
    {
        day = date.day;
        month = date. month;
        year = date.year;
    }

    unsigned int
        day, month, year;
};