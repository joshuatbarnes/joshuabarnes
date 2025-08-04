#include <windows.h>
#include <stdio.h>

// (Your ReadDeveloperToolsPolicy function goes here)
#define POLICY_KEY TEXT("Software\\Policies\\Microsoft\\Edge")

DWORD ReadDeveloperToolsPolicy(DWORD dwDefault)
{
    HKEY hKey;
    LONG lResult;
    DWORD dwValue;
    DWORD dwSize = sizeof(dwValue);
    const TCHAR* lpValueName = TEXT("DeveloperToolsAvailability");
 
    lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, POLICY_KEY, 0, KEY_READ, &hKey);
 
    if (lResult == ERROR_SUCCESS)
    {
        lResult = RegQueryValueEx(hKey, lpValueName, 0, NULL, (LPBYTE)&dwValue, &dwSize);
        RegCloseKey(hKey);
 
        if (lResult == ERROR_SUCCESS)
        {
            return dwValue;
        }
    }
    return dwDefault;
}


int main()
{
    // 1. Call the function to get the current policy value.
    // We'll use a default of 0 (allow) if the policy isn't set.
    DWORD policyValue = ReadDeveloperToolsPolicy(0);

    printf("Querying registry for DeveloperToolsAvailability...\n");

    // 2. Use an 'if' statement to check if the value is 2.
    if (policyValue == 2)
    {
        printf("Result: The policy is set to 2 (Allow for extensions).\n");
    }
    else
    {
        printf("Result: The policy is not set to 2. Current value: %lu\n", policyValue);
    }

    return 0;
}