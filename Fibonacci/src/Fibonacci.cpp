#include <iostream>
using namespace std;


//	0 ,für n = 0
//	1, für n = 1
//	f(n-1)+f(n-2), n > 1





 int fib(int i){
		if(i == 0){
			return 0;
		}
		if (i == 1){
			return 1;
		}

		return (fib(i-1)+ fib(i-2));
}

int main() {
int max = 47;

for (int i = 0; i <= max; ++i) {
	cout << fib(i) << endl;

}

	return 0;
}
