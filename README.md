# Benchmark-QuickSorts
This program test the eficiency of 4 distincts quickSorts.

2 types of partitioning:
- Lomuto and Hoare. 

and 2 types of pivoting for each partitioning: 
- Random and Median of 3.

The input file should be a .txt file with the structure like this:

(number of vectors) 

(size)  (elements)

Example - input.txt: 

2 

3 4 2 5 

5 7 9 1 4 2

There are 3 input files already in the input folder:
- entrada.txt
- entrada-mini.txt
- entrada-gigante.txt

There will be 2 outputs files for each quickSort (total 8 output files), one with the vectors sorted 
and the other with stats of the quickSort tested.

This stats output file will give: 
- Total number of swaps.
- Total number of recursive call.
- Execution time. (for ALL the vectors in the input file)
