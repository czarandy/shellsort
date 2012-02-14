#pragma once

#include <algorithm>
#include <array>

namespace algorithm {

template<class RandomIt>
void shell_sort(RandomIt start, RandomIt end) {

  /**
   * Shell sort increments. These determine the running time, although no set
   * of the best increments is known, these seem to be good in practice, see:
   *   http://oeis.org/A102549
   */

  std::array<int, 15> inc{
    227057,
    100913,
    44851,
    19933,
    8859,
    3937,
    1750,
    701,
    301,
    132,
    57,
    23,
    10,
    4,
    1,
  };

  for (const auto i : inc) {
    for (RandomIt j = start; j != start + i; ++j) {
      // Perform insertion sort on this subarray
      for (RandomIt k = j + i; k < end; k += i) {
        RandomIt l = k;
        RandomIt l_prev = l - i;
        while (l_prev >= start && *l < *l_prev) {
          std::iter_swap(l, l_prev);
          l -= i;
          l_prev -= i;
        }
      }
    }
  }
}

}
