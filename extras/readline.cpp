// Standard C++ includes
#include <iostream>
#include <string>
#include <queue>
// Standard C includes
// None
// Library includes
// None
// Project includes
// None

extern "C"
{
#include <readline/readline.h>
#include <readline/history.h>
}

using namespace::std;

static queue<string> inqueue;

void mock_readline_add(const string& _str)
{
  inqueue.push(_str);
}

char* readline(const char* prompt)
{
  static string result;

  if ( ! inqueue.size() )
  {
    cout << prompt << endl;
    return NULL;
  }
  else
  {
    result = inqueue.front();
    cout << prompt << result << endl;
    inqueue.pop();
    return const_cast<char*>(result.c_str());
  }
}

#if MAC
extern "C" int add_history(const char*)
{
  return 0;
}
#else
extern "C" void add_history(const char*)
{
}
#endif
// vim:cin:ai:sts=2 sw=2 ft=cpp
