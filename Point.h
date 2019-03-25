#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    public:
    Point();
    Point(int x,int y);


    /**
     * @brief calcule la distance entre deux points
     * à partir de l'origine
     * */
    float distance()const ;


    bool operator>(const Point& p)const;
    bool operator<(const Point& p)const;
    bool operator>=(const Point& p)const;
    bool operator<=(const Point& p)const;


    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    
    private:

    /**
     * Coordonnées dews points
     * */
    int x;
    int y;
};
#endif //POINT_H