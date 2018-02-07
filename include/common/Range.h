/*
 * File: libRange.h
 * -------------
 * This interface exports the libRange utility functions to work with range values.
 */
#ifndef _LIBRANGE_H_
#define _LIBRANGE_H_

namespace Ppa {
namespace Common {

/* Usage: range<int>(min, max)::contains(i)
 *        range<int>(min, max)::notContains(i)
 *        range<int>(min, max) //iterator
 * -------------
 * Template to check if type is is in range.
 */
template <typename T>
  class Range 
  {
  private:
  
    class iter {
      private:
        T m_x;
      
      public:
        iter(T x) : m_x(x) { }

        void operator++() { m_x++; }

        const T& operator*() const { return m_x; }

        bool operator!=(const iter &other) const {
          return m_x != other.m_x;
        }
      };

      T m_begin;
      T m_end;

  public:
    
    range(T min, T max) : m_begin(min), m_end(max) { }

    bool contains(int i) { 
      return m_begin <= i && m_end >= i;
    }
     
    bool notContains(int i) {
      return m_begin > i && m_end < i;
    }
   
    iter begin() const { return iter(m_begin); }
    iter end()   const { return iter(m_end  ); }
  
  };

} // namespace Common end
} // namespace Ppa end

#endif /* _LIBRANGE_H_ */
