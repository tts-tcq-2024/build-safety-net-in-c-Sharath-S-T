#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) 
{
    static const char code[] = {'0','1','2','3','0','1','2','0','0','2','2','4','5','5','0','1','2','6','2','3','0','1','0','2','0','2'};
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? code[c - 'A'] : '0';
}

void processChar(char code, char *soundex, int *sIndex) 
{
    if (code != '0' && code != soundex[*sIndex - 1]) 
    {
        soundex[(*sIndex)++] = code;
    }
}

void initializeSoundex(char firstChar, char *soundex, int *sIndex)
{
    soundex[0] = toupper(firstChar);
    *sIndex = 1;
}

void processRemainingChars(const char *name, char *soundex, int len, int *sIndex)
{
    for (int i = 1; i < len && *sIndex < 4; i++) 
    {
        char code = getSoundexCode(name[i]);
        processChar(code, soundex, sIndex);
    }
}

void padSoundex(char *soundex, int *sIndex)
{
    while (*sIndex < 4) 
    {
        soundex[(*sIndex)++] = '0';
    }
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) 
{
    if (name[0] == '\0')
    {
        soundex[0] = '\0';
        return;
    }
    
    int sIndex;
    int len = strlen(name);

    initializeSoundex(name[0], soundex, &sIndex);
    processRemainingChars(name, soundex, len, &sIndex);
    padSoundex(soundex, &sIndex);
}

#endif // SOUNDEX_H
