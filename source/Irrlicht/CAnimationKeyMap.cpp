#include "CAnimationKeyMap.h"

namespace irr
{
	namespace scene{
		CAnimationKeyMap::CAnimationKeyMap(){
			reset();
		};
		void CAnimationKeyMap::reset(){
			PositionKeys.clear();
			RotationKeys.clear();
			ScaleKeys.clear();
		};
		// add position key
		bool CAnimationKeyMap::addPositionKey(core::stringw jointName, ISkinnedMesh::SPositionKey newKey){
			if (PositionKeys.count(jointName) == 0){
				PositionKeys[jointName] = core::array< ISkinnedMesh::SPositionKey >();
			}
			PositionKeys[jointName].push_back(newKey);
			return true;
		};
		// add rotation key
		bool CAnimationKeyMap::addRotationKey(core::stringw jointName, ISkinnedMesh::SRotationKey newKey){
			if (RotationKeys.count(jointName) == 0){
				RotationKeys[jointName] = core::array< ISkinnedMesh::SRotationKey >();
			}
			RotationKeys[jointName].push_back(newKey);
			return true;
		};
		// add scale key
		bool CAnimationKeyMap::addScaleKey(core::stringw jointName, ISkinnedMesh::SScaleKey newKey){
			if (ScaleKeys.count(jointName) == 0){
				ScaleKeys[jointName] = core::array< ISkinnedMesh::SScaleKey >();
			}
			ScaleKeys[jointName].push_back(newKey);
			return true;
		}
		core::array<ISkinnedMesh::SPositionKey> & CAnimationKeyMap::getPositionKeys(core::stringw jointName){
			if (PositionKeys.count(jointName) == 0){
				PositionKeys[jointName] = core::array< ISkinnedMesh::SPositionKey >();
			}
			return PositionKeys[jointName];
		};
		core::array<ISkinnedMesh::SScaleKey> & CAnimationKeyMap::getScaleKeys(core::stringw jointName){
			if (ScaleKeys.count(jointName) == 0){
				ScaleKeys[jointName] = core::array< ISkinnedMesh::SScaleKey >();
			}
			return ScaleKeys[jointName];
		};
		core::array<ISkinnedMesh::SRotationKey>& CAnimationKeyMap::getRotationKeys(core::stringw jointName){
			if (RotationKeys.count(jointName) == 0){
				RotationKeys[jointName] = core::array< ISkinnedMesh::SRotationKey >();
			}
			return RotationKeys[jointName];
		};
	}
}