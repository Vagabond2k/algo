#include <stdio.h>
#define N 10000


// goal is to print pair node that are 
// not connected, in order to do that 
// we pick one of the two node p or q 
// and use is value on the array to mark 
// the other eg (p,q) -> (3,2): with q 
// elected as value marker
//  0 1 2 3 4 5 6
// [0 1 2 3 4 5 6 ..]
// became
// [0 1 2 2 4 5 6 ..]
// marking the two as equal value
// make them connected
int main()
{ // p object 
  // q object 
  // p&&q => (3,2)
  // i counter 0 to N
  // N maximum number of node
  // id array contain node 
  int i, p, q, t, id[N];
  //initialiaze the array id from 0 to N - 1
  for (i=0; i< N; i++) id[i] = i;
  while( scanf("%d %d", &p, &q) == 2 )
     {
         printf ("Evaluating %d %d\n", p, q);
         // if two nodes match go further 
         // this is the critical piece because 
         // if they are of equal value they are connected
	     if (id[p] == id[q]){
             printf("p and q are connected\n");
             continue;
         }
         // start loop, assigning to t the value of 
         // node p on the board
         // let's say that p is 3
         // [0 1 2 3 4 5 6]
	     for (t = id[p], i=0; i<N; i++){
            // if first time 
            // p is 3 so is t, i is 0 
            // when id[i] == 3 transform the value
            // from 3 to 2 that is q to enable 
            // the connection
	        if (id[i] == t){ 
                //change the value of all the array elements
                //that has as index the value of p in the array
                //this is brilliant and is the key to the algo
                //because it basically move a group of connection 
                //already made to a new group of possible connection
                id[i] = id[q];
            }
          }
	     printf ("Still Not Connected %d %d\n", p, q);
	 }
}


//due to the fact that to perform a union operation we have to loop 
//the entire array of length N, this lead to a high computational time
//for N object provided as input. 
//The quick-find algorithm executes at least M N instruction to solve 
//a connectivity problem with N objects that involves union operation

