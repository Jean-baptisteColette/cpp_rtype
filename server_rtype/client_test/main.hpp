//
// main.hpp for  in /home/beche_f/rendu/cpp/poc/udp
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Thu Jan 11 12:23:08 2018 beche
// Last update Thu Jan 11 16:57:59 2018 beche
//

#pragma once

typedef struct s_packet
{
  char opcode;
  int value;
}               t_packet;


namespace Data{
  
  template<typename T>
  void unserialise(char *buf, T &data)
  {
    memcpy(&data, buf, sizeof(T));
  }
  
  template<typename T>
  void serialise(T &data, char *buf)
  {
    memcpy((void*)buf, (void*)&data, sizeof(T));
  }
}
