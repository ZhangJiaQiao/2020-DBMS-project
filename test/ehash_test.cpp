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
}

TEST(LeafSplitTest, Split) {

}