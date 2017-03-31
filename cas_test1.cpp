/*************************************************************************
    > File Name: cas_test1.cpp
    > Author: Feng
    > Created Time: Fri 31 Mar 2017 07:51:28 PM CST
    > Content: 
 ************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int a = 100;
	__sync_fetch_and_add(&a, 33);
	cout << a << endl;
}
