#include"data_page.h"
#include"pm_ehash.h"

/**
 * @description: construct a new instance of PmEHash in a specific directory
 * @param {const char*} the path of file directory
 * @return: new instance of PmEHash
 */
PmEHash::PmEHash(const char* file_dir_path) {

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

}

/**
 * @description: 
 * @param {type} 
 * @return: 0 = removing successfully, -1 = fail to remove(target data doesn't exist)
 */
int PmEHash::remove(uint64_t key) {

}
/**
 * @description: 
 * @param {type} 
 * @return: 0 = update successfully, -1 = fail to update(target data doesn't exist)
 */
int PmEHash::update(kv kv_pair) {

}
/**
 * @description: 
 * @param {type} 
 * @return: 0 = search successfully, -1 = fail to search(target data doesn't exist) 
 */
int PmEHash::search(uint64_t key, uint64_t& return_val) {
    
}