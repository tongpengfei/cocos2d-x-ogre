#ifndef OGREAPP_H
#define OGREAPP_H

#include "Ogre.h"
#include "OgreConfigFile.h"
#include <OgreRenderWindow.h>

using namespace Ogre;

class OgreApp{
public:
	static OgreApp* I();
    OgreApp();
    virtual ~OgreApp();

    virtual void start(void);
	virtual void render();

	SceneManager* getSceneManager();
protected:
    Root *mRoot;
    Camera* mCamera;
    SceneManager* mSceneMgr;
    RenderWindow* mWindow;
	Ogre::String mResourcePath;

    // These internal methods package up the stages in the startup process
    /** Sets up the application - returns false if the user chooses to abandon configuration. */
    virtual bool setup(void);
    virtual void chooseSceneManager(void);
    virtual void createCamera(void);
    virtual void destroyScene(void);    // Optional to override this

    virtual void createViewports(void);

    /// Method which will define the source of resources (other than current folder)
    virtual void setupResources(void);
	/// Optional override method where you can create resource listeners (e.g. for loading screens)
	virtual void createResourceListener(void);

	/// Optional override method where you can perform resource group loading
	/// Must at least do ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	virtual void loadResources(void);
};

#endif//OGREAPP_H
