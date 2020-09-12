# BinarySort
Binary sort is an algorithm that sorts the given array of numbers based on its binary value.

# How to use
First compile both C file using following command: "gcc -o BinarySort BinarySort.c" & "gcc -o Generator Generator.c"
Then run "Generator.exe" file using following command: "Generator.exe 10000 Data.txt" - Here 10000 is size of array which is going to be generated.
It will generate Data.txt file, filled with 10000 random numbers.
Then run "BinarySort.exe" file using following command: "BinarySort.exe 10000 Data.txt" for windows & "./BinarySort 10000 Data.txt" for linux
It will use Data.txt file as an input to the algorithm and sort thos data and will generate "Sorted Data.txt" file which is sorted output.

# Working of an algorithm
This algorithm is work on binery value of the numbers.
Suppose, given num is 8, 6 and 5 then it will first check the 4th bit of all num if one of them is 1(logic 1) then it will be the biggest num else it will create new array of all 4th bit 1 nums.
In our case 8=1000, 6=0110, 5=0011. 4th bit of 8 is 1 but 6 & 5 is 0 so the biggest one is 8.
In the next step it will check for 3rd bit but excluding 8 which is alrady biggest. So here 6=0110 & 5=0101 now 3rd bit of both num is 1 so it will goto check 2nd bit for those two only. By comparing 2nd bit it will get biggest of them is 6.
Last only num is filled in to the arry list and we got the sorted num.
