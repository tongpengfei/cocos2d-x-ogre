#include <ogreapp.h>

#include <cocos2d.h>
USING_NS_CC;

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "Android/OgreAPKFileSystemArchive.h"
#include "Android/OgreAPKZipArchive.h"
#include <OgreGLES2Plugin.h>
#include <android/asset_manager_jni.h>
#include <RTShaderHelper.h>
static AAssetManager* gAssetMgr = NULL;
static Ogre::ShaderGeneratorTechniqueResolverListener* gMatListener = NULL;

#else
#include <GL/glew.h>
#include "GL/glfw.h"
#include <OgreGLPlugin.h>
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include <CoreFoundation/CoreFoundation.h>

// This function will locate the path to our application on OS X,
// unlike windows you can not rely on the curent working directory
// for locating your configuration files and resources.

std::string macBundlePath()
{
    char path[1024];
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    assert(mainBundle);

    CFURLRef mainBundleURL = CFBundleCopyBundleURL(mainBundle);
    assert(mainBundleURL);

    CFStringRef cfStringRef = CFURLCopyFileSystemPath( mainBundleURL, kCFURLPOSIXPathStyle);
    assert(cfStringRef);

    CFStringGetCString(cfStringRef, path, 1024, kCFStringEncodingASCII);

    CFRelease(mainBundleURL);
    CFRelease(cfStringRef);

    return std::string(path);
}
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
static String resource_cfg_file = "android_resources.cfg";
#else
static String resource_cfg_file = "resources.cfg";
#endif

static OgreApp* s_ogreapp = NULL;
OgreApp* OgreApp::I(){
	if( NULL == s_ogreapp ){
		s_ogreapp = new OgreApp();
	}
	return s_ogreapp;
}

OgreApp::OgreApp(){
	mRoot = 0;
	// Provide a nice cross platform solution for locating the configuration files
	// On windows files are searched for in the current working directory, on OS X however
	// you must provide the full path, the helper function macBundlePath does this for us.
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
	mResourcePath = macBundlePath() + "/Contents/Resources/";
#else
	mResourcePath = "../Resources/";
#endif
}

OgreApp::~OgreApp(){
	destroyScene();
	if (mRoot)
		delete mRoot;
}

void OgreApp::start(void){
	if (!setup())
		return;

	RenderSystem* render_system = mRoot->getRenderSystem();
	assert( render_system );
	render_system->_initRenderTargets();
	mRoot->clearEventTimes();
}


// These internal methods package up the stages in the startup process
/** Sets up the application - returns false if the user chooses to abandon configuration. */
bool OgreApp::setup(void){
	String cfgPath = mResourcePath + resource_cfg_file;

	mRoot = new Root();

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	Ogre::GLES2Plugin* plugin = new Ogre::GLES2Plugin();
#else
	Ogre::GLPlugin* plugin = new Ogre::GLPlugin();
	//Ogre::GLES2Plugin* plugin = new Ogre::GLES2Plugin();
#endif

	mRoot->installPlugin(plugin);
	Ogre::RenderSystem* rs = mRoot->getRenderSystemByName( "OpenGL Rendering Subsystem" );
	assert( rs );

//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCSize frameSize = CCDirector::sharedDirector()->getWinSize();
	char buff[256]; memset( buff, 0x00, sizeof(buff) );
	sprintf( buff, "%dx%d", (int)frameSize.width, (int)frameSize.height );
//	sprintf( buff, "%dx%d", 200, 200 );
	rs->setConfigOption( "Video Mode", buff );
	rs->setConfigOption( "Full Screen", "No" );

	mRoot->setRenderSystem( rs );
	mWindow = mRoot->initialise(true);

	setupResources();

	chooseSceneManager();
	createCamera();
	createViewports();

	// Set default mipmap level (NB some APIs ignore this)
	TextureManager::getSingleton().setDefaultNumMipmaps(5);

	// Create any resource listeners (for loading screens)
	createResourceListener();
	// Load resources

#if( CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID )
	//android 不需要?
	loadResources();
#endif
	return true;
}

SceneManager* OgreApp::getSceneManager(){
	return mSceneMgr;
}

void OgreApp::chooseSceneManager(void){
	// Create the SceneManager, in this case a generic one
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "OgreSMInstance");
}

void OgreApp::createCamera(void){
	// Create the camera
	mCamera = mSceneMgr->createCamera("OgreCamera");

	// Position it at 500 in Z direction
	mCamera->setPosition(Vector3(0,0,500));
	// Look back along -Z
	mCamera->lookAt(Vector3(0,0,-300));
	mCamera->setNearClipDistance(5);
}

void OgreApp::destroyScene(void){
}

