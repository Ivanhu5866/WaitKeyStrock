/*
 *  Copyright(C) 2019 Canonical Ltd.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 *  USA.
 */

#include <efi.h>
#include <efilib.h>


EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_INPUT_KEY eik;
	EFI_STATUS efi_status;

	InitializeLib(ImageHandle, SystemTable);

	Print(L"Test key stroke application started\n");

	while (1) {
		WaitForSingleEvent(ST->ConIn->WaitForKey, 0);
		efi_status = uefi_call_wrapper(ST->ConIn->ReadKeyStroke, 2, ST->ConIn, &eik);
		Print(L"ScanCode: %lxh  UnicodeChar: %lxh CallRtStatus: %lx\n",
		eik.ScanCode, eik.UnicodeChar, efi_status);
	}

	return EFI_SUCCESS;
}
