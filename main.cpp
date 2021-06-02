#include "game.hpp"
/** \brief the main class is just handling the basics of starting and closing the game
 * it would be giving the message of failure to intialize in case the compiler is unable to intialize the game 
 */ 
int main(int argc, char *argv[]){
    Game game;
    srand(time(0));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
    if( !game.loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }

    game.run();
    game.close();

    return 0;
}