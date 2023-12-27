/*
1115. Print FooBar Alternately
Solved
Medium
Topics
Companies

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}

The same instance of FooBar will be passed to two different threads:

    thread A will call foo(), while
    thread B will call bar().

Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.

 

Constraints:

    1 <= n <= 1000
*/

class FooBar {
private:
    int n;
    sem_t fooDone;
    sem_t barDone;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&fooDone, 0, 0);
        sem_init(&barDone, 0, 1);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&barDone);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&fooDone);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
            sem_wait(&fooDone);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&barDone);
        }
    }
};

//check thread yield
