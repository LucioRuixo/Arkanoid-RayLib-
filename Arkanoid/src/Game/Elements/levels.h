#ifndef LAYOUTS_H
#define LAYOUTS_H

namespace game
{
namespace levels
{
struct Level
{
	int layout[8][10];
};

extern Level levels[3];

void Initialize();
}
}

#endif
