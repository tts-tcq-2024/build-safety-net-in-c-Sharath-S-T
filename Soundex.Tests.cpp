#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) 
{
    char soundex[5];

    generateSoundex("Sharath", soundex);
    ASSERT_STREQ(soundex, "S630");

    generateSoundex("aabbccdd", soundex);
    ASSERT_STREQ(soundex, "A123");

    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "");

    generateSoundex("HO1ME", soundex);
    ASSERT_STREQ(soundex, "H500");
}
