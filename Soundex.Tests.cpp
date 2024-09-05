#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) 
{
    char soundex[5];

    generateSoundex("Sharath", soundex);
    ASSERT_STREQ(soundex, "S635");

    generateSoundex("aabbccdd", soundex);
    ASSERT_STREQ(soundex, "A130");

    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "");

    generateSoundex("HO1ME", soundex);
    ASSERT_STREQ(soundex, "H050");
}
