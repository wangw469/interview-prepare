#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

const int MAX_STRING_LEN = 32;

typedef bool (*UNIQUE_CHECK_FUN)(const char*string);

bool simpleImplement(const char* string);
bool hashImplement(const char* string);

typedef struct {
    char string[MAX_STRING_LEN];
    bool expected;
} TEST_CONFIG;

static const TEST_CONFIG testConfig[] = {
    { .string = "abcd", .expected = true, },
    { .string = "1234", .expected = true, },
    { .string = "aaaa", .expected = false, },
    { .string = "test", .expected = false, },
};

int main() {
    int indexTest = 0;
    bool bResult = false;
    bool bFinalResult = true;
    const TEST_CONFIG* pConfig = NULL;

    UNIQUE_CHECK_FUN checkFunc = simpleImplement;

    for (indexTest = 0; indexTest < (sizeof(testConfig) / sizeof(TEST_CONFIG)); indexTest++) {
        pConfig = &(testConfig[indexTest]);
        bResult = checkFunc(pConfig->string);

        if (bResult != pConfig->expected) {
            bFinalResult = false;
            printf("%s != %s\n", pConfig->string, pConfig->expected ? "true" : "false");
        }
    }

    if (bFinalResult == true) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    return 0;
}

static char uniqueArray[MAX_STRING_LEN];

// simple implementation
bool simpleImplement(const char* string) {
    int indexUnique = 0;
    int indexString = 0;

    if (string == NULL)
        return true;

    while (string[indexString] != '\0')
    {
        char value = string[indexString];
        int i = 0;

        for (i = 0; i < indexUnique; i++) {
            if (uniqueArray[i] == value) {
                return false;
            }
        }

        uniqueArray[indexUnique] = value;

        indexUnique++;
        indexString++;
    }

    return true;
}

// hash table implement
bool hashImplement(const char* string) {
    return false;
}
