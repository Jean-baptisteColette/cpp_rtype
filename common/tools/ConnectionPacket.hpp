#pragma once

// Sent from both server and client
struct t_connection
{
  char opcode; //0x0A if client Ox0B if server 
};
