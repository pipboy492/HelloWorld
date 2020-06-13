#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//���ڹ��̺���

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)

{

static TCHAR szAppName[] = TEXT("MyWindows");//���崰������

HWND hwnd;//���ھ��

MSG msg; //

WNDCLASS wndclass;  //������

wndclass.style = CS_HREDRAW | CS_VREDRAW;//ָ���������ͣ����֡����񡱣�����·���������ʹ�ð�λ��������������

wndclass.lpfnWndProc = WndProc;//ָ�����ڹ��̣������ǻص�������

wndclass.cbClsExtra = 0;//Ԥ���Ķ���ռ䣬һ��Ϊ 0

wndclass.cbWndExtra = 0;//Ԥ���Ķ���ռ䣬һ��Ϊ 0

wndclass.hInstance = hInstance;//Ӧ�ó����ʵ�����

wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//Ϊ���л��ڸô�����Ĵ����趨һ��ͼ��

wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ϊ���л��ڸô�����Ĵ����趨һ�����ָ��

wndclass.lpszMenuName = NULL;//ָ�����ڲ˵�

wndclass.lpszClassName = szAppName;//ָ����������

if (!RegisterClass(&wndclass))//ע�ᴰ��

{

MessageBox(NULL, TEXT("���������Ҫ�� Windows NT ����ִ�У�"), szAppName, MB_ICONERROR);

return 0;

}

hwnd = CreateWindow(szAppName,      //��������

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

ShowWindow(hwnd, iCmdShow);  //��ʾ����

UpdateWindow(hwnd);      //���´���,�ػ�

while (GetMessage(&msg, NULL, 0, 0)) //�����Ϣ

{

TranslateMessage(&msg);

DispatchMessage(&msg);

}

return msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)//�ص�����

{

HDC hdc;

PAINTSTRUCT ps;

RECT rect;

switch (message)

{

case WM_PAINT:

hdc = BeginPaint(hwnd, &ps);

GetClientRect(hwnd, &rect);

DrawText(hdc, TEXT("��һ��C���Դ��ڳ���"), -1, &rect,

DT_SINGLELINE | DT_CENTER | DT_VCENTER);

EndPaint(hwnd, &ps);

return 0;

case WM_DESTROY:

PostQuitMessage(0);

return 0;

}

return DefWindowProc(hwnd, message, wParam, lParam);

}
