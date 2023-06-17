WaitForSingleObject(pi1.hProcess,INFINITE);

    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);