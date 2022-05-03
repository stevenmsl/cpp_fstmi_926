#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol926;

/*
Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
*/
tuple<string, int>
testFixture1()
{
  return make_tuple("00110", 1);
}

/*
Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
*/
tuple<string, int>
testFixture2()
{
  return make_tuple("010110", 2);
}

/*
Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
*/
tuple<string, int>
testFixture3()
{
  return make_tuple("00011000", 2);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minFlips(get<0>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minFlips(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minFlips(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}