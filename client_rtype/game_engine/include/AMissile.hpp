#pragma once

#include "AEntity.hpp"

enum eMissile
{
    BASIC,
    LASER
};

class AMissile : public AEntity
{
  public:
    virtual ~AMissile(){}

    virtual void setTypeMissile(eMissile value) { _type = value;}
    virtual eMissile getTypeMissile() const & {return _type;}

  protected:
    eMissile _type;
};