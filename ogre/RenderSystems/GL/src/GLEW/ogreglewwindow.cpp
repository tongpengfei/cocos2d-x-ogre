/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

You may alternatively use this source under the terms of a specific version of
the OGRE Unrestricted License provided you have obtained such a license from
Torus Knot Software Ltd.
-----------------------------------------------------------------------------
*/

#include "ogreglewwindow.h"
#include "OgreRoot.h"
#include "OgreGLRenderSystem.h"
#include "OgreImageCodec.h"
#include "OgreException.h"
#include "OgreLogManager.h"
#include "OgreStringConverter.h"
#include "OgreWindowEventUtilities.h"
#include "OgreGLUtil.h"

//#include "GL/glfw.h"

#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <climits>

//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glx.h>
#include <GL/glfw.h>
//#include <glew.h>

//#include <ccMacros.h>
//#include <CCEGLView.h>

namespace Ogre{

GLEWWindow::GLEWWindow():mClosed(false), mVisible(true), mOldMode(-1){
	mActive = false;
	mIsFullScreen = false;
}

GLEWWindow::~GLEWWindow() {
	destroy();
}

void GLEWWindow::create(const String& name, unsigned int width, unsigned int height,
	            bool fullScreen, const NameValuePairList *miscParams){
	LogManager::getSingleton().logMessage("GLEWWindow::create");

	String title = name;
        // Unless parentWindowHandle is given in miscParams we're top-level
	mTopLevel = true;
   
	LogManager::getSingleton().logMessage("Parsing miscParams");
	if(miscParams){
		// Parse miscellenous parameters
		NameValuePairList::const_iterator opt;
		// Window title
		opt = miscParams->find("title");
		if(opt != miscParams->end()) //check for FSAA parameter, if not ignore it...
			title = opt->second;

	}
	//Register only Ogre created windows (users can register their own)
//	WindowEventUtilities::_addRenderWindow(this);

	mName = name;
	mWidth = width;
	mHeight = height;
	mIsFullScreen = fullScreen;

	mLeft = 0;
	mTop = 0;

	// Create OGRE GL context
//	mContext = new GLXContext(mDisplay, mWindow, mGlxContext, mVisualInfo);
	mActive = true;
}

void GLEWWindow::destroy(void){
//	WindowEventUtilities::_removeRenderWindow(this);


	mActive = false;
	mVisible = false;
	mClosed = true;

	Root::getSingleton().getRenderSystem()->detachRenderTarget( this->getName() );
}

bool GLEWWindow::isActive() const{
	return mActive;
}

bool GLEWWindow::isClosed() const{
	return mClosed;
}

bool GLEWWindow::isVisible() const{
	return mVisible;
}

void GLEWWindow::setVisible(bool visible){
	mVisible = visible;
}

void GLEWWindow::reposition(int left, int top){
//	XMoveWindow(mDisplay,mWindow,left,top);
}

void GLEWWindow::resize(unsigned int width, unsigned int height){
	// Check if the window size really changed
	if(mWidth == width && mHeight == height)
		return;

	mWidth = width;
	mHeight = height;

	if (!mTopLevel){
		for (ViewportList::iterator it = mViewportList.begin();	it != mViewportList.end(); ++it)
			(*it).second->_updateDimensions();
	}else{
//		XResizeWindow(mDisplay, mWindow, width, height); /// Ogre handles window
		bool eResult = false;
//		int u32GLFWFlags = GLFW_WINDOW;
//		eResult = (glfwOpenWindow(width, height, 5, 6, 5, 0, 16, 0, (int)u32GLFWFlags) != false) ? true : false;
		if (!eResult) {
//			CCAssert(0, "fail to GLEWWindow::resize of opengl");
		}
	}
}

void GLEWWindow::swapBuffers(bool waitForVSync){
//	cocos2d::CCEGLView::sharedOpenGLView()->glfwSwapBuffers();
//	glfwSwapBuffers();
}

void GLEWWindow::getCustomAttribute( const String& name, void* pData ){
//	if( name == "GLCONTEXT" ) {
//		static_cast<GLEWContext*>(pData) = glewGetContext();
//		return;
//	} 
}


void GLEWWindow::writeContentsToFile(const String& filename){
	ImageCodec::ImageData* imgData = new ImageCodec::ImageData;
	imgData->width = mWidth;
	imgData->height = mHeight;
	imgData->format = PF_BYTE_RGB;

	// Allocate buffer
	uchar* pBuffer = new uchar[mWidth * mHeight * 3];

	// Read pixels
	// I love GL: it does all the locking & colour conversion for us
	glReadPixels(0,0, mWidth, mHeight, GL_RGB, GL_UNSIGNED_BYTE, pBuffer);

	// Wrap buffer in a memory stream
	DataStreamPtr stream(new MemoryDataStream(pBuffer, mWidth * mHeight * 3, false));

	// Need to flip the read data over in Y though
	Image img;
	img.loadRawData(stream, mWidth, mHeight, PF_BYTE_RGB );
	img.flipAroundX();

	MemoryDataStreamPtr streamFlipped(new MemoryDataStream(img.getData(), stream->size(), false));

	// Get codec
	size_t pos = filename.find_last_of(".");
	String extension;
	if( pos == String::npos )
		OGRE_EXCEPT( Exception::ERR_INVALIDPARAMS, "Unable to determine image type for '" 
			+ filename + "' - invalid extension.", "GLEWWindow::writeContentsToFile" );

	while( pos != filename.length() - 1 )
		extension += filename[++pos];

	// Get the codec
	Codec * pCodec = Codec::getCodec(extension);

	// Write out
	Codec::CodecDataPtr codecDataPtr(imgData);
	pCodec->codeToFile(streamFlipped, filename, codecDataPtr);

	delete [] pBuffer;
}
}
