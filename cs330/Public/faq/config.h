// config.h
#ifndef CONFIG_H
#define CONFIG_H

// for compilers that support namespaces:
#define USING_STD  using namespace std;
#define STD        std::
//   (We assume by default that compilers do support namespaces, 
//   just because this should be increasingly true as time goes by.)


#ifdef __GNUG__
  /* Compiler is gcc/g++ - does not yet support namespaces */

  #undef USING_STD
  #undef STD
  #define USING_STD
  #define STD

#endif

/***********************************************************/
/*      integer portability                                */
/***********************************************************/

#ifdef __GNUG__
  /* Compiler is gcc/g++ */
  typedef short int16;
  typedef unsigned short uint16;
  typedef int int32;
  typedef unsigned int uint32;
#elif defined(_MSC_VER)
  /* compiler is Microsoft Visual C++ */
  typedef int int16;
  typedef unsigned int uint16;
  typedef long int32;
  typedef unsigned long uint32;
#elif defined(_Unix)
  /* compiler is some unknown Unix compiler - take a guess */
  typedef short int16;
  typedef unsigned short uint16;
  typedef int int32;
  typedef unsigned int uint32;
#else
  /* compiler is some unknown non-Unix compiler  - take a guess */
  typedef int int16;
  typedef unsigned int uint16;
  typedef long int32;
  typedef unsigned long uint32;
#endif

#endif
