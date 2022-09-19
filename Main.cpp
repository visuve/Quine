#include "Resource.h"

#include <windows.h>

int main()
{
    HMODULE moduleHandle = GetModuleHandle(nullptr);
    HRSRC resourceInfo = FindResource(moduleHandle, MAKEINTRESOURCE(IDR_SOURCE_CODE), L"TEXT");
    HGLOBAL resourceHandle = LoadResource(moduleHandle, resourceInfo);
    DWORD resourceSize = SizeofResource(moduleHandle, resourceInfo);
    LPVOID resourceData = LockResource(resourceHandle);
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsoleA(consoleHandle, resourceData, resourceSize, nullptr, nullptr);
    FreeResource(resourceHandle);
    return 0;
}