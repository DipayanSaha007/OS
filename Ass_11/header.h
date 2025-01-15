#define BUFFSIZE 1024

typedef struct {
	char data[BUFFSIZE];
	int result, cpid, spid;
}shm_area;

void smem_init(shm_area *smem) {
	smem->result = smem->spid = smem->cpid = -1;
	return;
}
