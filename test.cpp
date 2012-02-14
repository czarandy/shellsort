#include "shellsort.h"

#include <iostream>
#include <vector>
#include <sys/time.h>

double time(std::function<void()> f) {
}

int main()
{
  // Generate random vector
  std::vector<int> v(1000000);
  for (auto& i : v) {
    i = rand();
  }
  std::vector<int> w(v);

  auto time = [](std::function<void()> f) {
    timeval start, stop, result;
    gettimeofday(&start, NULL);
    f();
    gettimeofday(&stop, NULL);
    timersub(&stop, &start, &result);
    return result.tv_sec * 1000000.0 + result.tv_usec;
  };

  auto test = [&](const char* type) {
    std::cout << "Testing " << type << " array" << std::endl;
    double shell_time = time([&v](){ algorithm::shell_sort(v.begin(), v.end()); });
    double std_time = time([&w](){ std::sort(w.begin(), w.end()); });

    for (int i = 0; i < v.size(); ++i) {
      if (v[i] != w[i]) {
        std::cout << "Mismatch at position " << i << std::endl;
      }
    }
    std::cout << "Shell time: " << shell_time << std::endl;
    std::cout << "Std sort time: " << std_time << std::endl;
  };

  test("random");
  test("sorted");
}
