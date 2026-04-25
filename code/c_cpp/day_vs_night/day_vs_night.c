#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>

const char g_szClassName[] = "myWindowClass";

#define GRID_SIZE 25
#define CELL_SIZE 20
#define CIRCLE_RADIUS 12
#define IDI_MYICON 101

// white = 0
// black = 1
int grid[GRID_SIZE][GRID_SIZE];

// randomize
float RandomFloat() {
    return (float)rand() / RAND_MAX;
}

// circle positions & velocities
float leftCircleX = 6.25f, leftCircleY = 12.5f;
float leftVelX = 0.8f, leftVelY = -0.8f;
float rightCircleX = 18.75f, rightCircleY = 12.5f;
float rightVelX = -0.8f, rightVelY = 0.8f;

void InitializeGrid() {
    // i want the balls to be the same speed when the program starts
    float speed = 0.8f;
    
    // creates random angles for each circle using pi
    float pi = 3.14159f;
    float leftAngle = RandomFloat() * 2 * pi; 
    float rightAngle = RandomFloat() * 2 * pi;
    
    // calc velocities w same speed but different directions
    leftVelX = cos(leftAngle) * speed;
    leftVelY = sin(leftAngle) * speed;
    rightVelX = cos(rightAngle) * speed;
    rightVelY = sin(rightAngle) * speed;
    
    // create the grid
    int middleColumn = GRID_SIZE / 2;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // LEFT
            if (j < middleColumn) {
                grid[i][j] = 0; // white = 0
            // MIDDLE - half white, half black
            } else if (j == middleColumn) {
                if (i < GRID_SIZE / 2) {
                    grid[i][j] = 0; // top half = white (0)
                } else {
                    grid[i][j] = 1; // bottom half = black (1)
                }
            // RIGHT
            } else {
                grid[i][j] = 1; // black = 1
            }
        }
    }
}

void UpdateCircles() {
    // THIS IS FOR THE LEFT HALF (WHITE CIRCLE)
    leftCircleX += leftVelX;
    leftCircleY += leftVelY;
    
    // handles the wall bounces
    if (leftCircleX <= 1 || leftCircleX >= GRID_SIZE - 1) {
        leftVelX = -leftVelX;

        // this stuff makes sure the balls stay in bounds
        if (leftCircleX <= 1) leftCircleX = 1;
        if (leftCircleX >= GRID_SIZE - 1) leftCircleX = GRID_SIZE - 1;
        
        // everytime the balls bounce it changes the angle a bit
        // bcs otherwise the balls would draw an identical path
        float speed = sqrt(leftVelX * leftVelX + leftVelY * leftVelY);
        float angle = atan2(leftVelY, leftVelX) + (RandomFloat() - 0.5f) * 0.5f;
        leftVelX = cos(angle) * speed;
        leftVelY = sin(angle) * speed;
    }
    if (leftCircleY <= 1 || leftCircleY >= GRID_SIZE - 1) {
        leftVelY = -leftVelY;

        if (leftCircleY <= 1) leftCircleY = 1;
        if (leftCircleY >= GRID_SIZE - 1) leftCircleY = GRID_SIZE - 1;
        
        float speed = sqrt(leftVelX * leftVelX + leftVelY * leftVelY);
        float angle = atan2(leftVelY, leftVelX) + (RandomFloat() - 0.5f) * 0.5f;
        leftVelX = cos(angle) * speed;
        leftVelY = sin(angle) * speed;
    }
    
    // checks collision with grid cells
    int gridX = (int)leftCircleX;
    int gridY = (int)leftCircleY;
    if (gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE) {
        if (grid[gridY][gridX] == 1) { // if a black cell is hit...
            grid[gridY][gridX] = 0; // turn it white

            // same angle change code
            float speed = sqrt(leftVelX * leftVelX + leftVelY * leftVelY);
            float angle = atan2(-leftVelY, -leftVelX) + (RandomFloat() - 0.5f) * 0.8f;
            leftVelX = cos(angle) * speed;
            leftVelY = sin(angle) * speed;
        }
    }
    // END LEFT HALF
    
    // THIS IS FOR THE RIGHT HALF (BLACK CIRCLE)
    rightCircleX += rightVelX;
    rightCircleY += rightVelY;
    
    // handles the wall bounces
    if (rightCircleX <= 1 || rightCircleX >= GRID_SIZE - 1) {
        rightVelX = -rightVelX;
        // this stuff makes sure the balls stay in bounds
        if (rightCircleX <= 1) rightCircleX = 1;
        if (rightCircleX >= GRID_SIZE - 1) rightCircleX = GRID_SIZE - 1;
        
        // everytime the balls bounce it changes the angle a bit
        // bcs otherwise the balls would draw an identical path
        float speed = sqrt(rightVelX * rightVelX + rightVelY * rightVelY);
        float angle = atan2(rightVelY, rightVelX) + (RandomFloat() - 0.5f) * 0.5f;
        rightVelX = cos(angle) * speed;
        rightVelY = sin(angle) * speed;
    }
    if (rightCircleY <= 1 || rightCircleY >= GRID_SIZE - 1) {
        rightVelY = -rightVelY;
       
        if (rightCircleY <= 1) rightCircleY = 1;
        if (rightCircleY >= GRID_SIZE - 1) rightCircleY = GRID_SIZE - 1;
        
        float speed = sqrt(rightVelX * rightVelX + rightVelY * rightVelY);
        float angle = atan2(rightVelY, rightVelX) + (RandomFloat() - 0.5f) * 0.5f;
        rightVelX = cos(angle) * speed;
        rightVelY = sin(angle) * speed;
    }
    
    // checks collision with grid cells
    gridX = (int)rightCircleX;
    gridY = (int)rightCircleY;
    if (gridX >= 0 && gridX < GRID_SIZE && gridY >= 0 && gridY < GRID_SIZE) {
        if (grid[gridY][gridX] == 0) { // if a white cell is hit...
            grid[gridY][gridX] = 1; // turn it black
            
            // same angle change code
            float speed = sqrt(rightVelX * rightVelX + rightVelY * rightVelY);
            float angle = atan2(-rightVelY, -rightVelX) + (RandomFloat() - 0.5f) * 0.8f;
            rightVelX = cos(angle) * speed;
            rightVelY = sin(angle) * speed;
        }
    }
    // END RIGHT HALF
}

