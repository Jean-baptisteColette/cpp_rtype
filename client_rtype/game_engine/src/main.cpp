// Use this main to test the game engine

#include <memory>
#include "World.hpp"

int     main()
{
    std::shared_ptr<World> r_type = std::make_shared<World>();
    r_type->createWindow();
    r_type->createSpacecrafts("Focon", 1, 50, 50, 400, 5);
    r_type->getSpacecraft()->setEntity();
    while (r_type->getWindow()->isOpen() == true)
    {
        r_type->windowEvents();
        r_type->spacecraftEvents();
        r_type->draw();
        r_type->setDisplay();
        // win->scrollView(0.1f, 0.1f);
    }
    return (0);
}


//_____________________ THIS IS THE GAME ENGINE TEST!!!!
