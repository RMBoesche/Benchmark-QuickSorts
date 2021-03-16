#include "quicksorts_lib_benchmark.h"

namespace sortStats
{
    data::data() //Default Constructor
        : s{0}, c{0}, t{0}
    {
    }

    void data::clearData() //Set everything to zero.
    {
        s = 0;
        c = 0;
        t = 0;
    }

    bool data::isValidTime(float time) //Check the time given.
    {
        return (time >= 0) ? true : false;
    }

    void data::addTime(float f) //Increase time for a certain amount.
    {
        try
        {
            (isValidTime(f)) ? t += f : throw InvalidTime{};
        }
        catch (InvalidTime) //error if the argument is invalid.
        {
            error("Invalid Time.");
        }
    }
}

/*===============================================================================
                        Begin - Pivos
=================================================================================*/

int median(const Vector<int> &V, int a, int b, int c)
{
    if (V[a] < V[b])
    {
        if (V[b] < V[c])
            return b;
        if (V[a] < V[c])
            return c;
        return a;
    }
    if (V[c] < V[b])
        return b;
    if (V[c] < V[a])
        return c;
    return a;
}

int median3Pivot(const Vector<int> &V, int lo, int hi)
{
    int mean = floor((lo + hi) / 2);

    int pivot = median(V, lo, mean, hi);

    return pivot;
}

int randomPivot(int lo, int hi)
{
    int pivot;

    srand((unsigned)time(0));
    pivot = rand() % (hi - lo + 1) + lo;

    return pivot;
}

/*===============================================================================
                        End - Pivos
=================================================================================*/

/*===============================================================================
                        Begin - QuickSort Lomuto
=================================================================================*/

int lomutoPivoting(Vector<int> &V, int lo, int hi, sortStats::data &stats, int p)
{
    int i, j;

    swap(V[p], V[hi]);
    stats.incSwaps();

    p = V[hi];

    i = lo;

    for (j = lo; j < hi; j++)
    {
        if (V[j] < p)
        {
            swap(V[i], V[j]);
            stats.incSwaps();
            ++i;
        }
    }
    swap(V[i], V[j]);
    stats.incSwaps();

    return i;
}

int lomutoMedian3Pivoting(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    int partitioner = median3Pivot(V, lo, hi);

    return lomutoPivoting(V, lo, hi, stats, partitioner);
}

int lomutoRandomPivoting(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    int partitioner = randomPivot(lo, hi);

    return lomutoPivoting(V, lo, hi, stats, partitioner);
}

void quickSortLomutoMedian3(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    stats.incCalls();

    if (lo < hi)
    {
        int pivot = lomutoMedian3Pivoting(V, lo, hi, stats);

        quickSortLomutoMedian3(V, lo, (pivot - 1), stats);
        quickSortLomutoMedian3(V, (pivot + 1), hi, stats);
    }
}

void quickSortLomutoRandom(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    stats.incCalls();

    if (lo < hi)
    {
        int pivot = lomutoRandomPivoting(V, lo, hi, stats);

        quickSortLomutoRandom(V, lo, (pivot - 1), stats);
        quickSortLomutoRandom(V, (pivot + 1), hi, stats);
    }
}

/*===============================================================================
                        End - QuickSort Lomuto
=================================================================================*/

/*===============================================================================
                        Begin - QuickSort Hoare
=================================================================================*/

int hoarePivoting(Vector<int> &V, int lo, int hi, sortStats::data &stats, int p)
{
    int i = lo - 1;
    int j = hi + 1;

    swap(V[p], V[lo]);
    stats.incSwaps();

    p = V[lo];

    while (true)
    {
        do
        {
            ++i;
        } while (V[i] < p);

        do
        {
            --j;
        } while (V[j] > p);

        if (i >= j)
            return j;

        swap(V[i], V[j]);
        stats.incSwaps();
    }
}

int hoareMedian3Pivoting(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    int partitioner = median3Pivot(V, lo, hi);

    return hoarePivoting(V, lo, hi, stats, partitioner);
}

