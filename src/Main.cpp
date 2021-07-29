#include "Main.h"

int main()
{
	while (game.getWindow().isOpen())
	{
		game.update();
		game.draw();
		game.wait();
	}

	return 0;
}
