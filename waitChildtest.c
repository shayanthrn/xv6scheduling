#include "types.h"
#include "stat.h"
#include "user.h"

struct timevars {
  int creation_time;           //  {    
  int running_time;            //
  int sleep_time;              //       time variables!
  int waiting_time;            //
  int termination_time;        //  }
};
 
int
main(void)
{
  struct timevars s;
  waitChild(&s);
  printf(1,"%d",s.waiting_time);
  //printf(1,"hellooooooo %d %d %d %d %d",s.creation_time,s.running_time,s.sleep_time,s.termination_time,s.waiting_time);
  exit();
}