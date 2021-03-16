#include "../include/std_lib_facilities.h"

constexpr int LOMUTO_MEDIAN3 = 0, LOMUTO_RANDOM = 1, HOARE_MEDIAN3 = 2, HOARE_RANDOM = 3;

namespace sortStats
{

    class data
    {
    public:
        data(); //Default Constructor.

        int swaps() const { return s; }
        int calls() const { return c; }
        float time() const { return t; }
        void incSwaps() { s++; }
        void incCalls() { c++; }
        void addTime(float);
        void clearData();

        class InvalidTime
        {
        };

    private:
        int s;   //swaps counter
        int c;   //calls counter
        float t; //time pass
        bool isValidTime(float);
    };
}

/*===============================================================================
                        Begin - Pivots
=================================================================================*/

int median(const Vector<int> &, int, int, int);

int median3Pivot(const Vector<int> &, int, int);

int randomPivot(int, int);

/*===============================================================================
                        End - Pivos
=================================================================================*/

/*===============================================================================
                        Begin - QuickSort Lomuto
=================================================================================*/

int lomutoPivoting(Vector<int> &, int, int, sortStats::data &, int);

int lomutoMedian3Pivoting(Vector<int> &, int, int, sortStats::data &);

int lomutoRandomPivoting(Vector<int> &, int, int, sortStats::data &);

void quickSortLomutoMedian3(Vector<int> &, int, int, sortStats::data &);

void quickSortLomutoRandom(Vector<int> &, int, int, sortStats::data &);

/*===============================================================================
                        End - QuickSort Lomuto
=================================================================================*/

/*===============================================================================
                        Begin - QuickSort Hoare
=================================================================================*/

int hoarePivoting(Vector<int> &, int, int, sortStats::data &, int);

int hoareMedian3Pivoting(Vector<int> &, int, int, sortStats::data &);

int hoareRandomPivoting(Vector<int> &, int, int, sortStats::data &);

void quickSortHoareMedian3(Vector<int> &, int, int, sortStats::data &);

void quickSortHoareRandom(Vector<int> &, int, int, sortStats::data &);

/*===============================================================================
                        End - QuickSort Hoare
=================================================================================*/

/*===============================================================================
                        Begin - Benchmark
=================================================================================*/

void quickSortStats(Vector<int> &, sortStats::data &, int);

void printfVector(const Vector<int> &, ofstream &);

void createStatsFile(const sortStats::data &, string);

void benchmark(int, string, string, string);

/*===============================================================================
                        End - Benchmark
=================================================================================*/