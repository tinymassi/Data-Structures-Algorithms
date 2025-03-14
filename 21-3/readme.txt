To test the efficiency of my quicksort program with or without mo3, I
ran tests of pre sorted data. Since mo3 is designed to handle pre-sorted data,
I was searching for the point in which the efficiency of the mo3 implementation 
diverged from the non-mo3 implementation. Here are my test cases:

Inputs:      No m03:      Yes mo3:
100:         0.011s       0.011s
200:         0.012s       0.012s
300:         0.014s       0.014s
400:         0.017s       0.017s
500:         0.018s       0.014s
700:         0.026s       0.016s
900:         0.035s       0.017s
1000:        0.029s       0.018s
2000:        0.040s       0.026s
5000:        0.317s       0.076s
10000:       1.099s       0.103s

At Inputs = 500, we notice our first difference between the processing time
of the quicksort program with mo3 (0.014s) and without m03 (0.018s). From that
point on the execution time of the program without mo3 diverges more and more.
It is for this reason that I set the size of A to be greater than 500 for the 
mo3 function to be utilized.
