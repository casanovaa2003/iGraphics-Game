#include "iGraphics.h"
void drawHomePage();
void drawMenuPage();
void drawGamePage();
int gameState = 0;



int x = 0;
int y = 0;
int screenWidth = 1000;
int screenHeight = 600;

int buttonWidth = 350;
int buttonHeight = 70;
int buttonGap = 20;

int menuStartY;

void iDraw()
{
	iClear();

	if (gameState == 0)
	{
		drawHomePage();
	}
	else if (gameState == 1)
	{
		drawMenuPage();
	}
	else if (gameState == 2)
	{
		drawGamePage();
	}
}


void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

void fixedUpdate()
{
	if (isKeyPressed('w') || isSpecialKeyPressed(GLUT_KEY_UP))
	{
		y++;
	}
	if (isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		x--;
	}
	if (isKeyPressed('s') || isSpecialKeyPressed(GLUT_KEY_DOWN))
	{
		y--;
	}
	if (isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		x++;
	}

	if (isKeyPressed(' ')) {
		// Playing the audio once
		mciSendString("play ggsong from 0", NULL, 0, NULL);
	}
}
void drawHomePage()
{
	iShowBMP2(0, 0, "image\\homepage.bmp", 0);

	iSetColor(255, 255, 255);
	//iText(420, 50, "Press ENTER to Continue", GLUT_BITMAP_HELVETICA_18);
}
void goToMenu()
{
	if (gameState == 0)
		gameState = 1;
}

void drawMenuPage()
{
	iShowBMP2(0, 0, "image\\menu_bg.bmp", 0);

	int centerX = screenWidth / 2 - buttonWidth / 2;

	// Total height of all buttons block
	int totalHeight = 5 * buttonHeight + 4 * buttonGap;

	// Start Y so that whole block is vertically centered
	menuStartY = screenHeight / 2 + totalHeight / 2 - buttonHeight;

	// Draw 5 buttons
	for (int i = 0; i < 5; i++)
	{
		int y = menuStartY - i * (buttonHeight + buttonGap);
		iShowBMP2(centerX, y, "image\\button.bmp", 0);
	}

	// Button Text
	iSetColor(255, 255, 255);

	iText(centerX + 110, menuStartY + 25, "ONE VS ONE", GLUT_BITMAP_HELVETICA_18);
	iText(centerX + 120, menuStartY - (buttonHeight + buttonGap) + 25, "STORY MODE", GLUT_BITMAP_HELVETICA_18);
	iText(centerX + 150, menuStartY - 2 * (buttonHeight + buttonGap) + 25, "SHOP", GLUT_BITMAP_HELVETICA_18);
	iText(centerX + 100, menuStartY - 3 * (buttonHeight + buttonGap) + 25, "PRACTICE MODE", GLUT_BITMAP_HELVETICA_18);
	iText(centerX + 140, menuStartY - 4 * (buttonHeight + buttonGap) + 25, "ABOUT US", GLUT_BITMAP_HELVETICA_18);
}
void drawGamePage()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, screenWidth, screenHeight);

	iSetColor(255, 255, 255);
	iText(450, 300, "GAME STARTED");
}
/*void iKeyboard(unsigned char key)
{
	if (gameState == 0)
	{
		if (key == '\r' || key == '\n')  
		{
			gameState = 1;
		}
	}
}*/



int main()
{
	// Opening/Loading the audio files
	mciSendString("open \"Audios//background.mp3\" alias bgsong", NULL, 0, NULL);
	mciSendString("open \"Audios//gameover.mp3\" alias ggsong", NULL, 0, NULL);

	// Playing the background audio on repeat
	mciSendString("play bgsong repeat", NULL, 0, NULL);

	// If the use of an audio is finished, close it to free memory
	// mciSendString("close bgsong", NULL, 0, NULL);
	// mciSendString("close ggsong", NULL, 0, NULL);

	iSetTimer(4000, goToMenu);
	iInitialize(1000, 600, "Project Title");
	iStart();
	return 0;
}