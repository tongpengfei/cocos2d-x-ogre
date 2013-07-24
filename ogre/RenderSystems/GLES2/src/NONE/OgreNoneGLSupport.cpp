/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2008 Renato Araujo Oliveira Filho <renatox@gmail.com>
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

#include "OgreNoneGLSupport.h"
#include "OgreNoneGLWindow.h"
#include "OgreNoneGLRenderTexture.h"


namespace Ogre {


    NoneGLSupport::NoneGLSupport(){
    }

    NoneGLSupport::~NoneGLSupport(){
    }

    void NoneGLSupport::addConfig(void)
    {
        ConfigOption optFullScreen;
        ConfigOption optVideoMode;
        ConfigOption optDisplayFrequency;
        ConfigOption optFSAA;
#if GL_OES_packed_depth_stencil
        ConfigOption optRTTMode;
#endif

        optFullScreen.name = "Full Screen";
        optFullScreen.immutable = false;

        optVideoMode.name = "Video Mode";
        optVideoMode.immutable = false;

        optDisplayFrequency.name = "Display Frequency";
        optDisplayFrequency.immutable = false;

        optFSAA.name = "FSAA";
        optFSAA.immutable = false;

#if GL_OES_packed_depth_stencil
        optRTTMode.name = "RTT Preferred Mode";
        optRTTMode.possibleValues.push_back("FBO");
        optRTTMode.possibleValues.push_back("Copy");
        optRTTMode.currentValue = "FBO";
        optRTTMode.immutable = false;
        optRTTMode.currentValue = optRTTMode.possibleValues[0];
#endif
        optFullScreen.possibleValues.push_back("No");
        optFullScreen.possibleValues.push_back("Yes");

        optFullScreen.currentValue = optFullScreen.possibleValues[1];

        VideoModes::const_iterator value = mVideoModes.begin();
        VideoModes::const_iterator end = mVideoModes.end();

        for (; value != end; value++)
        {
            String mode = StringConverter::toString(value->first.first,4) + " x " + StringConverter::toString(value->first.second,4);
            optVideoMode.possibleValues.push_back(mode);
        }
        removeDuplicates(optVideoMode.possibleValues);

        optVideoMode.currentValue = StringConverter::toString(mCurrentMode.first.first,4) + " x " + StringConverter::toString(mCurrentMode.first.second,4);

        refreshConfig();
        if (!mSampleLevels.empty())
        {
            StringVector::const_iterator value = mSampleLevels.begin();
            StringVector::const_iterator end = mSampleLevels.end();

            for (; value != end; value++)
            {
                optFSAA.possibleValues.push_back(*value);
            }

            optFSAA.currentValue = optFSAA.possibleValues[0];
        }


        mOptions[optFullScreen.name] = optFullScreen;
        mOptions[optVideoMode.name] = optVideoMode;
        mOptions[optDisplayFrequency.name] = optDisplayFrequency;
        mOptions[optFSAA.name] = optFSAA;
#if GL_OES_packed_depth_stencil
        mOptions[optRTTMode.name] = optRTTMode;
#endif
        refreshConfig();
    }

    void NoneGLSupport::refreshConfig(void) 
    {
        ConfigOptionMap::iterator optVideoMode = mOptions.find("Video Mode");
        ConfigOptionMap::iterator optDisplayFrequency = mOptions.find("Display Frequency");

        if (optVideoMode != mOptions.end() && optDisplayFrequency != mOptions.end())
        {
            optDisplayFrequency->second.possibleValues.clear();

            VideoModes::const_iterator value = mVideoModes.begin();
            VideoModes::const_iterator end = mVideoModes.end();

            for (; value != end; value++)
            {
                String mode = StringConverter::toString(value->first.first,4) + " x " + StringConverter::toString(value->first.second,4);

                if (mode == optVideoMode->second.currentValue)
                {
                    String frequency = StringConverter::toString(value->second) + " MHz";

                    optDisplayFrequency->second.possibleValues.push_back(frequency);
                }
            }

            if (!optDisplayFrequency->second.possibleValues.empty())
            {
                optDisplayFrequency->second.currentValue = optDisplayFrequency->second.possibleValues[0];
            }
            else
            {
                optVideoMode->second.currentValue = StringConverter::toString(mVideoModes[0].first.first,4) + " x " + StringConverter::toString(mVideoModes[0].first.second,4);
                optDisplayFrequency->second.currentValue = StringConverter::toString(mVideoModes[0].second) + " MHz";
            }
        }
    }

    void NoneGLSupport::setConfigOption(const String &name, const String &value)
    {
        GLES2Support::setConfigOption(name, value);
        if (name == "Video Mode")
        {
            refreshConfig();
        }
    }

    String NoneGLSupport::validateConfig(void)
    {
        // TODO
        return StringUtil::BLANK;
    }

    String NoneGLSupport::getDisplayName(void)
    {
		return "todo";
    }

    void* NoneGLSupport::getProcAddress(const Ogre::String& name)
    {
#if 0
        return (void*)glGetProcAddress((const char*) name.c_str());
#endif
        return NULL;
    }

    RenderWindow* NoneGLSupport::createWindow(bool autoCreateWindow,
                                           GLES2RenderSystem* renderSystem,
                                           const String& windowTitle)
    {
        RenderWindow *window = 0;

        if (autoCreateWindow)
        {
            ConfigOptionMap::iterator opt;
            ConfigOptionMap::iterator end = mOptions.end();
            NameValuePairList miscParams;

            bool fullscreen = false;
            uint w = 640, h = 480;

            if ((opt = mOptions.find("Full Screen")) != end)
            {
                fullscreen = (opt->second.currentValue == "Yes");
            }

            if ((opt = mOptions.find("Display Frequency")) != end)
            {
                miscParams["displayFrequency"] = opt->second.currentValue;
            }

            if ((opt = mOptions.find("Video Mode")) != end)
            {
                String val = opt->second.currentValue;
                String::size_type pos = val.find('x');

                if (pos != String::npos)
                {
                    w = StringConverter::parseUnsignedInt(val.substr(0, pos));
                    h = StringConverter::parseUnsignedInt(val.substr(pos + 1));
                }
            }

            if ((opt = mOptions.find("FSAA")) != end)
            {
                miscParams["FSAA"] = opt->second.currentValue;
            }

            window = renderSystem->_createRenderWindow(windowTitle, w, h, fullscreen, &miscParams);
        }

        return window;
    }

    void NoneGLSupport::start()
    {
    }

    void NoneGLSupport::stop()
    {
    }
	RenderWindow* NoneGLSupport::newWindow(const String &name,
			unsigned int width, unsigned int height, bool fullScreen, const NameValuePairList *miscParams){   
		NoneGLWindow* window = new NoneGLWindow(this);
		window->create(name, width, height, fullScreen, miscParams);
		return window;
	} 
}
