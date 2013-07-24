CC      = gcc
CXX     = g++
TARGET	= main
CCFLAGS = -Wall -Wno-deprecated
CXXFLAGS = -Wall -Wno-deprecated
VISIBILITY = 

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
OGRE_PATH = $(SDK_PATH)/ogre
INCLUDES =  -I../ \
			-I../Classes \
			-I../Classes/ccogre \
			-I/home/tpf/company/code/libcocos2dx/public/tui \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/platform/third_party/linux \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libfreetype2 \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform \
			-I$(COCOS2DX_PATH)/platform/linux \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/include/ \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libxml2 \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libjpeg  \
			-I$(OGRE_PATH)/Build/ \
			-I$(OGRE_PATH)/OgreMain/include \
			-I$(OGRE_PATH)/OgreMain/include/GLX \
			-I$(OGRE_PATH)/RenderSystems/GL/include \
			-I$(OGRE_PATH)/RenderSystems/GLES2/include \


DEFINES = -DLINUX

OBJECTS = ./main.o \
        ../Classes/AppDelegate.o \
		../Classes/ogreapp.o \
		../Classes/helloogre.o
#        ../Classes/ccogreview.o \
        ../Classes/skybox.o \
        ../Classes/HelloWorldScene.o \
        ../Classes/exampleapplication.o \
        ../Classes/exampleframelistener.o \
#		../Classes/ccogre/ogreglewglsupport.o \
		../Classes/ccogre/ogreglewwindow.o

LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
STATICLIBS_DIR = ../../../cocos2dx/platform/third_party/linux/libraries/lib64
else
STATICLIBS_DIR = ../../../cocos2dx/platform/third_party/linux/libraries
endif
STATICLIBS = 
STATICLIBS = $(STATICLIBS_DIR)/libfreetype.a \
				$(STATICLIBS_DIR)/libxml2.a \
				$(STATICLIBS_DIR)/libpng.a \
				$(STATICLIBS_DIR)/libjpeg.a \
				$(STATICLIBS_DIR)/libtiff.a \
#				$(STATICLIBS_DIR)/libGLEW.a \

SHAREDLIBS = 
ifeq ($(LBITS),64)
SHAREDLIBS_DIR = $(SDK_PATH)/CocosDenshion/third_party/fmod/lib64/api/lib
SHAREDLIBS = -L$(SHAREDLIBS_DIR) -lfmodex64
else
SHAREDLIBS_DIR = $(SDK_PATH)/CocosDenshion/third_party/fmod/api/lib
SHAREDLIBS = -L$(SHAREDLIBS_DIR) -lfmodex
endif

SHAREDLIBS += -lglfw -lGL
#SHAREDLIBS += -L../../../lib/linux/Debug -lcocos2d -lrt -lz -lcocosdenshion -Wl,-rpath,../../../../lib/linux/Debug/ 
SHAREDLIBS += -Wl,-rpath,../../$(SHAREDLIBS_DIR)
#SHAREDLIBS += -Wl,-rpath,../../../../cocos2dx/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib
#SHAREDLIBS += -L$(SDK_PATH)/cocos2dx/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib -lGLEW
#SHAREDLIBS += -Wl,-rpath,$(SDK_PATH)/cocos2dx/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib

#$(shell ../../build-linux.sh $<)

BIN_DIR_ROOT=./
BIN_DIR = $(BIN_DIR_ROOT)

debug: BIN_DIR = ./
debug: CCFLAGS += -g3 -O0
debug: CXXFLAGS += -g3 -O0
debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lcocos2d -lrt -lz -lcocosdenshion
debug: SHAREDLIBS += -Wl,-rpath,$(SDK_PATH)/lib/linux/Debug/
debug: DEFINES += -DDEBUG
debug: $(TARGET)

SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lOgreMain -lOgreRenderSystem -lOgreComponents
SHAREDLIBS += -lOIS

release: BIN_DIR = $(BIN_DIR_ROOT)/release
release: CCFLAGS += -O3
release: CXXFLAGS += -O3
release: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Release -lcocos2d -lrt -lz -lcocosdenshion
release: SHAREDLIBS += -Wl,-rpath,$(SDK_PATH)/lib/linux/Release/
release: DEFINES += -DNDEBUG
release: $(TARGET)

####### Build rules
$(TARGET): $(OBJECTS) 
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(OBJECTS) -o $(BIN_DIR)/$(TARGET) $(SHAREDLIBS) $(STATICLIBS)

####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean: 
	rm -f $(OBJECTS) $(TARGET) core
