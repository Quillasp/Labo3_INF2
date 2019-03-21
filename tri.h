#ifndef TRI_H
#define TRI_H

#include <iostream>
#include <vector>

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

template <typename T> void display (T v)
{
	for (auto i = v.begin(); i != v.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

template <typename T> void test (T v)
{
	display(v);
	quicksort(v.begin(), v.end());
	display(v);
}

#endif // TRI_H