int hoareRandomPivoting(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    int partitioner = randomPivot(lo, hi);

    return hoarePivoting(V, lo, hi, stats, partitioner);
}

void quickSortHoareMedian3(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    stats.incCalls();

    if (lo < hi)
    {
        int pivot = hoareMedian3Pivoting(V, lo, hi, stats);

        quickSortHoareMedian3(V, lo, pivot, stats);
        quickSortHoareMedian3(V, (pivot + 1), hi, stats);
    }
}

void quickSortHoareRandom(Vector<int> &V, int lo, int hi, sortStats::data &stats)
{
    stats.incCalls();

    if (lo < hi)
    {
        int pivot = hoareRandomPivoting(V, lo, hi, stats);

        quickSortHoareRandom(V, lo, pivot, stats);
        quickSortHoareRandom(V, (pivot + 1), hi, stats);
    }
}

/*===============================================================================
                        End - QuickSort Hoare
=================================================================================*/

/*===============================================================================
                        Begin - Benchmark
=================================================================================*/

void quickSortStats(Vector<int> &V, sortStats::data &stats, int quickSort)
{
    clock_t start, end;
    float t;

    switch (quickSort)
    {
    case LOMUTO_MEDIAN3:
        start = clock();
        quickSortLomutoMedian3(V, 0, (V.size() - 1), stats);
        end = clock();

        t = ((end - start) * 1000.0) / ((float)CLOCKS_PER_SEC);
        stats.addTime(t);
        break;

    case LOMUTO_RANDOM:
        start = clock();
        quickSortLomutoRandom(V, 0, (V.size() - 1), stats);
        end = clock();

        t = ((end - start) * 1000.0) / ((float)CLOCKS_PER_SEC);
        stats.addTime(t);
        break;

    case HOARE_MEDIAN3:
        start = clock();
        quickSortHoareMedian3(V, 0, (V.size() - 1), stats);
        end = clock();

        t = (float)((end - start) * 1000.0) / ((float)CLOCKS_PER_SEC);
        stats.addTime(t);
        break;

    case HOARE_RANDOM:
        start = clock();
        quickSortHoareRandom(V, 0, (V.size() - 1), stats);
        end = clock();

        t = ((end - start) * 1000.0) / ((float)CLOCKS_PER_SEC);
        stats.addTime(t);
        break;
    }
}

void printfVector(const Vector<int> &V, ofstream &ofs)
{
    for (int i = 0; i < V.size(); ++i)
    {
        ofs << V[i] << " ";
    }
    ofs << "\n";
}

void createStatsFile(const sortStats::data &stats, string ofnameStats)
{
    ofstream ofsStats{ofnameStats};
    if (!ofsStats)
        error("Can't open output stats file ", ofnameStats);

    ofsStats << "Total number of swaps: " << stats.swaps() << endl;
    ofsStats << "Total number of recursive call: " << stats.calls() << endl;
    ofsStats << "Execution time: " << stats.time() << " ms" << endl;

    ofsStats.close();
}

void benchmark(int quickSort, string ifname, string ofname, string ofnameStats)
{
    ifstream ifs{ifname}; //ifs: Input File Stream.
    if (!ifs)
        error("Can't open input file ", ifname);

    ofstream ofs{ofname}; //ofs: Output File Stream.
    if (!ofs)
        error("Can't open output file ", ofname);

    sortStats::data stats; //A class to keep the stats of the current quickSort.

    int n, size; //n is the number of vector in the file.
    ifs >> n;
    ofs << n << endl;

    for (int i = 0; i < n; ++i)
    {
        ifs >> size; //Gets the size of the vector in the file
        ofs << size << " ";
        Vector<int> V(size); //Create a vector with that size

        for (int j = 0; j < size; ++j)
        {
            ifs >> V[j]; //Fill the vector.
        }

        quickSortStats(V, stats, quickSort); //Sort the vector and get the stats of the quickSort.

        printfVector(V, ofs); //Write the vector on the output file.
    }

    ifs.close();
    ofs.close();

    createStatsFile(stats, ofnameStats);
}

/*===============================================================================
                        End - Benchmark
=================================================================================*/