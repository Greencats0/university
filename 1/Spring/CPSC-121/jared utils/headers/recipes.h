// this is a header file I hope to use in future projects to make my life easier
// examples may be taken from the interwebs and modified a bit but code using these will be unique
// some functions may be GNU G++ compliant only due to different people writing different C++ compiliers, can't control that YO!

// you do not actually need to declare the size of an array as const int, only if you need a specific amount that does not change
// this function calculates the size of the array by using sizeof(array) and dividing it by the pointer of the size of the array
// http://zubplot.blogspot.com/2015/01/gcc-is-wonderful-better-arraysize-macro.html
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

#define CHECK_OS
  #ifdef _WIN32


// https://www.youtube.com/watch?v=kdAiCZQVuvI
//#define REMOVE_DUPLICATES(array)
