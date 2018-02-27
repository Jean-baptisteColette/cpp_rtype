#pragma once

// Sent from server, kills an entity
struct t_die
{
  char opcode; // OX03
  int idPlayer;
  
};
