#include "gtest/gtest.h"
#include "pm_ehash.h"
#include <iostream>
#include <string>

using namespace std;

TEST(InsertTest, SingleInsert) {
    PmEHash* ehash = new PmEHash;
    kv temp;
    temp.key = temp.value = 1;
    int result = ehash->insert(temp);
    GTEST_ASSERT_EQ(result, 0);
    uint64_t val;
    result = ehash->search(1, val);
    GTEST_ASSERT_EQ(result, 0);
    GTEST_ASSERT_EQ(val, 1);
    result = ehash->search(0, val);
    GTEST_ASSERT_EQ(result, -1);
    ehash->selfDestory();
}

TEST(InsertTest, DuplicateInsert) {
    PmEHash* ehash = new PmEHash;
    kv temp;
    temp.key = temp.value = 1;
    int result = ehash->insert(temp);
    GTEST_ASSERT_EQ(result, 0);
    result = ehash->insert(temp);
    GTEST_ASSERT_EQ(result, -1);
    ehash->selfDestory();
}

TEST(UpdateTest, SingleUpdate) {
    PmEHash* ehash = new PmEHash;
    kv temp;
    temp.key = temp.value = 1;
    int result = ehash->insert(temp);
    GTEST_ASSERT_EQ(result, 0);
    temp.value = 2;
    result = ehash->update(temp);
    GTEST_ASSERT_EQ(result, 0);
    temp.key = 2;
    result = ehash->update(temp);
    GTEST_ASSERT_EQ(result, -1);
    ehash->selfDestory();
}

TEST(SearchTest, SingleSearch) {
    PmEHash* ehash = new PmEHash;
    kv temp;
    temp.key = temp.value = 1;
    int result = ehash->insert(temp);
    uint64_t val = 0;
    result = ehash->search(1, val);
    GTEST_ASSERT_EQ(result, 0);
    GTEST_ASSERT_EQ(val, 1);
}

TEST(RemoveTest, SingleRemove) {
    PmEHash* ehash = new PmEHash;
    kv temp;
    temp.key = temp.value = 1;
    int result = ehash->insert(temp);
    GTEST_ASSERT_EQ(result, 0);
    temp.key = temp.value = 2;
    result = ehash->insert(temp);
    GTEST_ASSERT_EQ(result, 0);
    result = ehash->remove(1);
    GTEST_ASSERT_EQ(result, 0);
    result = ehash->remove(1);
    GTEST_ASSERT_EQ(result, -1);
    uint64_t val = 0;
    result = ehash->search(1, val);
    GTEST_ASSERT_EQ(result, -1);
    GTEST_ASSERT_EQ(val, 1);
    ehash->selfDestory();
}