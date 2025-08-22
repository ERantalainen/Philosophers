This project is a part of the 42 curriculum. The goal is to make a multithreading program, where multiple threads, without directly communicating with each other use shared resources.

The "philosophers" all must eat, sleep and think. However, if they do not eat within a certain timelimit, set at program launch, they will die. There are no global variables, and no direct communication between threads. 
I use a death checker thread, to monitor the status of all philosophers, while the philosophers simply focus on repeating their loop. 
