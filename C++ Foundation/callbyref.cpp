#include<bits/stdc++.h>
using namespace std;

/* call by value
   in this the value of variable is taken not the actually variable so it do not affect the real values of the variables.
*/

int swapbyvalue(int a, int b) //formal arguments
{
    int temp =a;
    a=b;
    b=temp;
}



/* call by reference 
in this actually  we change the value that has assigned to that particular variable address */

void swapbyref(int* a, int* b) //pointers to point to the address of the variables
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x , y; 
    cin>>x>>y;

    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl<<endl;
    cout<<&x<<" is the address of x and "<<&y<<" is the address of y\n\n";


    // swap by "Call by Value"
    swapbyvalue(x,y);  // here are the actual arguements
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl<<endl;

    // swap by "Call by Reference"
    swapbyref(&x,&y);
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl<<endl;



    cout<<&x<<" is the address of x and "<<&y<<" is the address of y\n\n";

}