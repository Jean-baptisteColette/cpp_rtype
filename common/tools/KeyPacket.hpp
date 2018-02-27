#pragma once

// Sent from client

struct t_key
{
  char opcode; // 0x04
  int Playerid;
  int key; // either 0(Nothing), 1(Up), 2(Down), 3(Left), 4(Right), 5 (Space)

};
