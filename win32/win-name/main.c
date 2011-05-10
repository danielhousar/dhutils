/***************************************************************
 * file:	win32/win-name/main.c
 ***************************************************************/

#include <windows.h>
#define IDB_MENO 1001
#define IDB_KONIEC 1002

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */

LPCSTR szClassName = TEXT("WindowsApp");
LPCSTR szWinName = TEXT("WindowsApp");

HWND hEdit,ButtonMeno,ButtonKoniec;


int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_WINDOWFRAME;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           szWinName,       	/* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           250,                 /* The programs width */
           120,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hDC;
	char retazec[256];
	LPCWSTR text2 = TEXT("Put your name:");

/* handle the messages */
    switch (message) {
		case WM_COMMAND:
			switch(LOWORD(wParam)) {	//kontroluje hodnotu wParam - obsahuje id prvku
				case IDB_MENO:
                    GetWindowText(hEdit, retazec, 255);
					MessageBox(hwnd, retazec, TEXT("Your Name is:"), MB_OK);
					break;
				case IDB_KONIEC:
					if(MessageBox(hwnd, TEXT("Are you sure?"), TEXT("Close?"), MB_ICONQUESTION | MB_YESNO)==IDYES)
					PostQuitMessage (0);
					break;
			}
			break;
		case WM_CREATE:
			hEdit = CreateWindowEx(0, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 120,10,100,18,hwnd,NULL, NULL,NULL);
			ButtonMeno = CreateWindowEx( 0, TEXT("BUTTON"), TEXT("What is my name?"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 20,35,95,20,hwnd,(HMENU)IDB_MENO, NULL,NULL);    //ako hodnota manipulatora menu sa da dcerskym oknam predat ich id
			ButtonKoniec = CreateWindowEx(0, TEXT("BUTTON"), TEXT("Exit"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , 125,35,95,20,hwnd,(HMENU)IDB_KONIEC, NULL,NULL);
			break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
			break;
        case WM_PAINT:
			hDC = BeginPaint(hwnd,&ps);
			TextOut(hDC, 20, 10, text2, 14);
			EndPaint(hwnd,&ps);
			break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
