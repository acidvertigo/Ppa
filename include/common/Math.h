
#include <cmath>

using namespace std;

/*
 * int math
 */

/*
 * floating point math
 * Usage: floatEquals<float>(1.00f, 1.00f, 2f)
 */
template <typename T>
bool floatEquals(T left, T right, T epsilon) {
  return (fabs(left - right) < epsilon);
}

template <typename T, typename U>
U floatLess(T left, T right, T epsilon, U orequal = false) {
  if (fabs(left - right) < epsilon) {
    return (orequal);
  }
  return (left < right);
}

template <typename T, typename U>
U floatGreater(T left, T right, T epsilon, U orequal = false) {
  if (fabs(left - right) < epsilon) {
    return (orequal);
  }
  return (left > right);
}

