#ifndef _NIMA_ACTORCOMPONENT_HPP_
#define _NIMA_ACTORCOMPONENT_HPP_

#include <string>
#include <vector>
#include <nima/Mat2D.hpp>
#include <nima/Vec2D.hpp>

namespace nima
{
	class Actor;
	class ActorNode;
	class BlockReader;

	enum class ComponentType
	{
		ActorNode = 2,
		ActorBone = 3,
		ActorRootBone = 4,
		ActorImage = 5,
		ActorIKTarget = 11
	};


	class ActorComponent
	{
		protected:
			ComponentType m_Type;
			std::string m_Name;
			ActorNode* m_Parent;
			Actor* m_Actor;

		private:
			unsigned short m_ParentIdx;
			unsigned short m_Idx;
			
		protected:
			ActorComponent(Actor* actor, ComponentType type);

		public:
			virtual ~ActorComponent();
			Actor* actor() const;
			const std::string& name() const;
			ComponentType type() const;

			ActorNode* parent() const;
			unsigned short parentIdx() const;
			unsigned short idx() const;
			virtual void resolveComponentIndices(ActorComponent** components);
			virtual ActorComponent* makeInstance(Actor* resetActor) = 0;
			void copy(ActorComponent* node, Actor* resetActor);
			virtual bool isNode() { return false; }

			static ActorComponent* read(Actor* actor, BlockReader* reader, ActorComponent* component = NULL);
	};
}
#endif