//
// Data.hpp for  in /home/beche_f/rendu/cpp/cpp_rtype/common/tools
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Thu Jan 11 16:59:07 2018 beche
// Last update Sat Jan 20 13:43:40 2018 jbcolette
//

#pragma once
#include "ConnectionPacket.hpp"
#include "NewGamePacket.hpp"
#include "CreationPacket.hpp"
#include "MovePacket.hpp"
#include "AttackPacket.hpp"
#include "DiePacket.hpp"
#include "KeyPacket.hpp"
#include "NewGamePacket.hpp"

#define HELLO_FROM_CLIENT 0x0A
#define HELLO_FROM_SERVER 0x0B
#define START_GAME 0x0C
#define KEY_EVENT 0x04
#define CREATE_ENTITY 0x01
#define MOVE_ENTITY 0x02
#define DIE_ENTITY 0x03