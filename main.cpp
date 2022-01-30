#include <Windows.h>

HWND find_window() {
    HWND hwnd_host = nullptr;
    HWND hwnd_ret = nullptr;

    int count = 0;

    while ((hwnd_host = FindWindowEx(nullptr, hwnd_host, "NativeHWNDHost", "")) != nullptr) {
        if (FindWindowEx(hwnd_host, nullptr, "DirectUIHWND", "") != nullptr) {
            if (count == 0) {
                hwnd_ret = hwnd_host;
            }

            count++;

            if (count > 1)
                return nullptr;

        }
    }
    return hwnd_ret;
}

int main() {
    HWND volume_window = find_window();

    WINDOWPLACEMENT wd;
    GetWindowPlacement(volume_window, &wd);

    if (wd.showCmd == SW_SHOWMINIMIZED)
        ShowWindow(volume_window, SW_RESTORE);
    else
        ShowWindow(volume_window, SW_MINIMIZE);

    return 0;
}
