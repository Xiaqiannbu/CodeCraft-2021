#ifndef INCLUDE_COMPUTE
#define INCLUDE_COMPUTE

#ifndef INCLUDE_STRING
#include <string>
#endif // !INCLUDE_STRING

#ifndef INCLUDE_UNORDERED_MAP
#include <unordered_map>
#endif // !INCLUDE_UNORDERED_MAP

#ifndef INCLUDE_VECTOR
#include <vector>
#endif // !INCLUDE_VECTOR

using namespace std;

class ComputeNum
{
public:
	unordered_map<string, int> buyServerNum();
};



#endif // !INCLUDE_COMPUTE
