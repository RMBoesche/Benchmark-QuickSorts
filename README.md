# Benchmark-QuickSorts
This program test the eficiency of 4 distincts quickSorts.
2 types of partitioning:
- Lomuto and Hoare. 
and 2 types of pivoting for each partitioning: 
- Random and Median of 3.

The input file should be a .txt file with the structure like this:
entrada.txt - example:
2 <-(number of vectors)
3 <-(size) 4 2 5 <-(elements)
5 7 9 1 4 2

There are 3 input files already in the input folder:
- entrada.txt
- entrada-mini.txt
- entrada-gigante.txt

There will be 2 outputs file, one with the vectors sorted 
and the other with stats of the quickSort tested.

This second output file will give: 
1 - Total number of swaps.
2 - Total number of recursive call.
3 - Execution time. (for ALL the vectors in the input file)
