#include "Action.hpp"
#include "Data.hpp"

Action::Action(Socket &s, std::shared_ptr<EntityContainer> e) : _socket(s), _entityContainer(e)
{
}

Action::~Action()
{
}

void Action::ActionOnKey(const eAction &action)
{
    _inc++;
    if ((_inc % 100) == 50)
    {

    t_key k;
    k.opcode = 0x04;
    k.key = action;
    k.Playerid = this->_entityContainer->getMyId();
    if (_socket.sendPacket(&k, sizeof(struct t_key)) != true)
    {
        std::cout << "fail send\n";
    }
    std::cout << "move\n";
    _inc = 0;
    }
}
