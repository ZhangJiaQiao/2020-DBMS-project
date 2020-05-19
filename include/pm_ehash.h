#ifndef PM_E_HASH_H
#define PM_E_HASH_H
#include<cstdint>
#include<queue>
#include<map>
#include"data_page.h"

#define BUCKET_SLOT_NUM 15
#define DEFAULT_CATALOG_SIZE 16

using namespace std;

const char* META_NAME = "pm_ehash_metadata";
const char* CATALOG_NAME = "pm_ehash_catalog";
const char* PM_EHASH_DIRECTORY = "";        // add your own directory path to store the pm_ehash


/* 
---the physical address of data in NVM---
fileId: 1-N, the data page name
offset: data offset in the file
*/
typedef struct pm_address
{
    uint32_t fileId;
    uint32_t offset;
} pm_address;

/*
the data entry stored by the hash
*/
typedef struct kv
{
    uint64_t key;
    uint64_t value;
} kv;

typedef struct pm_bucket
{
    uint64_t local_depth;
    uint8_t  bitmap[BUCKET_SLOT_NUM / 8 + 1];      // one bit for each slot
    kv       slot[BUCKET_SLOT_NUM];                                // one slot for one kv-pair
} pm_bucket;

typedef struct ehash_catalog
{
    pm_address* buckets_pm_address;         // pm address array of buckets
    pm_bucket*  buckets_virtual_address;    // virtual address array mapped by pmem_map
} ehash_catalog;

typedef struct ehash_metadata
{
    uint64_t max_file_id;   // next file id that can be allocated
    uint64_t catalog_size;  // the catalog size of catalog file(amount of data entry)
    uint64_t global_depth;  // global depth of PmEHash
} ehash_metadata;

class PmEHash
{
private:
    
    ehash_metadata* metadata;       // virtual address of metadata, mapping the metadata file
    ehash_catalog   catalog;        // the catalog of hash

    queue<pm_bucket*> free_slot;        //all free slots in data pages to store buckets
    map<pm_bucket*, pm_address> vAddr2pmAddr;       // virtual address map to pm_address, used to find specific pm_address

    uint64_t hashFunc(uint64_t key);

    pm_bucket* getFreeBucket(uint64_t key);
    kv* getFreeKvSlot(pm_bucket* bucket);

    void splitBucket(uint64_t bucket_id);
    void mergeBucket(uint64_t bucket_id);

    void extendCatalog();
    void* getNewSlot(pm_address& new_address);
    void allocNewPage();

    void recover();
    void mapAllPage();

public:
    PmEHash();
    ~PmEHash();

    int insert(kv new_kv_pair);
    int remove(uint64_t key);
    int update(kv kv_pair);
    int search(uint64_t key, uint64_t& return_val);

};

#endif