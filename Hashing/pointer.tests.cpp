#include<bits/stdc++.h>
using namespace std;

int main() {
	int a = 5;
	int *p1; // pointer type variable will only store address of int data type
	p1 = &a; //way to initialize
	
	cout<<"\n\n\n";
	/*
	cout<<p1<<" "<<&a<<" are the address\n";
	cout<<*p1<<" "<<a<<" are the values\n";
	cout<<&p1<<" is the address of pointer p1\n";
	*/
	
	/* Double Pointers */
	
	int **p2; // double pointer variable
	p2 = &p1; // will store the address of pointer p1
	cout<<&p2<<" is the address of pointer p2\n";
	cout<<p2<<" is the value of pointer p2 and its value is address of pointer p1\n";
	cout<<*p2<<"it gives the value stored in pointer p1, address of original variable a\n";
	cout<<**p2<<" is the value of original variable\n";
	
	cout<<"\n\n\n";
	
	/* Similarly triple pointers can be created and so on the no of stars increases and it goes on */
}
