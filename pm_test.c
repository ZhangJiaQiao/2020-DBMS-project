#include<libpmem.h>
#include<stdint.h>
#include<stdio.h>

typedef struct data
{
    uint64_t v1;
    uint64_t v2;
} data;


int main() {
    size_t map_len;
    int is_pmem;
    data* tdata = pmem_map_file("file", sizeof(data), PMEM_FILE_CREATE, 0777, &map_len, &is_pmem);
    tdata->v1 = 10;
    tdata->v2 = 20;
    pmem_persist(tdata, map_len);
    pmem_unmap(tdata, map_len);

    tdata = pmem_map_file("file", sizeof(data), PMEM_FILE_CREATE, 0777, &map_len, &is_pmem);
    printf("v1: %ln\nv2: %ln\n", &tdata->v1, &tdata->v2);
    pmem_unmap(tdata, map_len);
    return 0;
}