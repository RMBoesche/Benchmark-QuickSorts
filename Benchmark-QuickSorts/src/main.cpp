/*This program teste the eficiency of 4 distincts quickSorts.
(2 types of partitioning - Lomuto and Hoare 
and 2 types of pivoting - Random and Median of 3)

The input file should be a file with the structure like this:
entrada.txt - example:
2 <-(number of vectors)
3 <-(size) 4 2 5 <-(elements)
5 7 9 1 4 2

There will be 2 outputs file, one with the vectors sorted 
and the other with stats of the quickSort tested.

This second file will output: 
1 - Total number of swaps.
2 - Total number of recursive call.
3 - Execution time. (for ALL the vectors in the input file)
 */
#include "../lib/quicksorts_lib_benchmark.h"

int main()
{
    cout << "Input file name: " << endl;
    cout << "../input/"; //the path of the file.

    string inputFile;
    cin >> inputFile;
    inputFile = "../input/" + inputFile; //concatenate the name, to get the correct path.

    //benchmark(quick _type, "file type", "file output with the sorted vectors", "file output with the stats");
    benchmark(LOMUTO_MEDIAN3, inputFile, "../output/output-median3-lomuto.txt", "../output/stats-median3-lomuto.txt");
    benchmark(LOMUTO_RANDOM, inputFile, "../output/output-random-lomuto.txt", "../output/stats-random-lomuto.txt");
    benchmark(HOARE_MEDIAN3, inputFile, "../output/output-median3-hoare.txt", "../output/stats-median3-hoare.txt");
    benchmark(HOARE_RANDOM, inputFile, "../output/output-random-hoare.txt", "../output/stats-random-hoare.txt");

    return 0;
}
