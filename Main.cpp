#include "Resource.h"

#include <windows.h>
#include <cstdio>

int main()
{
    HMODULE moduleHandle = GetModuleHandle(nullptr);
    HRSRC resourceInfo = FindResource(moduleHandle, MAKEINTRESOURCE(IDR_SOURCE_CODE), L"TEXT");
    HGLOBAL resourceHandle = LoadResource(moduleHandle, resourceInfo);
    DWORD resourceSize = SizeofResource(moduleHandle, resourceInfo);
    LPVOID resourceData = LockResource(resourceHandle);
    fwrite(resourceData, sizeof(char), resourceSize, stdout);
    FreeResource(resourceHandle);
    return 0;
}