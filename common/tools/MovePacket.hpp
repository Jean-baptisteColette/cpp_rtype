#pragma once

// Sent from Server, moves an Entity
struct t_move
{
  char opcode; //0X02
  int idEntity;
  int x;
  int y;

};
