/*
 * File: libRange.h
 * -------------
 * This interface exports the libRange utility functions to work with range values.
 */
#ifndef _LIBRANGE_H_
#define _LIBRANGE_H_

/* Usage: range<int>(min, max)::contains(i)
 *        range<int>(min, max)::notContains(i)
 *        range<int>(min, max) //iterator
 * -------------
 * Template to check if type is is in range.
 */
template <typename T>
  class range 
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

    static bool contains(int i) { 
      return min <= i && i max >= i;
    }
     
    static bool notContains(int i) {
      return min > i && max < i;
    }
   
    iter begin() const { return iter(m_begin); }
    iter end()   const { return iter(m_end  ); }
  
  };

#endif /* _LIBRANGE_H_ */