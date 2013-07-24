CC      = gcc
#CC		= @echo "compiling $@" && gcc
CXX     = g++
#CXX     = @echo "compiling $@" && g++

SO_TARGET = libOgreComponents.so

CCFLAGS = -Wall
CCFLAGS += -g3 -O0
CXXFLAGS = -Wall -fPIC
CXXFLAGS += -g3 -O0
VISIBILITY = 

#CXXFLAGS += -DOGRE_NONCLIENT_BUILD -DOGRE_GUI_GLX -fvisibility=hidden -fvisibility-inlines-hidden -DOGRE_GCC_VISIBILITY -MD -MP -MF -Wno-deprecated
CXXFLAGS += -DOGRE_NONCLIENT_BUILD -fvisibility=hidden -fvisibility-inlines-hidden -DOGRE_GCC_VISIBILITY -Wno-deprecated

DEFINES = -DLINUX
DEFINES += -DDEBUG

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
INCLUDES =  -I. \
			-I../../OgreMain/include \
			-I../../Build \
			-I../RTShaderSystem/include \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libfreetype2 \

#			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform\
			-I$(COCOS2DX_PATH)/platform/linux\
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS2DX_PATH)/kazmath/include/kazmath \
			-I$(SDK_PATH)/extensions/ \
			-I$(COCOS2DX_PATH)/ \
#			-I../include/gtk \


SO_OBJECTS =   \
					../RTShaderSystem/src/OgreShaderCGProgramProcessor.o \
					../RTShaderSystem/src/OgreShaderCGProgramWriter.o \
					../RTShaderSystem/src/OgreShaderExDualQuaternionSkinning.o \
					../RTShaderSystem/src/OgreShaderExHardwareSkinning.o \
					../RTShaderSystem/src/OgreShaderExHardwareSkinningTechnique.o \
					../RTShaderSystem/src/OgreShaderExIntegratedPSSM3.o \
					../RTShaderSystem/src/OgreShaderExLayeredBlending.o \
					../RTShaderSystem/src/OgreShaderExLinearSkinning.o \
					../RTShaderSystem/src/OgreShaderExNormalMapLighting.o \
					../RTShaderSystem/src/OgreShaderExPerPixelLighting.o \
					../RTShaderSystem/src/OgreShaderExTextureAtlasSampler.o \
					../RTShaderSystem/src/OgreShaderFFPColour.o \
					../RTShaderSystem/src/OgreShaderFFPFog.o \
					../RTShaderSystem/src/OgreShaderFFPLighting.o \
					../RTShaderSystem/src/OgreShaderFFPRenderStateBuilder.o \
					../RTShaderSystem/src/OgreShaderFFPTexturing.o \
					../RTShaderSystem/src/OgreShaderFFPTransform.o \
					../RTShaderSystem/src/OgreShaderFunctionAtom.o \
					../RTShaderSystem/src/OgreShaderFunction.o \
					../RTShaderSystem/src/OgreShaderGenerator.o \
					../RTShaderSystem/src/OgreShaderGLSLESProgramProcessor.o \
					../RTShaderSystem/src/OgreShaderGLSLESProgramWriter.o \
					../RTShaderSystem/src/OgreShaderGLSLProgramProcessor.o \
					../RTShaderSystem/src/OgreShaderGLSLProgramWriter.o \
					../RTShaderSystem/src/OgreShaderHLSLProgramProcessor.o \
					../RTShaderSystem/src/OgreShaderHLSLProgramWriter.o \
					../RTShaderSystem/src/OgreShaderMaterialSerializerListener.o \
					../RTShaderSystem/src/OgreShaderParameter.o \
					../RTShaderSystem/src/OgreShaderProgram.o \
					../RTShaderSystem/src/OgreShaderProgramManager.o \
					../RTShaderSystem/src/OgreShaderProgramProcessor.o \
					../RTShaderSystem/src/OgreShaderProgramSet.o \
					../RTShaderSystem/src/OgreShaderProgramWriter.o \
					../RTShaderSystem/src/OgreShaderProgramWriterManager.o \
					../RTShaderSystem/src/OgreShaderRenderState.o \
					../RTShaderSystem/src/OgreShaderScriptTranslator.o \
					../RTShaderSystem/src/OgreShaderSubRenderState.o \


LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
STATICLIBS_DIR = $(COCOS2DX_PATH)/platform/third_party/linux/libraries/lib64
else
STATICLIBS_DIR = $(COCOS2DX_PATH)/platform/third_party/linux/libraries
endif
STATICLIBS = 
#STATICLIBS = $(STATICLIBS_DIR)/libfreetype.a \
				$(STATICLIBS_DIR)/libxml2.a \
				$(STATICLIBS_DIR)/libpng.a \
				$(STATICLIBS_DIR)/libjpeg.a \
				$(STATICLIBS_DIR)/libtiff.a \

SHAREDLIBS = -lglfw -lcurl
#SHAREDLIBS += -Wl,-rpath,$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib
#SHAREDLIBS += -L$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib -lGLEW

#SHAREDLIBS += -lfreetype
#SHAREDLIBS += -lX11 -lXext -lGL -lXrandr -lXxf86vm -lGLU
#SHAREDLIBS += -lXaw -lXt -lSM -lICE
SHAREDLIBS += -lGL -lGLU
SHAREDLIBS += -lfreeimage
SHAREDLIBS += -Wl,-Bsymbolic-functions -lzzip -lz

#debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lcocos2d -lrt -lz -lcocosdenshion
debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lrt -lz
debug: SHAREDLIBS += -Wl,-rpath,$(SDK_PATH)/lib/linux/Debug/
debug: $(SO_TARGET)

####### Build rules
$(SO_TARGET): $(SO_OBJECTS) 
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) $(SO_OBJECTS) -shared -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean: 
	rm -f $(SO_OBJECTS) $(SO_TARGET) core

install: $(SO_TARGET)
	cp *.so $(SDK_PATH)/lib/linux/Debug

all : install
