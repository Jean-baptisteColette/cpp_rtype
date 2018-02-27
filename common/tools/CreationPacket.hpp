#pragma once

// Sent from Server, creates an entiy
struct t_create
{
  char opcode; // Ox01
  int idEntity;
  int typeEntity; // either spacecraft, missile or enemie spacecraft
  int x;
  int y;
  
};
