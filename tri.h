#ifndef TRI_H
#define TRI_H

#include <iostream>
#include <vector>

/**
 * @brief Détermine le pivot à utiliser dans le tri rapide
 * @param begin : début du vecteur à trier
 * @param end : fin du vecteur à trier
 * @return : retourne un itérateur du type contenu dans le vecteur
 */
template < typename RandomAccessIterator >
RandomAccessIterator selectPivot( const RandomAccessIterator begin,
                                 const RandomAccessIterator end )
{
    RandomAccessIterator p1 = begin;
    RandomAccessIterator p2 = begin + ( end-begin ) / 2;
    RandomAccessIterator p3 = end - 1;

    if(*p1 < *p2) {
        if( *p2 < *p3 ) return p2;
        else if(*p1 < *p3) return p3;
        return p1;
    } else {
        if( *p1 < *p3 ) return p1;
        else if(*p2 < *p3) return p3;
        return p2;
    }
}

/**
 * @brief Partitionne le vecteur pour permettre l'appel récursif sur chacun des sous-tableaux
 * @param BeginIterator : début du vecteur à trier
 * @param EndIterator : fin du vecteur à trier
 * @return : retourne un itérateur du type contenu dans le vecteur
 */
template <typename T> T partition(T BeginIterator, T EndIterator)
{
    auto i = BeginIterator - 1;
    auto j = EndIterator - 1;

    while (true)
    {
        do {
            i++;
        } while (*i < *(EndIterator - 1));

        do {
            j--;
        } while (j > BeginIterator && *(EndIterator - 1) < *j);

        if (i >= j) break;

        // std::iter_swap(i, j);
        auto tmp = *i;
        *i = *j;
        *j = tmp;
    }

    // std::iter_swap(i, EndIterator - 1);
    auto tmp = *i;
    *i = *(EndIterator - 1);
    *(EndIterator - 1) = tmp;
    return i;

}

/**
 * @brief Quicksort ou tri rapide, qui effectuera le tri en faisant un appel récursif. Le pivot y est déterminé
 * et le partitionnement aussi.
 * @param begin : début du vecteur à trier
 * @param end : fin du vecteur à trier
 */
template <typename T> void quicksort (T BeginIterator, T EndIterator)
{
    if (EndIterator - 1 <= BeginIterator)
		return;

    auto p = selectPivot(BeginIterator, EndIterator);
    // std::iter_swap(EndIterator - 1, p);
    auto tmp = *(EndIterator - 1);
    *(EndIterator - 1) = *p;
    *p = tmp;

    auto i = partition(BeginIterator, EndIterator);

    quicksort(BeginIterator, i);
    quicksort(i + 1, EndIterator);
}

/**
 * @brief Affichage du contenu d'un tableau
 * @param v : vecteur à afficher
 */
template <typename T> void display (T v)
{
	for (auto i = v.begin(); i != v.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief Affiche le vecteur avant et après le tri
 * @param v : vecteur à tester
 */
template <typename T> void test (T v)
{
	display(v);
	quicksort(v.begin(), v.end());
	display(v);
}

#endif // TRI_H