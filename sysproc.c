#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getChildren(void)
{
  return getChildren();
}

int
sys_changePolicy(void)
{
  return changePolicy();
}

int
sys_waitChild(void){
  struct timevars *times;
  argptr (0 , (void*)&times ,sizeof(*times));
  return waitChild(times);
}

int
sys_getRuntime(void){
  return getRuntime();
}

int
sys_getRuntimeofchild(void){
    int *pid;
    argptr (0 , (void*)&pid ,sizeof(int *));
    return getRuntimeofchild(pid);
}

int
sys_checkalive(void){
  int *pid;
  argptr (0 , (void*)&pid ,sizeof(int *));
  return checkalive(pid);
}

int
sys_setpro(void){
  int *pro;
  argptr (0 , (void*)&pro ,sizeof(int *));
  return setpro(pro);
}