#pragma once

#include <windows.h>
#pragma execution_character_set("utf-8")

#define IMPORT __declspec(dllimport)

typedef void (*KeyboardHandler)(DWORD, WORD, BYTE, BOOL, BOOL, BOOL, BOOL);

IMPORT void keyboardHandlerRegister(KeyboardHandler handler);

IMPORT void keyboardHandlerUnregister(KeyboardHandler handler);

IMPORT void scriptWait(DWORD time);
IMPORT void scriptRegister(HMODULE module, void (*LP_SCRIPT_MAIN)());
IMPORT void scriptRegisterAdditionalThread(HMODULE module, void (*LP_SCRIPT_MAIN)());
IMPORT void scriptUnregister(HMODULE module);

IMPORT void nativeInit(UINT64 hash);
IMPORT void nativePush64(UINT64 val);
IMPORT PUINT64 nativeCall();

static void WAIT(DWORD time) { scriptWait(time); }

IMPORT UINT64 *getGlobalPtr(int globalId);

IMPORT void *getCommandFromHash(UINT64 hash);

// Drawing

/*
	Make sure to call these functions every frame if you want to render something on the screen!
	The coordiantes behave the same as in other Rockstar Games titles. x=0.5, y=0.5 is center of the screen on any resolution.
	Width and Height: 0.2 is 20% width of your screen, same goes for height
	There are some default fonts that are already embedded into ScriptHook, you can look them up in the enums.h file!
*/
IMPORT void drawRect(float x, float y, float width, float height, int r, int g, int b, int a, float rounding);
IMPORT void drawText(float x, float y, const char *text, int r, int g, int b, int a, int fontId, float fontSize, int justification);
IMPORT void drawSprite(float x, float y, float width, float height, int spriteId, float rotation, int r, int g, int b, int a);

/*
	IMPORTANT: Only call this function once, at the beginning of your script!
	This function accepts a path to a .ttf file, make sure to check the fontSize before registering it. Usually you always want to pass sizePixels=72.0f
	RETURNS: fontId to use in drawText.
*/
IMPORT int registerFont(const char *filename, float sizePixels);
/*
	IMPORTANT: Only call this function once, at the beginning of your script!
	This function accepts a path to any image format (.png, .jpg, .jpeg, ...)
	RETURNS: if successfull it returns the spriteId to use in drawSprite.
*/
IMPORT int registerSprite(const char *filepath);