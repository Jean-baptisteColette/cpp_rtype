#pragma once

#include <vector>

class Entity
{
private:
  int _id;
  int _type;
  int _x;
  int _y;
  int _height;
  int _width;
  int _created;

public:
  // Constructor
  Entity(int id, int type, int x, int y)
  {
    this->_id = id;
    this->_type = type;
    this->_x = x;
    this->_y = y;
    switch (_type) {
      case 1 :
      _width = 400;
      _height = 50;
      break;
      case 2 :
      _width = 50;
      _height = 5;
      break;
      case 3 :
      _width = 400;
      _height = 50;
      break;
      default:
      break;
    }
    _created = 0;
  };
  //Destructor
  ~Entity()
  {

  };
  int moveEntity(int Movement)
  {
    if (_type == 1)
    {
      switch (Movement)
      {
        //UP
        case 1:
        _y -= 30;
        break;
        //DOWN
        case 2:
        _y += 30;
        break;
        // RIGHT
        case 3:
        _x -= 30;
        break;
        // LEFT
        case 4:
        _x += 30;
        break;
      }
    }
    else if (_type == 2)
    {
      _x += 5;
    }
    else
    {
      _x -= 5;
    }
    return (0);
  };

//Getters
  int getId()
  {
    return (_id);
  };

  int getType()
  {
    return (_type);
  };

  int getX()
  {
    return (_x);
  };

  int getY()
  {
    return (_y);
  };

  int getCreated()
  {
    return (_created);
  };

  int getHeight()
  {
    return (_height);
  };

  int getWidth()
  {
    return (_width);
  };

  //Setters
  void setId(int id)
  {
    _id = id;
  };

  void setType(int type)
  {
    _type = type;
  };

  void setX(int x)
  {
    _x = x;
  };

  void setY(int y)
  {
    _y = y;
  };

  void setCreated(int created)
  {
    _created = created;
  };

  void setHeight(int height)
  {
    _height = height;
  };

  void setWidth (int width)
  {
    _width = width;
  };

int ColisionCheck(std::vector<Entity> objects)
{
  for(Entity &it : objects)
    {
      if (it.getId() != _id)
	     {
	        if ((it.getX() <= _x && (it.getX() + it.getWidth()) >= _x && it.getY() <= _y
	       && (it.getY() + it.getHeight()) >= _y)
	      || (it.getX() <= _x + _width && (it.getX() + it.getWidth()) >= _x + _width
		  && it.getY() <= _y && (it.getY() + it.getHeight()) >= _y)
	      || (it.getX() <= _x && (it.getX() + it.getWidth()) >= _x && it.getY() <= _y + _height
		   && (it.getY() + it.getHeight()) >= _y + _height)
		  || (it.getX() <= _x + _width && (it.getX() + it.getWidth()) >= _x + _width
		       && it.getY() <= _y + _height && (it.getY() + it.getHeight()) >= _y + _height))
		  return (1);
		  }
	      }
        if(_x <= 0 || _x + _width >= 1200 || _y <= 0 || _y + _height >= 700 )
          return (1);
	  return (0);
	};

    };
