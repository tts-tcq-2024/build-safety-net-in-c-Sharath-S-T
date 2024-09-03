#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) 
{
    static const char code[] = {'0','1','2','3','0','1','2','0','0','2','2','4','5','5','0','1','2','6','2','3','0','1','0','2','0','2'};
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return code[c - 'A'];
    }
    return '0';
}

void end(char *soundex, int *sIndex)
{
    while (*sIndex < 4) 
    {
        soundex[(*sIndex)++] = '0';
    }
}

void initialize(const char *name, char *soundex)
{
    if (name[0] == '\0')
    {
        soundex[0] = '\0';
        return;
    }
    else
    {
        soundex[0] = toupper(name[0]);
    }
}

void process(const char *name, char *soundex, int len, int *sIndex)
{
    for (int i = 1; i < len && *sIndex < 4; i++) 
    {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[*sIndex - 1]) 
        {
            soundex[(*sIndex)++] = code;
        }
    }
}

void generateSoundex(const char *name, char *soundex) 
{
    int sIndex = 1;
    int len = strlen(name);
    initialize(name, soundex);
    process(name, soundex, len, &sIndex);
    end(soundex, &sIndex);

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
