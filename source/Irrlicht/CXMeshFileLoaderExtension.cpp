
#include "IrrCompileConfig.h"

#ifdef _IRR_COMPILE_WITH_X_LOADER_

#include "CXMeshFileLoader.h"
#include "CMeshTextureLoader.h"
#include "os.h"

#include "fast_atof.h"
#include "coreutil.h"
#include "ISceneManager.h"
#include "IVideoDriver.h"
#include "IFileSystem.h"
#include "IReadFile.h"

namespace irr
{
	namespace scene
	{

		//! Parses the next Data object in the file
		bool CXMeshFileLoader::parseDataObjectAnimationSetOnly(io::IReadFile* file, CAnimationKeyMap* animationKey)
		{

			core::stringc objectName = getNextToken();

			if (objectName.size() == 0)
				return false;

			// parse specific object
#ifdef _XREADER_DEBUG
			os::Printer::log("debug DataObject:", objectName.c_str(), ELL_DEBUG);
#endif

			if (objectName == "AnimationSet")
			{
				return parseDataObjectAnimationSet();
			}

			//os::Printer::log("Unknown data object in animation of .x file", objectName.c_str(), ELL_WARNING);

			return parseUnknownDataObject();
		}

		bool CXMeshFileLoader::parseDataObjectAnimationSet(CAnimationKeyMap* animationKey)
		{
		#ifdef _XREADER_DEBUG
			os::Printer::log("CXFileReader: Reading animation set", ELL_DEBUG);
		#endif

			core::stringc AnimationName;

			if (!readHeadOfDataObject(&AnimationName))
			{
				os::Printer::log("No opening brace in Animation Set found in x file", ELL_WARNING);
				os::Printer::log("Line", core::stringc(Line).c_str(), ELL_WARNING);
				return false;
			}
			os::Printer::log("Reading animationset ", AnimationName, ELL_DEBUG);

			while (true)
			{
				core::stringc objectName = getNextToken();

				if (objectName.size() == 0)
				{
					os::Printer::log("Unexpected ending found in Animation set in x file.", ELL_WARNING);
					os::Printer::log("Line", core::stringc(Line).c_str(), ELL_WARNING);
					return false;
				}
				else
					if (objectName == "}")
					{
						break; // animation set finished
					}
					else
						if (objectName == "Animation")
						{
							if (!parseDataObjectAnimation())
								return false;
						}
						else
						{
							os::Printer::log("Unknown data object in animation set in x file", objectName.c_str(), ELL_WARNING);
							if (!parseUnknownDataObject())
								return false;
						}
			}
			return true;
		}

	}
}

#endif