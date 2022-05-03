#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol926;
using namespace std;

/*takeaways
  - using DP
    - calculate the moves required to flip
      the following substrings into all 1's
      s[n-1],s[n-2..n-1],s[n-3..n-1]...s[0,n-1]
    - calculate the moves required to flip
      the following substrings into all 0's
      s[0],s[0..1],s[0..2]...s[0,n-1]
    - try all combinations of breaking s
      into two parts and find the min flips
      s[0..i-1], l[i-1] is the number of moves
                 required to change it to all 0's
      s[i..n-1], r[i+1] is the number of moves
                 required to change it to all 1's
      total moves = l[i-1] + r[i+1]

*/

int Solution::minFlips(string s)
{
  const int n = s.size();
  /* how many flips needed
     to make s[0..i] all 0's
  */
  auto l = vector<int>(n + 1);
  /* how many flips needed
     to make s[i..n-1] all 1's
     - set it to have one more
       element for convenience
       later when we try
       all possible combinations
       of breaking up the string
  */
  auto r = vector<int>(n + 1);

  l[0] = s[0] - '0';
  r[n - 1] = '1' - s[n - 1];

  for (auto i = 1; i < n; i++)
    /* add one if we need to flip s[i] when it's a '1' */
    l[i] = l[i - 1] + s[i] - '0';
  for (auto i = n - 2; i >= 0; i--)
    r[i] = r[i + 1] + '1' - s[i];

  /*start with the moves required
    to flip the string into all 1's
  */
  auto moves = r[0];

  /* try all the combinations of breaking s
     into two parts and calculate the moves
     required to change it to be monotone
     increaing
  */
  for (auto i = 1; i <= n; i++)
    moves = min(moves, l[i - 1] + r[i]);

  return moves;
}