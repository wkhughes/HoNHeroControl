#include <windows.h>

DWORD getOffsetAddress(char* moduleName, unsigned int offset)
{
    DWORD address = 0;
    HMODULE moduleHandle;
    
    moduleHandle = GetModuleHandle(moduleName);

    if (moduleHandle == NULL) // Load module if not loaded already
    {
        moduleHandle = LoadLibrary(moduleName);
    }

    if (moduleHandle != NULL)
    {
        address = (DWORD)moduleHandle + offset;
    }

    return address;
}

DWORD getExportAddress(char* moduleName, char* exportName)
{
    DWORD address = 0;
    HMODULE moduleHandle = GetModuleHandle(moduleName);

    if (moduleHandle == NULL) // Load module if not loaded already
    {
        moduleHandle = LoadLibrary(moduleName);
    }

    if (moduleHandle != NULL)
    {
        address = (DWORD)GetProcAddress(moduleHandle, exportName);
    }

    return address;
}

bool writeBytes(DWORD address, void* bytes, unsigned int length)
{
    BOOL hasProtectionChanged;
    DWORD oldProtection;

    hasProtectionChanged = VirtualProtect((void*)address, length, PAGE_READWRITE, &oldProtection);

    if (hasProtectionChanged == FALSE)
    {
        return FALSE;
    }

    memcpy_s((void*)address, length, bytes, length);
    return VirtualProtect((void*)address, length, oldProtection, &oldProtection) == TRUE;
}