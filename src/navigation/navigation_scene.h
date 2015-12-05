#pragma once


#include "engine/iplugin.h"


namespace Lumix
{


class NavigationSystem;
class Path;


class NavigationScene : public IScene
{
public:
	static NavigationScene* createInstance(NavigationSystem& system,
		Universe& universe,
		class IAllocator& allocator);
	static void destroyInstance(NavigationScene* scene);

	virtual float getNavigationAgentRadius(ComponentIndex cmp) = 0;
	virtual void setNavigationAgentRadius(ComponentIndex cmp, float radius) = 0;
};


} // namespace Lumix