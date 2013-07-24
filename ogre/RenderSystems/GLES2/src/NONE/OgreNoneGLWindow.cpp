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
--------------------------------------------------------------------------*/

#include "OgreRoot.h"
#include "OgreException.h"
#include "OgreStringConverter.h"
#include "OgreWindowEventUtilities.h"

#include "OgreGLES2Prerequisites.h"
#include "OgreGLES2RenderSystem.h"

#include "OgreNoneGLSupport.h"
#include "OgreNoneGLWindow.h"
#include "OgreNoneGLContext.h"
#include "OgreGLES2PixelFormat.h"

#include <iostream>
#include <algorithm>
#include <climits>

namespace Ogre {

    NoneGLWindow::NoneGLWindow(NoneGLSupport *glsupport)
        : mGLSupport(glsupport),
          mContext(0) {
        mIsTopLevel = false;
        mIsFullScreen = false;
        mClosed = false;
        mActive = true;//todo
        mIsExternalGLControl = false;
		mVisible = false;
    }

    NoneGLWindow::~NoneGLWindow(){
        destroy();

        if (mContext){
            delete mContext;
        }

        mContext = 0;
    }

    void NoneGLWindow::destroy(void)
    {
        if (mClosed){
            return;
        }

        mClosed = true;
        mActive = false;

        if (!mIsExternal){
//            WindowEventUtilities::_removeRenderWindow(this);
        }

        if (mIsFullScreen)
        {
            switchFullScreen(false);
        }
    }

    void NoneGLWindow::setFullscreen(bool fullscreen, uint width, uint height){
        short frequency = 0;

        if (mClosed || !mIsTopLevel){
            return;
        }

        if (fullscreen == mIsFullScreen && width == mWidth && height == mHeight){
            return;
        }
        if (mIsFullScreen != fullscreen){
            switchFullScreen(fullscreen);
        }

        if (!mIsFullScreen){
            resize(width, height);
            reposition(mLeft, mTop);
        }
    }

    bool NoneGLWindow::isClosed() const{
        return mClosed;
    }

    bool NoneGLWindow::isVisible() const
    {
        return mVisible;
    }

    void NoneGLWindow::setVisible(bool visible)
    {
        mVisible = visible;
    }

  

    void NoneGLWindow::swapBuffers(bool waitForVSync)
    {
        if (mClosed || mIsExternalGLControl){
            return;
        }

		LogManager::getSingleton().logMessage("NoneGLWindow swapBuffers");
//        glSwapBuffers();
    }

    void NoneGLWindow::getCustomAttribute( const String& name, void* pData )
    {
		(void)name;
		(void)pData;
	}

    void NoneGLWindow::copyContentsToMemory(const PixelBox &dst, FrameBuffer buffer)
    {
		if ((dst.left < 0) || (dst.right > mWidth) ||
			(dst.top < 0) || (dst.bottom > mHeight) ||
			(dst.front != 0) || (dst.back != 1)){
			OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
				"Invalid box.",
				"NoneGLWindow::copyContentsToMemory" );
		}

		if (buffer == FB_AUTO){
			buffer = mIsFullScreen? FB_FRONT : FB_BACK;
		}

		GLenum format = GLES2PixelUtil::getGLOriginFormat(dst.format);
		GLenum type = GLES2PixelUtil::getGLOriginDataType(dst.format);

		if ((format == 0) || (type == 0)){
			OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
				"Unsupported format.",
				"NoneGLWindow::copyContentsToMemory" );
		}


		// Switch context if different from current one
		RenderSystem* rsys = Root::getSingleton().getRenderSystem();
		rsys->_setViewport(this->getViewport(0));

		// Must change the packing to ensure no overruns!
		glPixelStorei(GL_PACK_ALIGNMENT, 1);

		//glReadBuffer((buffer == FB_FRONT)? GL_FRONT : GL_BACK);
		glReadPixels((GLint)dst.left, (GLint)dst.top,
			(GLsizei)dst.getWidth(), (GLsizei)dst.getHeight(),
			format, type, dst.data);

		// restore default alignment
		glPixelStorei(GL_PACK_ALIGNMENT, 4);

		//vertical flip
		{
			size_t rowSpan = dst.getWidth() * PixelUtil::getNumElemBytes(dst.format);
			size_t height = dst.getHeight();
			uchar *tmpData = new uchar[rowSpan * height];
			uchar *srcRow = (uchar *)dst.data, *tmpRow = tmpData + (height - 1) * rowSpan;

			while (tmpRow >= tmpData)
			{
				memcpy(tmpRow, srcRow, rowSpan);
				srcRow += rowSpan;
				tmpRow -= rowSpan;
			}
			memcpy(dst.data, tmpData, rowSpan * height);

			delete [] tmpData;
		}

    }

	bool NoneGLWindow::requiresTextureFlipping() const
	{
		return false;
	}
	void NoneGLWindow::create(const String& name, uint width, uint height,
				                           bool fullScreen, const NameValuePairList *miscParams)
	{ 
	}
}
