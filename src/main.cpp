#include "core/Game.h"
#include "utils/Logger.h"

int main(int argc, char* argv[]) {
    Game game;

    Logger::info("Dang khoi tao game...");
    if (!game.init()) {
        Logger::error("Kich hoat game that bai");
        return -1;
    }
    Logger::info("Khoi tao thanh cong man hinh game...");
    game.run();
    Logger::info("Game da dong an toan.");
    return 0;
}