#pragma once

// Sent from server to let the client know the game started
struct t_newGame
{
  char opcode; // 0x0C
  int id;
};
