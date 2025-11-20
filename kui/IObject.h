/*
===============================================================================

    IObject

===============================================================================
*/

#pragma once

namespace kui
{

class IObject
{
public:
    IObject() = default;
    virtual ~IObject() = default;

    virtual void Think() {};

private:

};

} // kui
