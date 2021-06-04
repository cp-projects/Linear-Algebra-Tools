#ifndef HEADER_FILE
#define HEADER_FILE





#if defined(_LP64)
typedef int unknownNum_t;
#elif
typedef unsigned unknownNum_t;
#elif
typedef float unknownNum_t
#elif
typedef double unknownNum_t;
#else
typedef long unknownNum_t;
#endif


unknownNum_t test(unknownNum_t input)
{



return input;
}
























#endif
