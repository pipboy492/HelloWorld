#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//窗口过程函数

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)

{

static TCHAR szAppName[] = TEXT("MyWindows");//定义窗口类名

HWND hwnd;//窗口句柄

MSG msg; //

WNDCLASS wndclass;  //窗口类

wndclass.style = CS_HREDRAW | CS_VREDRAW;//指定窗口类型，各种“类风格”（详见下方↓）可以使用按位或操作符组合起来

wndclass.lpfnWndProc = WndProc;//指定窗口过程（必须是回调函数）

wndclass.cbClsExtra = 0;//预留的额外空间，一般为 0

wndclass.cbWndExtra = 0;//预留的额外空间，一般为 0

wndclass.hInstance = hInstance;//应用程序的实例句柄

wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//为所有基于该窗口类的窗口设定一个图标

wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//为所有基于该窗口类的窗口设定一个鼠标指针

wndclass.lpszMenuName = NULL;//指定窗口菜单

wndclass.lpszClassName = szAppName;//指定窗口类名

if (!RegisterClass(&wndclass))//注册窗口

{

MessageBox(NULL, TEXT("这个程序需要在 Windows NT 才能执行！"), szAppName, MB_ICONERROR);

return 0;

}

hwnd = CreateWindow(szAppName,      //创建窗口

TEXT("windows"),

WS_OVERLAPPEDWINDOW,

CW_USEDEFAULT,

CW_USEDEFAULT,

CW_USEDEFAULT,

CW_USEDEFAULT,

NULL,

NULL,

hInstance,

NULL);

ShowWindow(hwnd, iCmdShow);  //显示窗口

UpdateWindow(hwnd);      //更新窗口,重绘

while (GetMessage(&msg, NULL, 0, 0)) //获得消息

{

TranslateMessage(&msg);

DispatchMessage(&msg);

}

return msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)//回调函数

{

HDC hdc;

PAINTSTRUCT ps;

RECT rect;

switch (message)

{

case WM_PAINT:

hdc = BeginPaint(hwnd, &ps);

GetClientRect(hwnd, &rect);

DrawText(hdc, TEXT("第一个C语言窗口程序！"), -1, &rect,

DT_SINGLELINE | DT_CENTER | DT_VCENTER);

EndPaint(hwnd, &ps);

return 0;

case WM_DESTROY:

PostQuitMessage(0);

return 0;

}

return DefWindowProc(hwnd, message, wParam, lParam);

}
