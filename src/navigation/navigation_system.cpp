#include "navigation_system.h"
#include "navigation_scene.h"

#include "core/resource_manager.h"
#include "engine/engine.h"
#include "engine/iplugin.h"


namespace Lumix
{


	struct NavigationSystemImpl : public NavigationSystem
	{
		NavigationSystemImpl(Engine& engine)
		: m_engine(engine)
		{
		}


		bool create() override
		{
			return true;
		}


		void destroy() override
		{

		}


		const char* getName() const override { return "navigation"; }


		IScene* createScene(UniverseContext& ctx)
		{
			return NavigationScene::createInstance(*this, *ctx.m_universe, m_engine.getAllocator());
		}


		void destroyScene(IScene* scene) { NavigationScene::destroyInstance(static_cast<NavigationScene*>(scene)); }


		Engine& m_engine;
	};


} // namespace Lumix


extern "C" LUMIX_LIBRARY_EXPORT Lumix::IPlugin* createPlugin(Lumix::Engine& engine)
{
	return LUMIX_NEW(engine.getAllocator(), Lumix::NavigationSystemImpl)(engine);
}
