#include "helloogre.h"
#include "AppMacros.h"
USING_NS_CC;

#include <macro.h>
#include <ogreapp.h>
#include <string>
using std::string;

OgreScene* OgreScene::create(){
	OgreScene* v = new OgreScene();
	if( v->init() ){
		v->autorelease();
	}else{
		delete v;
		v = NULL;
	}
	return v;
}

bool OgreScene::init(){
	CCScene::init();
	OgreApp::I()->start();
	return true;
}

void OgreScene ::visit(void){
	OgreApp::I()->render();
	CCScene::visit();
}

CCScene* HelloOgre::scene(){
    CCScene *scene = OgreScene::create();
    HelloOgre *layer = HelloOgre::create();
    scene->addChild(layer);
    return scene;
}

HelloOgre* HelloOgre::create(){
	HelloOgre* o = new HelloOgre();
	if( o->init() ){
		o->autorelease();
	}else{
		delete o;
		o = NULL;
	}
	return o;
}

// on "init" you need to initialize your instance
bool HelloOgre::init(){
    if ( !CCLayer::init() ){
        return false;
    }

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
	tAssertm( pSprite, "HelloWorld.png" );
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	pSprite->setScale( 0.1 );
    this->addChild(pSprite, 0);

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
    					"CloseNormal.png", "CloseSelected.png", this,
						menu_selector(HelloOgre::menuCloseCallback));
	pCloseItem->setPosition(
				ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
               		origin.y + pCloseItem->getContentSize().height/2));
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    CCLabelTTF* pLabel = CCLabelTTF::create("Hello Ogre", "Arial", TITLE_FONT_SIZE);
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    this->addChild(pLabel, 1);

	initOgre();
	createManual();
	scheduleUpdate();
    return true;
}

void HelloOgre::update(float){
	static int move_dir = -1;
	static float move_step = 2.0f;
	static int move_count = 0;
	static float move_offset = 0.0f;
	if( move_count % 150 == 0 ){
		move_dir *= -1;
	}
	move_offset = move_step * move_dir;
	move_count++;

	if( ogre_head_node ){
		ogre_head_node->translate( Ogre::Vector3(move_offset, 0.0f, 0.0f));
		ogre_head_node->rotate( Ogre::Vector3( 0.0f, 1.0f, 0.0f ), Ogre::Radian(0.1f) );
	}

	if( ogre_head_node2 ){
		ogre_head_node2->translate( Ogre::Vector3(-move_offset, 0.0f, 0.0f));
		ogre_head_node2->rotate( Ogre::Vector3( 0.0f, 1.0f, 0.0f ), Ogre::Radian(0.1f) );
	}

	size_t nsize = vec_ogre_head_node.size();
	Ogre::SceneNode* pnode = NULL;
	size_t half_size = nsize >> 1;
	for( size_t i=0; i<half_size; ++i ){
		pnode = vec_ogre_head_node[i];
		pnode->translate( Ogre::Vector3((move_offset*i*0.1f), 0.0f, 0.0f));
		pnode->rotate( Ogre::Vector3( 0.0f, 1.0f, 0.0f ), Ogre::Radian(0.1f) );
	}

	for( size_t i=0; i<half_size; ++i ){
		pnode = vec_ogre_head_node[half_size+i];
		pnode->translate( Ogre::Vector3(-(move_offset*i*0.1f), 0.0f, 0.0f));
		pnode->rotate( Ogre::Vector3( 0.0f, 1.0f, 0.0f ), Ogre::Radian(0.1f) );
	}
}

void HelloOgre::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloOgre::initOgre(){
	ogre_head = NULL;
	ogre_head_node = NULL;
	Ogre::Root* ogre_root = Ogre::Root::getSingletonPtr();
	Ogre::SceneManager* mSceneMgr= OgreApp::I()->getSceneManager();

	mSceneMgr->setSkyBox(true, "Examples/SpaceSkyBox", 50 );

	Light* l = mSceneMgr->createLight("MainLight");
	// Accept default settings: point light, white diffuse, just set position
	// NB I could attach the light to a SceneNode if I wanted it to move automatically with
	//  other objects, but I don't
	l->setPosition(20,80,50);

	ogre_head = mSceneMgr->createEntity("OgreHead", "ogrehead.mesh");
	ogre_head_node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogre_head_node->attachObject( ogre_head );
	ogre_head_node->translate( Ogre::Vector3(0.0f, 0.0f, 0.0f));

	ogre_head2 = mSceneMgr->createEntity("OgreHead2", "ogrehead.mesh");
	ogre_head_node2 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogre_head_node2->attachObject( ogre_head2 );
	ogre_head_node2->translate( Ogre::Vector3(0.0f, 0.0f, 0.0f));

	for( int i=0; i<0; ++i ){
		string head_name = "head";
		head_name += i;
		Ogre::Entity* head = mSceneMgr->createEntity(head_name.c_str(), "ogrehead.mesh");
		Ogre::SceneNode* head_node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		head_node->attachObject( head );
		head_node->translate( Ogre::Vector3(0.0f, 0.0f, 0.0f));
		vec_ogre_head_node.push_back( head_node );
	}
}

void HelloOgre::createManual(){
	Ogre::SceneManager* mSceneMgr= OgreApp::I()->getSceneManager();
#if 1
	ManualObject* manual = mSceneMgr->createManualObject("manual");
	// specify the material (by name) and rendering type
	manual->begin("BaseWhiteNoLighting", RenderOperation::OT_LINE_LIST);
//	manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_STRIP);
	// define start and end point
	manual->position(-100, -100, -100 );
	manual->position(100, 100, 100 );
	manual->colour( 1.0f, 1.0f, 1.0f, 1.0f );
	// tell Ogre, your definition has finished
	manual->end();
	// add ManualObject to the RootSceneNode (so it will be visible)
	mSceneMgr->getRootSceneNode()->attachObject(manual);
#endif

#if 1
// Create a manual object for 2D
	manual = mSceneMgr->createManualObject("manual2");
	 
	// Use identity view/projection matrices
	manual->setUseIdentityProjection(true);
	manual->setUseIdentityView(true);
	 
	manual->begin("BaseWhiteNoLighting", RenderOperation::OT_LINE_STRIP);
	 
	manual->position(-0.2, -0.2, 0.0);
	manual->position( 0.2, -0.2, 0.0);
	manual->position( 0.2,  0.2, 0.0);
	manual->position(-0.2,  0.2, 0.0);
	 
	manual->index(0);
	manual->index(1);
	manual->index(2);
	manual->index(3);
	manual->index(0);
	 
	manual->end();
	 
	// Use infinite AAB to always stay visible
	AxisAlignedBox aabInf;
	aabInf.setInfinite();
	manual->setBoundingBox(aabInf);
	 
	// Render just before overlays
	manual->setRenderQueueGroup(RENDER_QUEUE_OVERLAY - 1);
	 
	// Attach to scene
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(manual);
#endif
}
