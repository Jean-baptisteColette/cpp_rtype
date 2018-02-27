#include <iostream>
#include "Room.hpp"
#include <thread>
#include <mutex>
#include <algorithm>
#include <memory>
#include "Data.hpp"
#include "Game.hpp"
#include "Entity.hpp"

std::mutex mymutex;


Room::Room(int id, std::vector<Client> listClient, Socket &s) : _socket(s)
{
    this->_id = id;
    for (unsigned int i = 0; i < listClient.size(); ++i)
    {
        listClient[i].getPlayer().setPosY(listClient[i].getPlayer().getPosY() * (i + 1));
        listClient[i].getPlayer().setId(listClient[i].getPlayer().getId() + i);
        this->_client.push_back(listClient[i]);
        std::cout << "Client[" << listClient[i].getPlayer().getId() << "] posY = " << listClient[i].getPlayer().getPosY() << std::endl;
    }
    std::cout << "New Room[" << this->getId() << "] create" << std::endl;
}

Room::~Room()
{
    std::cout << "ROOM delete " << std::endl;
    // this->_threadM.joinThread();
}

int Room::getId()
{
    return this->_id;
}

void Room::setId(int val)
{
    this->_id = val;
}

void Room::deleteClientToRoom(Client client)
{
    /*
    ** Parcourir le std::vector<Client>
    ** Trouver le Client en question
    ** Le delete de la Room
    */
}
std::shared_ptr<std::thread> Room::spawnThread()
{
    std::shared_ptr<std::thread> t = std::make_shared<std::thread>([this]() {

        std::cout << "thread lancé\n";
        std::chrono::milliseconds Interval(200);

        t_newGame ng;
        int i = 1;
        for (Client &c : this->_client)
        {
            ng.opcode = 0x0C;
            ng.id = i;
            this->_socket.setDest(c.getIp());

            if (this->_socket.sendPacket(&ng, sizeof(t_newGame)) == true)
            {
                std::cout << "startGame sent (0x0C)" << std::endl;
            }
            else
            {
                std::cout << "fail send\n";
            }
            i++;
        }

        std::vector<Entity> objects;

        objects.push_back(Entity(1, 1, 200, 90));
        objects.push_back(Entity(2, 1, 200, 270));
        objects.push_back(Entity(3, 1, 200, 450));
        objects.push_back(Entity(4, 1, 200, 630));
        int nbEnemies = 5;
        int nbMisile = 10;
        while (true)
        {
          //set the val catch the commands
          int idmsg = 0; // Id of client either 1 or 2 or 3 or 4
          int Movement = 0; // Movement
          // Receive the packet here and set the above values
          //Do the mutex here
          std::lock_guard<std::mutex> guard(mymutex);
          if (_instruction.size() != 0)
          {
            struct t_key *msgEvent = reinterpret_cast<struct t_key *>((char *)_instruction.at(0));
            idmsg = msgEvent->Playerid;
            Movement = msgEvent->key;
          //Remove the parsed msg
            _instruction.erase(_instruction.begin());
          std::cout << "i Received the msg correctly from " << idmsg << " key : " << Movement << std::endl;
          }
          // Missile client
          if (Movement == 5)
          {
            for (Entity &tmp : objects)
            {
              if (idmsg == tmp.getId())
                objects.push_back(Entity(objects.size() + 1, 2, tmp.getX(), tmp.getY() + 200));
            }
          }
          //create Enemies if there are less than 3 enemies
          while(nbEnemies < 8)
          {
            objects.push_back(Entity(objects.size() + 1, 3, 800, 75 * nbEnemies));
            nbEnemies++;
          }

          // Update the client and check if there is a need of creating new Entity
          for (Entity &tmp : objects)
          {
            if (tmp.getCreated() == 0)
            {
              t_create start;
              for (Client &c : this->_client)
              {
                  start.opcode = 0x01;
                  start.idEntity = tmp.getId();
                  start.typeEntity = tmp.getType();
                  start.x = tmp.getX();
                  start.y = tmp.getY();
                  this->_socket.setDest(c.getIp());
                  if (this->_socket.sendPacket(&start, sizeof(t_create)) == true)
                    std::cout << "newEntity sent (0x01)" << std::endl;
                  else
                    std::cout << "fail send\n";
              }
              tmp.setCreated(1);
              std::cout << "Created = " << tmp.getCreated() << " 0X01 " << tmp.getId() << " " << tmp.getX() << " " << tmp.getY() << std::endl;
            }
          }

          //Moves objects
          for (Entity &tmp : objects)
          {
              if (tmp.getType() == 1 && tmp.getId() == idmsg)
              {
                tmp.moveEntity(Movement);
              }
              else
              {
                tmp.moveEntity(0);
              }
              if (tmp.getCreated() == 1)
              {
                t_move move;
                for (Client &c : this->_client)
                {
                  move.opcode = 0x02;
                  move.idEntity = tmp.getId();
                  move.x = tmp.getX();
                  move.y = tmp.getY();
                  this->_socket.setDest(c.getIp());
                  if (this->_socket.sendPacket(&move, sizeof(t_move)) == true)
                    std::cout << "MoveEntity sent (0x02)" << std::endl;
                  else
                    std::cout << "fail send\n";
                  }
              std::cout << " 0X02 " << tmp.getId() << " " << tmp.getX() << " " << tmp.getY() << std::endl;
            }
          }

          // Kill Objects out of range or colliding
          for (Entity &it : objects)
          {
            if (it.ColisionCheck(objects) == 1)
            {
              // Kill Entity
              if (it.getCreated() == 1)
                {
              t_die die;
              for (Client &c : this->_client)
              {
                  die.opcode = 0x03;
                  die.idPlayer = it.getId();
                  this->_socket.setDest(c.getIp());
                  if (this->_socket.sendPacket(&die, sizeof(t_die)) == true)
                  {
                      std::cout << "RemoveEntity sent (0x03)" << std::endl;
                  }
                  else
                  {
                      std::cout << "fail send\n";
                  }
              }
              std::cout << " 0x03 " << it.getId() << std::endl;
              if (it.getType() == 3)
              {
                nbEnemies--;
              }
              // RemoveEntity from Server
              int end = 0;
              for(std::vector<Entity>::iterator jetest = objects.begin(); jetest!= objects.end() && end != 1; ++jetest)
              {
                  if (jetest->getId() == it.getId())
                  {
                    objects.erase(jetest);
                    end = 1;
                  }
              }
              std::cout << "I managed to RemoveEntity properly but im still in the loop" << std::endl;
            }
            }
          }
          std::cout << "I passed everything onced without segfaulting" << std::endl;
     //     std::this_thread::sleep_for(Interval);

          std::cout << "size instruction : " << this->_instruction.size() << std::endl;
        }
    });
    return t;
}

void Room::stopRoom()
{
    /*
    **  Voir si cet fonction est utile
    */
}

void Room::pushInstruction(char* msg)
{
    this->_instruction.push_back(msg);
}

bool Room::isClient(const struct sockaddr_in &client)
{
    for (Client &value : this->_client)
    {
        if (value.getIp().sin_port == client.sin_port && value.getIp().sin_family == client.sin_family)
            return true;
    }
    return false;
}