void OgreApp::createViewports(void){
	// Create one viewport, entire window
	Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(ColourValue(0.0,0.0,0.3));

	// Alter the camera aspect ratio to match the viewport
	mCamera->setAspectRatio(
			Real(vp->getActualWidth()) / Real(vp->getActualHeight()));

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	Ogre::RTShader::ShaderGenerator::initialize();
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
	gMatListener = new Ogre::ShaderGeneratorTechniqueResolverListener();
	Ogre::MaterialManager::getSingleton().addListener(gMatListener);

	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(mSceneMgr);

	vp->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);    
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->invalidateScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
#endif

}

/// Method which will define the source of resources (other than current folder)
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
static Ogre::DataStreamPtr openAPKFile(const Ogre::String& fileName);
#endif
void OgreApp::setupResources(void){
	Ogre::ResourceGroupManager* res_manager = Ogre::ResourceGroupManager::getSingletonPtr();
#if 0
	std::string res_path = respath + "materials/programs";
	res_manager->addResourceLocation(res_path, "FileSystem", "General");
	res_path = respath + "materials/scripts";
	res_manager->addResourceLocation(res_path, "FileSystem", "General");
	res_path = respath + "materials/textures";
	res_manager->addResourceLocation(res_path, "FileSystem", "General");
	res_path = respath + "models";
	res_manager->addResourceLocation(res_path, "FileSystem", "General");
#endif

	// Load resource paths from config file
	ConfigFile cf;

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	if (gAssetMgr) {   
		ArchiveManager::getSingleton().addArchiveFactory( 
				new APKFileSystemArchiveFactory(gAssetMgr) );
		ArchiveManager::getSingleton().addArchiveFactory( 
				new APKZipArchiveFactory(gAssetMgr) );
	} 

	cf.load(openAPKFile(resource_cfg_file));
#else
	cf.load(mResourcePath + resource_cfg_file);
#endif

	// Go through all sections & settings in the file
	ConfigFile::SectionIterator seci = cf.getSectionIterator();

	String sec, type, arch;
	while (seci.hasMoreElements()){
		sec = seci.peekNextKey();
		ConfigFile::SettingsMultiMap *settings = seci.getNext();
		ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i){
			type = i->first;
			arch = i->second;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
			// OS X does not set the working directory relative to the app,
			// In order to make things portable on OS X we need to provide
			// the loading with it's own bundle path location
			arch = String(macBundlePath) + "/" + arch;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//			arch= "assets/" + arch;
#else
			//notice: mResourcePath must be prefix
			arch= mResourcePath + arch;
#endif
			res_manager->addResourceLocation(arch, type, sec);
		}
	}

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	res_manager->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
#endif
}

/// Optional override method where you can create resource listeners (e.g. for loading screens)
void OgreApp::createResourceListener(void){
}

/// Optional override method where you can perform resource group loading
/// Must at least do ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
void OgreApp::loadResources(void){
	// Initialise, parse scripts etc
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void oc_reset_gl_state(){
	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, 0 );
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnable(GL_BLEND);

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#else
	GLfloat lmodel_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
#endif
}

void oc_reset_cc_gl_state(){
	//reset to cocos2d-x render state
	static GLuint s_cc_gl_program = 0;
	static CCDirector* s_cc_director = NULL;
	if( 0 == s_cc_gl_program ){
		CCShaderCache* cache = CCShaderCache::sharedShaderCache();
		CCGLProgram* glp = cache->programForKey(kCCShader_PositionTextureColor);
		s_cc_gl_program = glp->getProgram();
	}
	if( NULL == s_cc_director ){
		s_cc_director = CCDirector::sharedDirector();
	}
	glUseProgram(s_cc_gl_program);
	s_cc_director->setAlphaBlending(true);
	s_cc_director->setDepthTest(false);
	s_cc_director->setProjection(kCCDirectorProjection3D);
//	glDisable( GL_CULL_FACE );
}

void OgreApp::render(){
	glUseProgram(0);
	mRoot->renderOneFrame();

	oc_reset_gl_state();
	//you may render some model here
	//render_other_model();
	oc_reset_cc_gl_state();
}

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
static Ogre::DataStreamPtr openAPKFile(const Ogre::String& fileName){
	Ogre::DataStreamPtr stream;
	AAsset* asset = AAssetManager_open(gAssetMgr, fileName.c_str(), AASSET_MODE_BUFFER);
	if(asset){
		off_t length = AAsset_getLength(asset);
		void* membuf = OGRE_MALLOC(length, Ogre::MEMCATEGORY_GENERAL);
		memcpy(membuf, AAsset_getBuffer(asset), length);
		AAsset_close(asset);

		stream = Ogre::DataStreamPtr(new Ogre::MemoryDataStream(membuf, length, true, true));
	}
	return stream;
}


extern "C"{
void Java_org_cocos2dx_hellocpp_HelloOgre_nativeSetAssetsManagerFromJava(JNIEnv* env, jobject thiz, jobject assetManager ){
	gAssetMgr = AAssetManager_fromJava( env, assetManager );
}

}
#endif
