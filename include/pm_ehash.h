#ifndef PM_E_HASH_H
#define PM_E_HASH_H
#include<stdint.h>

#define BUCKET_SLOT_NUM 15
#define DEFAULT_CATALOG_SIZE 16

const char* META_NAME = "pm_ehash_metadata";
const char* CATALOG_NAME = "pm_ehash_catalog";


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
    uint8_t  bitmap[BUCKET_SLOT_NUM / 8 + 1];   // one bit for each slot
    kv       slot[BUCKET_SLOT_NUM];
} pm_bucket;

typedef struct ehash_catalog
{
    pm_address* buckets_pm_address;         // pm address array of buckets
    pm_bucket*  buckets_virtual_address;    // virtual address array mapped by pmem_map
} ehash_metadata;

typedef struct ehash_metadata
{
    uint64_t max_file_id;   // next file id that can be allocated
    uint64_t catalog_size;  // the catalog size of catalog file(amount of data entry)
    uint64_t global_depth;  // global depth of PmEHash
} ehash_metadata;

class PmEHash
{
private:
    
    ehash_metadata* metadata;
    ehash_catalog   catalog;

    uint64_t hashFunc(uint64_t key);

    void splitBucket(uint64_t bucket_id);
    void mergeBucket(uint64_t bucket_id);

    void extendCatalog();
    void* getNewSlot(pm_address& new_address);
    void recover();
    void mapAllPage();

public:
    PmEHash() = delete;
    PmEHash(const char* file_dir_path);
    ~PmEHash();

    int insert(kv new_kv_pair);
    int remove(uint64_t key);
    int update(kv kv_pair);
    int search(uint64_t key, uint64_t& return_val);

};

#endif