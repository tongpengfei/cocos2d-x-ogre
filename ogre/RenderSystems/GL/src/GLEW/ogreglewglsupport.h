#ifndef OGRE_GLEWGLSupport_H
#define OGRE_GLEWGLSupport_H

#include "OgreGLSupport.h"

//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glx.h>

namespace Ogre {

class GLEWGLSupport : public GLSupport
{
public:
	GLEWGLSupport();
	~GLEWGLSupport();

	/**
	* Add any special config values to the system.
	* Must have a "Full Screen" value that is a bool and a "Video Mode" value
	* that is a string in the form of wxh
	*/
	void addConfig(void);
	/**
	* Make sure all the extra options are valid
	*/
	String validateConfig(void);

	/// @copydoc GLSupport::createWindow
	RenderWindow* createWindow(bool autoCreateWindow, GLRenderSystem* renderSystem, const String& windowTitle);
	
	/// @copydoc RenderSystem::createRenderWindow
	virtual RenderWindow* newWindow(const String &name, unsigned int width, unsigned int height, 
		bool fullScreen, const NameValuePairList *miscParams = 0);

	virtual void initialiseExtensions();
	
	/**
	* Start anything special
	*/
	void start();
	/**
	* Stop anything special
	*/
	void stop();

	/**
	* Get the address of a function
	*/
	void* getProcAddress(const String& procname);
}; 

}; // namespace Ogre

#endif // OGRE_GLEWGLSupport_H
