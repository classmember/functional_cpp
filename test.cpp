/**
 * @file: test.cpp
 * @description: functional cpp examples
 */

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

constexpr unsigned fibonacci(const unsigned x) {
  return x <= 1 ?
    1 :
    fibonacci(x - 1) + fibonacci(x - 2);
}

int main(void) {
    vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7 };
    vector<int> vout;
    ostringstream oss_v;
    ostringstream oss;

    transform(v.begin(),
	      v.end(),
	      back_inserter(vout),
	      [](int & value) { return fibonacci(value); });

    if (!v.empty()) {
        copy(v.begin(),
		  v.end()-1,
		  ostream_iterator<int>(oss_v, ", "));
	oss_v << v.back();
    }

    if (!vout.empty()) {
        copy(vout.begin(),
		  vout.end()-1,
		  ostream_iterator<int>(oss, ", "));
	oss << vout.back();
    }

    cout <<"# fibonacci sequence across an array" <<endl
	 <<"  array:   " <<oss_v.str() <<endl
	 <<"  results: " <<oss.str() <<endl <<endl;

    vector<int>::iterator endfilter = remove_if(vout.begin(), vout.end(), [](int & value){
        if(value % 2 == 0) {
	    return true;
	}
	return false;
    });

    cout <<"# filter only odd numbers" <<endl
	 <<"  odd only: ";
    for(auto itr = vout.begin(); itr != endfilter; itr++) {
        cout <<*itr <<", ";
    }
    cout <<"\b\b" <<endl <<endl;

    int finalVal = accumulate(vout.begin(), endfilter, 0, [](int first, int second){ return first + second;});

    cout <<"# Sum of only odd numbers in fibonacci sequence" <<endl
	 <<"  sum: " <<finalVal <<endl <<endl;
    
    return(0);
}
