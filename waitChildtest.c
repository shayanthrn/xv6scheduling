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
  int pid1=0,pid2=0,pid3=0;
  struct timevars t1,t2,t3;
  pid1=fork();
  changePolicy();
  if(pid1==0){
      //child
      int i=0;
      for(i=0;i<100000;i++){
        i=i;
      }
      exit();
  }
  else{
      pid2=fork();
      if(pid2==0){
          //child
          int i=0;
      for(i=0;i<100000;i++){
        i=i;
      }
          exit();
      }
      else{
          pid3=fork();
          if(pid3==0){
              //child
              while(1){
                printf(1,"%d",getRuntime());
              }
              exit();
          }
          else{
              waitChild(&t1);
              waitChild(&t2);
              waitChild(&t3);
              printf(1,"prcoess n1 : %d %d %d %d %d\nprcoess n2 : %d %d %d %d %d\nprcoess n3 : %d %d %d %d %d\n",t1.creation_time,t1.running_time,t1.sleep_time,t1.termination_time,t1.waiting_time,t2.creation_time,t2.running_time,t2.sleep_time,t2.termination_time,t2.waiting_time,t3.creation_time,t3.running_time,t3.sleep_time,t3.termination_time,t3.waiting_time);
              exit();
          }
      }
    }
}