/*
1116. Print Zero Even Odd
Solved
Medium
Topics
Companies

You have a function printNumber that can be called with an integer parameter and prints it to the console.

    For example, calling printNumber(7) prints 7 to the console.

You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

    Thread A: calls zero() that should only output 0's.
    Thread B: calls even() that should only output even numbers.
    Thread C: calls odd() that should only output odd numbers.

Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

    ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
    void zero(printNumber) Calls printNumber to output one zero.
    void even(printNumber) Calls printNumber to output one even number.
    void odd(printNumber) Calls printNumber to output one odd number.

 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.

Example 2:

Input: n = 5
Output: "0102030405"

 

Constraints:

    1 <= n <= 1000
*/

class ZeroEvenOdd {
private:
    int n;
    sem_t zs;
    sem_t es;
    sem_t os;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zs, 0, 1);
        sem_init(&es, 0, 0);
        sem_init(&os, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        // there will be n zeroes
        for(int i = 0; i < n; i++)
        {
            //note that here we initialize the value of zs to be 1. 
            // otherwise in the first instance of 0, the wait will never get a
            // go ahead
            sem_wait(&zs);
            printNumber(0);
            //0th 0 will be followed by odd number. 1st 0 by even number and so on
            if(i%2 != 0)
                sem_post(&es);
            else
                sem_post(&os);
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <=n; i+=2)
        {
            sem_wait(&es);
            printNumber(i);
            sem_post(&zs);
        }
        
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <=n; i+=2)
        {
            sem_wait(&os);
            printNumber(i);
            sem_post(&zs);
        }
    }
};

//try with condition variables also
