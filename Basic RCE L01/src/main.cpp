#include <Windows.h>
#include <iostream>

int main()
{
	// esi - AddressOfEntryPoint
	std::uint32_t esi = 0x401000;

	MessageBoxA(0, "Make me think your HD is CD-Rom", "abex 1st crackme", 0);
	std::uint32_t eax = GetDriveTypeA("c:\\");
	printf("drive type: %d\n", eax);

	esi++;
	eax--;

	esi++;
	esi++;
	eax--;

	if (eax == esi)
	{
		MessageBoxA(0, "Ok, I really think that your HD is a CD-ROM! :p", "YEAH!", MB_OK);
	}

	else
	{
		MessageBoxA(0, "Nah... This is not a CD-ROM Drive!", "Error", MB_OK);
	}

	std::cin.get();
	return 0;
}