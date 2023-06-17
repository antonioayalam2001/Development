#include <Windows.h>
#include <string.h>
int main()
{
char cad[50]="Hola a todo el mundo";
char cad2[50]="Hola a todo el otro mundo";
char cad3[50]="Hola a todo el ultimo mundo";

 // Open a handle to the file
 HANDLE hFile = CreateFile(
 "C:\\Users\\Rodrigo\\Desktop\\pruebas\\text1.txt", // Filename
 GENERIC_WRITE, // Desired access
 FILE_SHARE_READ, // Share mode
 NULL, // Security attributes
 CREATE_NEW, // Creates a new file, only if it doesn't already exist
 FILE_ATTRIBUTE_NORMAL, // Flags and attributes
 NULL); // Template file handle
 if (hFile == INVALID_HANDLE_VALUE)
 {
 // Failed to open/create file
 return 2;
 }
 // Write data to the file
 LPSTR(strText); // For C use LPSTR (char*) or LPWSTR (wchar_t*)
 DWORD bytesWritten;
 WriteFile(
 hFile, // Handle to the file
 cad, // Buffer to write
 strlen(cad), // Buffer size
 &bytesWritten, // Bytes written
 NULL); // Overlapped
 // Close the handle once we don't need it.
 CloseHandle(hFile);

  HANDLE hFilee = CreateFile(
 "C:\\Users\\Rodrigo\\Desktop\\pruebas\\text2.txt", // Filename
 GENERIC_WRITE, // Desired access
 FILE_SHARE_READ, // Share mode
 NULL, // Security attributes
 CREATE_NEW, // Creates a new file, only if it doesn't already exist
 FILE_ATTRIBUTE_NORMAL, // Flags and attributes
 NULL); // Template file handle
 if (hFilee == INVALID_HANDLE_VALUE)
 {
 // Failed to open/create file
 return 2;
 }
 // Write data to the file
 WriteFile(
 hFilee, // Handle to the file
 cad2, // Buffer to write
 strlen(cad2), // Buffer size
 &bytesWritten, // Bytes written
 NULL); // Overlapped
 // Close the handle once we don't need it.
 CloseHandle(hFilee);

 HANDLE hFileee = CreateFile(
 "C:\\Users\\Rodrigo\\Desktop\\pruebas\\text3.txt", // Filename
 GENERIC_WRITE, // Desired access
 FILE_SHARE_READ, // Share mode
 NULL, // Security attributes
 CREATE_NEW, // Creates a new file, only if it doesn't already exist
 FILE_ATTRIBUTE_NORMAL, // Flags and attributes
 NULL); // Template file handle
 if (hFileee == INVALID_HANDLE_VALUE)
 {
 // Failed to open/create file
 return 2;
 }
 // Write data to the file
 WriteFile(
 hFileee, // Handle to the file
 cad3, // Buffer to write
 strlen(cad3), // Buffer size
 &bytesWritten, // Bytes written
 NULL); // Overlapped
 // Close the handle once we don't need it.
 CloseHandle(hFileee);
}