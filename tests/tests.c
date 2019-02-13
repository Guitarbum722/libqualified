#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../qualified.h"
#include "unity/unity.h"

struct table_test {
    char* name;
    char* expected;
};

/**
 * test_strqsep validates that the proper tokens
 * are returned.
 */
void
test_strqsep_comma_no_qual(void)
{
    static struct table_test table_tests[] = {
        { .name = "first", .expected = "Don" },
        { .name = "second", .expected = "K" },
        { .name = "third", .expected = "Moby" },
        { .name = "fourth", .expected = "don.moby@nothing.com" },

    };
    char *got, *input, *original;
    original = input = strdup("Don,K,Moby,don.moby@nothing.com");

    for (int i = 0; i < sizeof(table_tests) / sizeof(struct table_test); i++) {
        got = strqsep(&input, ",", "");
        TEST_ASSERT_EQUAL_STRING(table_tests[i].expected, got);
    }

    free(original);
}

void
test_strqsep_comma_with_qual(void)
{
    static struct table_test table_tests[] = {
        { .name = "first", .expected = "\"Don,,,\"" },
        { .name = "second", .expected = "K" },
        { .name = "third", .expected = "\"Moby, M.D.\"" },
        { .name = "fourth", .expected = "don.moby@nothing.com" },

    };
    char *got, *input, *original;
    original = input = strdup("\"Don,,,\",K,\"Moby, M.D.\",don.moby@nothing.com");

    for (int i = 0; i < sizeof(table_tests) / sizeof(struct table_test); i++) {
        got = strqsep(&input, ",", "\"");
        TEST_ASSERT_EQUAL_STRING(table_tests[i].expected, got);
    }

    free(original);
}

void
test_strqsep_pipe_delim_single_quote_qual(void)
{
    static struct table_test table_tests[] = {
        { .name = "first", .expected = "Johnny" },
        { .name = "second", .expected = "',|, '" },
        { .name = "third", .expected = "Topics" },
        { .name = "fourth", .expected = "'Look|at|me'" },
    };
    char *got, *input, *original;
    original = input = strdup("Johnny|',|, '|Topics|'Look|at|me'");

    for (int i = 0; i < sizeof(table_tests) / sizeof(struct table_test); i++) {
        got = strqsep(&input, "|", "'");
        TEST_ASSERT_EQUAL_STRING(table_tests[i].expected, got);
    }

    free(original);
}

void
test_strqsep_null_input(void)
{
    char *got, *input, *original;
    original = input = strdup("");

    got = strqsep(&input, ",", "");
    TEST_ASSERT_EQUAL_STRING(NULL, got);

    free(original);
}

void
test_strqsep_empty_input(void)
{
    char *got, *field;

    got = strqsep(NULL, "", "");
    TEST_ASSERT_EQUAL_STRING(NULL, got);

}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_strqsep_comma_no_qual);
  RUN_TEST(test_strqsep_comma_with_qual);
  RUN_TEST(test_strqsep_pipe_delim_single_quote_qual);
  RUN_TEST(test_strqsep_null_input);
  RUN_TEST(test_strqsep_empty_input);

  return UNITY_END();
}
