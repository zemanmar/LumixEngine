#include "navigation_scene.h"
#include "navigation_system.h"
#include "DetourCrowd.h"
#include "core/crc32.h"
#include "core/iallocator.h"
#include "universe/universe.h"


namespace Lumix
{


static const uint32 NAVIGATION_AGENT_HASH = crc32("navigation_agent");
static const int MAX_AGENTS = 4;


struct NavigationAgent
{
	Entity entity;
	ComponentIndex component;
	//dtNavmeshAgent
};

struct NavigationSceneImpl : public NavigationScene
{
	NavigationSceneImpl(NavigationSystem& system, Universe& universe, IAllocator& allocator)
		: m_allocator(allocator)
		, m_universe(universe)
		, m_system(system)
		, m_agents(allocator)
	{
		m_dtCrowd.init(MAX_AGENTS, 1.0f, nullptr);
	}


	~NavigationSceneImpl()
	{

	}


	void update(float time_delta) override
	{
		
	}


	void startGame() override
	{
		
	}


	void stopGame() override
	{
		
	}


	ComponentIndex createNavigationAgent(Entity entity)
	{
		auto& agent = m_agents.pushEmpty();
		agent.entity = entity;
		
		//TODO:
		//agent.dtagent = ...

		m_universe.addComponent(entity, NAVIGATION_AGENT_HASH, this, agent.component);
		return agent.component;
	}

	int getNavigationAgentIdx(ComponentIndex component) const
	{
		for (int i = 0, c = m_agents.size(); i < c; ++i)
		{
			if (m_agents[i].component == component) return i;
		}
		return -1;
	}

	ComponentIndex createComponent(uint32 type, Entity entity) override
	{
		if (type == NAVIGATION_AGENT_HASH)
		{
			return createNavigationAgent(entity);
		}
		return INVALID_COMPONENT;
	}


	void destroyComponent(ComponentIndex component, uint32 type) override
	{
		if (type == NAVIGATION_AGENT_HASH)
		{
			int idx = getNavigationAgentIdx(component);
			auto entity = m_agents[idx].entity;
			m_agents.eraseFast(idx);
			m_universe.destroyComponent(entity, type, this, component);
		}
	}


	void serialize(OutputBlob& serializer) override
	{
		/*serializer.write(m_listener.entity);
		serializer.write(m_clips.size());
		for (auto* clip : m_clips)
		{
			serializer.write(clip != nullptr);
			if (!clip) continue;
			
			serializer.write(clip->looped);
			serializer.writeString(clip->name);
			serializer.writeString(clip->clip->getPath().c_str());
		}

		serializer.write(m_last_ambient_sound_id);
		serializer.write(m_ambient_sounds.size());
		for (auto& i : m_ambient_sounds)
		{
			serializer.write(m_clips.indexOf(i.clip));
			serializer.write(i.component);
			serializer.write(i.entity);
		}*/
	}


	void deserialize(InputBlob& serializer, int) override
	{
		/*clearClips();

		serializer.read(m_listener.entity);
		if (m_listener.entity != INVALID_ENTITY)
		{
			m_universe.addComponent(m_listener.entity, LISTENER_HASH, this, 0);
		}

		int count = 0;
		serializer.read(count);
		m_clips.resize(count);
		for (int i = 0; i < count; ++i)
		{
			bool is_valid;
			serializer.read(is_valid);
			if (!is_valid)
			{
				m_clips[i] = nullptr;
				continue;
			}

			auto* clip = LUMIX_NEW(m_allocator, ClipInfo);
			m_clips[i] = clip;

			serializer.read(clip->looped);
			serializer.readString(clip->name, Lumix::lengthOf(clip->name));
			clip->name_hash = crc32(clip->name);
			char path[MAX_PATH_LENGTH];
			serializer.readString(path, Lumix::lengthOf(path));

			clip->clip = static_cast<Clip*>(m_system.getClipManager().load(Lumix::Path(path)));
		}
		
		serializer.read(m_last_ambient_sound_id);
		serializer.read(count);
		m_ambient_sounds.resize(count);
		for (int i = 0; i < count; ++i)
		{
			auto& sound = m_ambient_sounds[i];

			int clip_idx;
			serializer.read(clip_idx);
			if (clip_idx >= 0) sound.clip = m_clips[clip_idx];
			serializer.read(sound.component);
			serializer.read(sound.entity);

			m_universe.addComponent(sound.entity, AMBIENT_SOUND_HASH, this, sound.component);
		}
		*/
	}


	bool ownComponentType(uint32 type) const override
	{
		return type == NAVIGATION_AGENT_HASH;
	}


	float getNavigationAgentRadius(ComponentIndex cmp) override
	{
		int idx = getNavigationAgentIdx(cmp);
		//return m_agents[idx].
		return 0.5f;
	}


	void setNavigationAgentRadius(ComponentIndex cmp, float radius) override
	{

	}


	Universe& getUniverse() override { return m_universe; }
	IPlugin& getPlugin() const override { return m_system; }

	IAllocator& m_allocator;
	Universe& m_universe;
	NavigationSystem& m_system;

	Array<NavigationAgent> m_agents;
	dtCrowd m_dtCrowd;
};


NavigationScene* NavigationScene::createInstance(NavigationSystem& system,
	Universe& universe,
	IAllocator& allocator)
{
	return LUMIX_NEW(allocator, NavigationSceneImpl)(system, universe, allocator);
}


void NavigationScene::destroyInstance(NavigationScene* scene)
{
	LUMIX_DELETE(static_cast<NavigationSceneImpl*>(scene)->m_allocator, scene);
}


} // namespace Lumix