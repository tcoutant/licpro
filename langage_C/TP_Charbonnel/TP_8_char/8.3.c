#include <stdio.h>
#include <time.h>

int main()
{
  time_t buf ;

  time(&buf) ;
  struct tm *now = localtime(&buf) ;
  printf("%02d:%02d:%02d\n",now->tm_hour,now->tm_min,now->tm_sec) ;

  return 0 ;
}
