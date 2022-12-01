#include<bits/stdc++.h>
using namespace std;

int NthTerm(int n){
		    int i = 1;
		    long long int last = 1;
		    while(i<=n) {
		        last = last*i + 1;
		        i++;
		    }
		    return last;
		}
		
int main() {
	cout<<NthTerm(12);
	return 0;
}
