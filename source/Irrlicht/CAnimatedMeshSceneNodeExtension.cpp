#include "CAnimatedMeshSceneNode.h"

namespace irr
{
	namespace scene
	{
		// add new animation set to the internal map
		bool CAnimatedMeshSceneNode::addAnimation(core::stringw animationName, CAnimationKeyMap* animationKeys){
			if (AnimationMap.count(animationName) == 0){
				AnimationMap[animationName] = animationKeys;
				return true;
			}
			// return false if there is already an animation with the same key
			return false;
		};
		// check if the animation has been saved inside the mesh
		bool CAnimatedMeshSceneNode::canPerformAnimation(core::stringw animationName){
			return (AnimationMap.count(animationName) > 0);
		}
		// set new animation based on name
		bool CAnimatedMeshSceneNode::setAnimation(core::stringw animationName){
			// if no animation matches the required name, return false
			if (!canPerformAnimation(animationName)){
				return false;
			}
			// if this is a new animation, load the correct array in memory
			if (animationName != getCurrentAnimationName()){
				//if (!JointsUsed) return false;
				core::array<ISkinnedMesh::SJoint*> AllJoints = ((ISkinnedMesh*)Mesh)->getAllJoints();
				for (u32 i = 0; i < AllJoints.size(); ++i)
				{
					ISkinnedMesh::SJoint *joint = AllJoints[i];
					joint->RotationKeys.clear();
					joint->ScaleKeys.clear();
					joint->PositionKeys.clear();
					core::stringw jointName = joint->Name;
					joint->RotationKeys = AnimationMap[animationName]->getRotationKeys(jointName);
					joint->ScaleKeys = AnimationMap[animationName]->getScaleKeys(jointName);
					joint->PositionKeys = AnimationMap[animationName]->getPositionKeys(jointName);
				}
				return true;
			}
			return false;
		}
		// set new frame loop
		bool CAnimatedMeshSceneNode::setAnimationFrameLoop(core::stringw animationName, s32 begin, s32 end){
			// if the animation is new, load it from the map. If not, return false
			return setAnimation(animationName) && setFrameLoop(begin, end);
		};
		// get current animation name
		core::stringw CAnimatedMeshSceneNode::getCurrentAnimationName(){
			return currentAnimationName;
		};


	}
}