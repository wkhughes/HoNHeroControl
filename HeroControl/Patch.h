#pragma once

#include <windows.h>

class Patch
{
public:
    Patch() {};
    Patch(char* moduleName, DWORD offset, void* bytes, unsigned int length);
    Patch(char* moduleName, char* exportName, void* bytes, unsigned int length);
    Patch(DWORD address, void* bytes, unsigned int length);
    virtual ~Patch();

    void enable();
    void disable();
    void toggle();
    bool isEnabled();
    DWORD address();
    unsigned int length();

protected:
    DWORD address_;
    void* bytes_;
    unsigned int length_;
    void* oldBytes_;
    bool enabled_;

    void initialize(DWORD address, void* bytes, unsigned int length);
};