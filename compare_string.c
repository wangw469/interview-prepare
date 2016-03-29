#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool isStringCharacterAllUnique(const char* string);

typedef struct {
    char string[16];
    bool expected;
} TEST_CONFIG;

static const TEST_CONFIG testConfig[] = {
    { .string = "abcd", .expected = true, },
    { .string = "1234", .expected = true, },
    { .string = "aaaa", .expected = false, },
    { .string = "test", .expected = false, },
};

int main() {
    int testIndex = 0;
    bool bResult = false;
    bool bFinalResult = true;
    const TEST_CONFIG* pConfig = NULL;

    for (testIndex = 0; testIndex < (sizeof(testConfig) / sizeof(TEST_CONFIG)); testIndex++) {
        pConfig = &(testConfig[testIndex]);
        bResult = isStringCharacterAllUnique(pConfig->string);

        if (bResult != pConfig->expected) {
            bFinalResult = false;
            printf("%s != %s\n", pConfig->string, pConfig->expected ? "true" : "false");
        }
    }

    if (bFinalResult == true) {
        printf("PASS");
    }
    else{
        printf("FAIL");
    }

    return 0;
}

//bool isStringCharacterAllUnique(const char* string) {
//    return true;
//}

// simple implementation
bool isStringCharacterAllUnique(const char* string) {
    char* uniqueArray = malloc(sizeof(string));

    int size = 0;
    int index = 0;

    while (string[index] != '\0')
    {
        char value = string[index];
        int i = 0;

        for (i = 0; i < size; i++) {
            if (uniqueArray[i] == value) {
                free(uniqueArray);
                uniqueArray = NULL;
                return false;
            }
        }

        uniqueArray[size] = value;

        size++;
        index++;
    }

    free(uniqueArray);
    uniqueArray = NULL;

    return true;
}

