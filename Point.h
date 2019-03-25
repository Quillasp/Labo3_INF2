
/**
 * @file Point.h
 * @author Janssens Emmanuel
 * @brief  Coordonnées dans le plan réel
 * @date 2019-03-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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


    /**
     * @brief Surcharge des opérateurs de comparaisons
     * 
     * @param p 
     * @return true 
     * @return false 
     */
    bool operator>(const Point& p)const;
    bool operator<(const Point& p)const;
    bool operator>=(const Point& p)const;
    bool operator<=(const Point& p)const;

    /**
     * @brief Surcharge de l'opérateur de flux
     * 
     * @param os flux dans lequel il faut écrire
     * @param point Point que l'on veut afficher
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    
    private:

    /**
     * Coordonnées des points
     * */
    int x;
    int y;
};
#endif //POINT_H