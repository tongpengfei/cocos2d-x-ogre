/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2012 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#include "OgreException.h"
#include "OgreLogManager.h"
#include "OgreStringConverter.h"
#include "OgreRoot.h"

#include "OgreGLES2Prerequisites.h"
#include "OgreGLES2RenderSystem.h"

#include "OgreAndroidGLSupport.h"
#include "OgreAndroidWindow.h"
#include "OgreAndroidGLContext.h"

namespace Ogre {

    AndroidGLSupport::AndroidGLSupport()
    {
    }

    AndroidGLSupport::~AndroidGLSupport()
    {
        
	}

    String AndroidGLSupport::getDisplayName(void)
    {
		return "Android GLES2 Support";
	}


    void AndroidGLSupport::switchMode(uint& width, uint& height, short& frequency)
    {
        
	}
	
	RenderWindow* AndroidGLSupport::createWindow(bool autoCreateWindow,
											GLES2RenderSystem *renderSystem,
											const String& windowTitle)
	{
		LogManager::getSingleton().logMessage("\tGLSupport createWindow called");
		
		RenderWindow *window = 0;

        if (autoCreateWindow)
        {
            ConfigOptionMap::iterator opt;
            ConfigOptionMap::iterator end = mOptions.end();
            NameValuePairList miscParams;

            bool fullscreen = true;
			unsigned int w = 800, h = 600;

			if(( opt = mOptions.find("Video Mode")) != end){
				String val = opt->second.currentValue;
				String::size_type pos = val.find('x');
				if (pos == String::npos)
					OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, "Invalid Video Mode provided", "GLES2Support::createWindow");

				w = StringConverter::parseUnsignedInt(val.substr(0, pos));
				h = StringConverter::parseUnsignedInt(val.substr(pos + 1));
			}

            if ((opt = mOptions.find("Display Frequency")) != end){
                miscParams["displayFrequency"] = opt->second.currentValue;
            }

            window = renderSystem->_createRenderWindow(windowTitle, w, h, fullscreen, &miscParams);
        }

        return window;
	}

    RenderWindow* AndroidGLSupport::newWindow(const String &name,
                                        unsigned int width, unsigned int height,
                                        bool fullScreen,
                                        const NameValuePairList *miscParams)
    {
		LogManager::getSingleton().logMessage("\tGLSupport newWindow called");
		
		AndroidWindow* window = new AndroidWindow(this);
        window->create(name, width, height, fullScreen, miscParams);

        return window;
    }
	
	void AndroidGLSupport::start(void)
	{
		LogManager::getSingleton().logMessage("\tGLSupport start called");
	}
    
	void AndroidGLSupport::stop(void)
	{
		LogManager::getSingleton().logMessage("\tGLSupport stop called");
	}
    
	void AndroidGLSupport::addConfig(void)
	{
		LogManager::getSingleton().logMessage("\tGLSupport addConfig called");

		ConfigOption optFullScreen;
		ConfigOption optVideoMode;
		ConfigOption optBitDepth;
		ConfigOption optFSAA;
		ConfigOption optRTTMode;

		// FS setting possiblities
		optFullScreen.name = "Full Screen";
		optFullScreen.possibleValues.push_back("Yes");
		optFullScreen.possibleValues.push_back("No");
		optFullScreen.currentValue = "Yes";
		optFullScreen.immutable = false;

		// Video mode possiblities
		optVideoMode.name = "Video Mode";
		optVideoMode.immutable = false;

		// We could query Xrandr here, but that wouldn't work in the non-fullscreen case
		// or when that extension is disabled. Anyway, this list of modes is fairly
		// complete.
		optVideoMode.possibleValues.push_back("640 x 480");
		optVideoMode.possibleValues.push_back("800 x 600");
		optVideoMode.possibleValues.push_back("1024 x 768");
		optVideoMode.possibleValues.push_back("1280 x 960");
		optVideoMode.possibleValues.push_back("1280 x 1024");
		optVideoMode.possibleValues.push_back("1600 x 1200");

		optVideoMode.currentValue = "800 x 600";

		//FSAA possibilities
		optFSAA.name = "FSAA";
		optFSAA.possibleValues.push_back("0");
		optFSAA.possibleValues.push_back("2");
		optFSAA.possibleValues.push_back("4");
		optFSAA.possibleValues.push_back("6");
		optFSAA.currentValue = "0";
		optFSAA.immutable = false;

		optRTTMode.name = "RTT Preferred Mode";
		optRTTMode.possibleValues.push_back("FBO");
		optRTTMode.possibleValues.push_back("PBuffer");
		optRTTMode.possibleValues.push_back("Copy");
		optRTTMode.currentValue = "FBO";
		optRTTMode.immutable = false;

		mOptions[optFullScreen.name] = optFullScreen;
		mOptions[optVideoMode.name] = optVideoMode;
		mOptions[optFSAA.name] = optFSAA;
		mOptions[optRTTMode.name] = optRTTMode;

		// Currently no config options supported
		refreshConfig();
	}

	void AndroidGLSupport::refreshConfig(void)
	{
	}

	String AndroidGLSupport::validateConfig(void)
	{
		return StringUtil::BLANK;
	}
    
	void AndroidGLSupport::setConfigOption(const String &name, const String &value)
	{
		GLES2Support::setConfigOption(name, value);
		char buff[256]; memset(buff, 0x00, sizeof(buff));
		sprintf( buff, "ogre AndroidGLSupport::setConfigOption %s : %s", name.c_str(), value.c_str() );
		LogManager::getSingleton().logMessage( buff );
	}
    
	void* AndroidGLSupport::getProcAddress(const Ogre::String& name)
	{
		return 0;
	}
	
}
