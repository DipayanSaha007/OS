#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "buffer.h"
#include "psem.h"

#define  SHMKEY		1234
#define  DELAY		1000000	  
#define  MAXITERATION	30

int
main (void)
{
  int shmid, smem_size, i;
  unsigned y = 0;
  buffer *sbuf = NULL;
  psem_t mutex;
  psem_t empty, full;

  smem_size = sizeof (buffer);
  shmid = shmget (SHMKEY, smem_size, 0666 | IPC_CREAT);		
  if (shmid == -1)
    {
      perror ("shmget");
      return 1;
    }

  sbuf = (buffer *) shmat (shmid, NULL, 0);		
  if (!psem_init (&mutex, "MUTEX", -1))
    return 2;
  if (!psem_init (&empty, "EMPTY", -1))
    return 2;
  if (!psem_init (&full, "FULL", -1))
    return 2;

  i = MAXITERATION;				
  while (i--)
    {
      psem_wait(&full);
      psem_wait (&mutex);
      if (buf_delete (sbuf, &y))
	     printf ("\n  Consumed => %d\n", y);
      else
	     puts ("Buffer EMPTY\n");
      psem_post (&mutex);
      psem_post(&empty);
      usleep (DELAY*2);
    }

  psem_destroy (&mutex);
  psem_destroy (&empty);
  psem_destroy (&full);
  buf_destroy (sbuf);
  shmdt ((void *) sbuf);
  shmctl (shmid, IPC_RMID, 0);
  return 0;
}