// counts the squares for the counters at the bottom of the program
void CountSquares(int* dayCount, int* nightCount) {
    *dayCount = 0;
    *nightCount = 0;
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                (*dayCount)++;
            } else {
                (*nightCount)++;
            }
        }
    }
}

// window handling code
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CREATE:
            InitializeGrid();
            SetTimer(hwnd, 1, 25, NULL); // i put 25 bcs it feels best (higher = slower)
            break;
            
        case WM_TIMER:
            UpdateCircles();
            InvalidateRect(hwnd, NULL, FALSE);
            break;
            
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // draw ze grid
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                    HBRUSH brush;
                    if (grid[i][j] == 0) {
                        brush = CreateSolidBrush(RGB(234, 226, 183)); // dawn color
                    } else {
                        brush = CreateSolidBrush(RGB(13, 35, 43)); // dusk color
                    }
                    
                    RECT cellRect = {
                        j * CELL_SIZE,
                        i * CELL_SIZE,
                        (j + 1) * CELL_SIZE,
                        (i + 1) * CELL_SIZE
                    };
                    
                    FillRect(hdc, &cellRect, brush);
                    DeleteObject(brush);
                }
            }
            
            // drawing left circle (black)
            HBRUSH whiteBrush = CreateSolidBrush(RGB(13, 35, 43));
            HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(13, 35, 43));
            SelectObject(hdc, whiteBrush);
            SelectObject(hdc, blackPen);
            Ellipse(hdc, 
                (int)(leftCircleX * CELL_SIZE - CIRCLE_RADIUS),
                (int)(leftCircleY * CELL_SIZE - CIRCLE_RADIUS),
                (int)(leftCircleX * CELL_SIZE + CIRCLE_RADIUS),
                (int)(leftCircleY * CELL_SIZE + CIRCLE_RADIUS));
            DeleteObject(whiteBrush);
            DeleteObject(blackPen);
            
            // drawing right circle (white)
            HBRUSH blackBrush = CreateSolidBrush(RGB(234, 226, 183));
            HPEN whitePen = CreatePen(PS_SOLID, 2, RGB(234, 226, 183));
            SelectObject(hdc, blackBrush);
            SelectObject(hdc, whitePen);
            Ellipse(hdc,
                (int)(rightCircleX * CELL_SIZE - CIRCLE_RADIUS),
                (int)(rightCircleY * CELL_SIZE - CIRCLE_RADIUS),
                (int)(rightCircleX * CELL_SIZE + CIRCLE_RADIUS),
                (int)(rightCircleY * CELL_SIZE + CIRCLE_RADIUS));
            DeleteObject(blackBrush);
            DeleteObject(whitePen);

            // square counting and text display
            int dayCount, nightCount;
            CountSquares(&dayCount, &nightCount);

            // white background for text replacement
            HBRUSH textBgBrush = CreateSolidBrush(RGB(255, 255, 255));
            RECT textBgRect = {0, GRID_SIZE * CELL_SIZE, 520, GRID_SIZE * CELL_SIZE + 40};
            FillRect(hdc, &textBgRect, textBgBrush);
            DeleteObject(textBgBrush);

            // text properties
            SetTextColor(hdc, RGB(0, 0, 0));
            SetBkMode(hdc, TRANSPARENT);

            // font stuffs
            HFONT hFont = CreateFont(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, 
                                    DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                    DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Consolas");
            HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

            // text strings
            char dayText[50], nightText[50];
            sprintf(dayText, "dawn: %d", dayCount);
            sprintf(nightText, "dusk: %d", nightCount);

            // draw text
            int textY = GRID_SIZE * CELL_SIZE + 10;
            TextOut(hdc, 90, textY, dayText, strlen(dayText));
            TextOut(hdc, 325, textY, nightText, strlen(nightText));

            // cleanup
            SelectObject(hdc, hOldFont);
            DeleteObject(hFont);
            
            EndPaint(hwnd, &ps);
        }
        break;
        
        case WM_CLOSE:
            KillTimer(hwnd, 1);
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    srand((unsigned int)(time(NULL) + clock()));
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    // this is the window class setup
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON)); // icons, change in resources.rc file
    wc.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));    
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(32, 32, 32));
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // creating window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "dawn vs dusk",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 520, 580,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON)); 
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // some stuff (i have no idea what this is but dont delete it)
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}