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
 * @param kv: 插入的键值对
 * @return: 0 = insert successfully, -1 = fail to insert(target data doesn't exist)
 */
int PmEHash::insert(kv new_kv_pair) {
    return -1;
}

/**
 * @description: 
 * @param uint64_t: 要删除的目标键值对的键
 * @return: 0 = removing successfully, -1 = fail to remove(target data doesn't exist)
 */
int PmEHash::remove(uint64_t key) {
    return -1;
}
/**
 * @description: 
 * @param kv: 更新的键值对，有原键和新值
 * @return: 0 = update successfully, -1 = fail to update(target data doesn't exist)
 */
int PmEHash::update(kv kv_pair) {
    return -1;
}
/**
 * @description: 
 * @param uint64_t: 查询的目标键
 * @param uint64_t&: 查询成功后返回的目标值
 * @return: 0 = search successfully, -1 = fail to search(target data doesn't exist) 
 */
int PmEHash::search(uint64_t key, uint64_t& return_val) {
    return -1;
}

/**
 * @description: 用于对输入的键产生哈希值，用于后续的取模求桶号操作
 * @param uint64_t: 输入的键
 * @return: 返回键的哈希值
 */
uint64_t PmEHash::hashFunc(uint64_t key) {

}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
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
