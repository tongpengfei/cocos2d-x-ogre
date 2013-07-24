#ifndef HELLOOGRE_H
#define HELLOOGRE_H

#include "cocos2d.h"

#include <OgreRoot.h>

#include <vector>
using std::vector;

class OgreScene : public cocos2d::CCScene{
public:
	static OgreScene* create();
	bool init();
	virtual void visit(void);
};

class Ogre::Entity;
class Ogre::SceneNode;
class HelloOgre : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	static HelloOgre* create();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	void update(float);
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
private:
	void initOgre();
	void createManual();
private:
	Ogre::Entity* ogre_head;
	Ogre::SceneNode* ogre_head_node;

	Ogre::Entity* ogre_head2;
	Ogre::SceneNode* ogre_head_node2;
	
	vector<Ogre::SceneNode*> vec_ogre_head_node;
};

#endif //HELLOOGRE_H
