#include"pm_ehash.h"

/**
 * @description: construct a new instance of PmEHash in a default directory
 * @param NULL
 * @return: new instance of PmEHash
 */
PmEHash::PmEHash() {

}
/**
 * @description: persist and munmap all data in NVM
 * @param NULL 
 * @return: NULL
 */
PmEHash::~PmEHash() {

}

/**
 * @description: 
 * @param {type} 
 * @return: 0 = insert successfully, -1 = fail to insert(target data doesn't exist)
 */
int PmEHash::insert(kv new_kv_pair) {
    return -1;
}

/**
 * @description: 
 * @param {type} 
 * @return: 0 = removing successfully, -1 = fail to remove(target data doesn't exist)
 */
int PmEHash::remove(uint64_t key) {
    return -1;
}
/**
 * @description: 
 * @param {type} 
 * @return: 0 = update successfully, -1 = fail to update(target data doesn't exist)
 */
int PmEHash::update(kv kv_pair) {
    return -1;
}
/**
 * @description: 
 * @param {type} 
 * @return: 0 = search successfully, -1 = fail to search(target data doesn't exist) 
 */
int PmEHash::search(uint64_t key, uint64_t& return_val) {
    return -1;
}

uint64_t PmEHash::hashFunc(uint64_t key) {

}

pm_bucket* PmEHash::getFreeBucket(uint64_t key) {

}

kv* PmEHash::getFreeKvSlot(pm_bucket* bucket) {

}

void PmEHash::splitBucket(uint64_t bucket_id) {

}

void PmEHash::mergeBucket(uint64_t bucket_id) {
    
}

void PmEHash::extendCatalog() {

}

void* PmEHash::getNewSlot(pm_address& new_address) {

}

void PmEHash::allocNewPage() {

}

void PmEHash::recover() {

}

void PmEHash::mapAllPage() {

}
