cocos2d-x-ogre
==============

render 3D model by ogre in cocos2d-x

  Hi, I'm tring to render 3D model by ogre in cocos2d-x a 
few days ago. Now it works fine on linux, but some bugs 
on android yet, the main bug is it would show 3D model 
on android, but cocos2d-x can not be visible, I'm tring 
to resolve it.

  Ogre is just a plugin or third part for cocos2d-x here,
you do not need to modify cocos2d-x source code. ogre is 
very friendly with cocos2d-x on linux. so linux need no 
more words.

  Android port is more troble than linux, because ogre
using libfreeimage, cocos2d-x using libpng, libjpeg and
libtiff, when I compile ogre and cocos2d-x together, the
libs is multidefined, ogre is support more image format
than cocos2d-x, so I can't replace libfreeimage, I have to 
modify cocos2d-x Android.mk, replace libpng, libjpeg
and libtiff with libfreeimage, it is very easy, and it works
fine.

NOTICE:
  If you compile android error, try follow please:
  when build native code modify HelloOgre project.properties file:
  set target=android-9
  when build java code and pack it to apk:
  set target=android-8

INSTALL:
  copy all file to $COCOS2D_X_2.0.4_ROOT

Contact me:
  tpf 27001909@qq.com
