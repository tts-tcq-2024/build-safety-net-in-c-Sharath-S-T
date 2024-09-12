#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, SoundexTests)
{
    char soundex[5];

    // Arrays of inputs and expected outputs
    const char* inputs[] = {
        "Sharath",    // Replaces consonants with appropriate digits
        "aabbccdd",   // Handles repeating same characters
        "",           // Handles empty input string
        "HO1ME",      // Processes alphanumeric string, ignoring non-letters
        "aeiou",      // Handles input with no consonants (only vowels)
        "bbb",        // Handles adjacent consonants that map to the same digit
        "Ashcroft",   // Handles 'h' and 'w' between consonants
        "RoBerT",     // Case-insensitive input handling
        "R",          // Zero-pads result if fewer than 3 digits are generated
        "Jackson",    // Truncates longer names to exactly four characters
        "H3ll0",      // Handles input with non-alphabetic characters
        "Cage"        // Encodes consonants separated by vowels correctly
    };

    const char* expected_outputs[] = {
        "S630",
        "A123",
        "",
        "H500",
        "A000",
        "B100",
        "A261",
        "R163",
        "R000",
        "J250",
        "H400",
        "C200"
    };

    // Loop through the test cases
    for (size_t i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i) {
        generateSoundex(inputs[i], soundex);
        ASSERT_STREQ(soundex, expected_outputs[i]);
    }
}
