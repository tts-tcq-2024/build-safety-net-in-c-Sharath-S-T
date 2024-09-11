#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) 
{
    char soundex[5];

    // Test case: Replaces consonants with appropriate digits
    generateSoundex("Sharath", soundex);
    ASSERT_STREQ(soundex, "S630");

    // Test case: Handles repeating same characters
    generateSoundex("aabbccdd", soundex);
    ASSERT_STREQ(soundex, "A123");

    // Test case: Handles empty input string
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "");

    // Test case: Processes alphanumeric string, ignoring non-letters
    generateSoundex("HO1ME", soundex);
    ASSERT_STREQ(soundex, "H500");

    // Test case: Handles input with no consonants (only vowels)
    generateSoundex("aeiou", soundex);
    ASSERT_STREQ(soundex, "A000");

    // Test case: Handles adjacent consonants that map to the same digit
    generateSoundex("bbb", soundex);
    ASSERT_STREQ(soundex, "B100");

    // Test case: Handles 'h' and 'w' between consonants (treated as adjacent)
    generateSoundex("Ashcroft", soundex);
    ASSERT_STREQ(soundex, "A261");

    // Test case: Case-insensitive input handling
    generateSoundex("RoBerT", soundex);
    ASSERT_STREQ(soundex, "R163");

    // Test case: Zero-pads result if fewer than 3 digits are generated
    generateSoundex("R", soundex);
    ASSERT_STREQ(soundex, "R000");

    // Test case: Truncates longer names to exactly four characters
    generateSoundex("Jackson", soundex);
    ASSERT_STREQ(soundex, "J250");

    // Test case: Handles input with non-alphabetic characters (ignores numbers)
    generateSoundex("H3ll0", soundex);
    ASSERT_STREQ(soundex, "H400");

    // Test case: Encodes consonants separated by vowels correctly
    generateSoundex("Cage", soundex);
    ASSERT_STREQ(soundex, "C200");
}
