# ProjectTwoOS
Overview
My name is Annika Morgan and for assignment 1 for Operating Systems, we had to consider a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?


contents: banker.cpp, input.txt


How it Works
The input.txt file contains the number of processes, the values of allocations, the availavle values, and the values of maximums. The banker.cpp checks if a system is in a safe state by calculating the resources needed by th processes. Then banker.cpp reads input from input.txt, calculates the resources needs, and determines a sage sequence of processes. If all process can be completed without deadlock, it prints the safe sequence.


Example Output
System is in Safe State.
Safe sequence is: 1 3 4 0 2


Problems Faced
I was having trouble implementing the txt file and figuring out how the values in the table should go with the banker.cpp.
