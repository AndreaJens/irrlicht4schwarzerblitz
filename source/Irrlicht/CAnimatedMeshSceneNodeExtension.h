/*
#ifndef __C_ANIMATED_MESH_SCENE_NODE_H_EXTENSION_INCLUDED__
#define __C_ANIMATED_MESH_SCENE_NODE_H_EXTENSION_INCLUDED__

#include "CAnimatedMeshSceneNode.h"


namespace irr
{
	namespace scene
	{
		class CAnimatedMeshSceneNode : public IAnimatedMeshSceneNode{
		public:
			bool addAnimation(core::stringw animationName, CAnimationKeyMap* animationKeys);
			bool canPerformAnimation(core::stringw animationName);
			bool setAnimation(core::stringw animationName);
			bool setAnimationFrameLoop(core::stringw animationName, s32 begin, s32 end);
			core::stringw getCurrentAnimationName();
		private:
			std::map<core::stringw, CAnimationKeyMap*> AnimationMap;
			core::stringw currentAnimationName;
		};
	}
}

#endif
*/