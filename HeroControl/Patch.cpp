#include <windows.h>
#include "Patch.h"
#include "Memory.h"

Patch::Patch(char* moduleName, DWORD offset, void* bytes, unsigned int length)
{
    DWORD address = getOffsetAddress(moduleName, offset);
    initialize(address, bytes, length);
}

Patch::Patch(char* moduleName, char* exportName, void* bytes, unsigned int length)
{
    DWORD address = getExportAddress(moduleName, exportName);
    initialize(address, bytes, length);
}

Patch::Patch(DWORD address, void* bytes, unsigned int length)
{
    initialize(address, bytes, length);
}

void Patch::initialize(DWORD address, void* bytes, unsigned int length)
{
    address_ = address;
    bytes_ = bytes;
    length_ = length;

    enabled_ = false;
    enable();
}

Patch::~Patch() 
{ 
    disable(); 
}

void Patch::enable()
{
    if (!enabled_)
    {
        // Save old bytes
        oldBytes_ = new BYTE[length_];
        memcpy_s(oldBytes_, length_, (void*)address_, length_);

        // Patch
        writeBytes(address_, bytes_, length_);
        enabled_ = true;
    }
}

void Patch::disable()
{
    if (enabled_)
    {
        // Restore old bytes
        writeBytes(address_, oldBytes_, length_);
        delete[] oldBytes_;

        enabled_ = false;
    }
}

void Patch::toggle()
{
    if (enabled_)
    {
        disable();
    }
    else
    {
        enable();
    }
}

bool Patch::isEnabled()
{
    return enabled_;
}

DWORD Patch::address()
{
    return address_;
}

unsigned int Patch::length()
{
    return length_;
}

