CC      = gcc
#CC		= @echo "compiling $@" && gcc
CXX     = g++
#CXX     = @echo "compiling $@" && g++

SO_TARGET = libOgreRenderSystem.so

CCFLAGS = -Wall
CCFLAGS += -g3 -O0
CXXFLAGS = -Wall -fPIC
CXXFLAGS += -g3 -O0
VISIBILITY = 

#CXXFLAGS += -DOGRE_NONCLIENT_BUILD -DOGRE_GUI_GLX -fvisibility=hidden -fvisibility-inlines-hidden -DOGRE_GCC_VISIBILITY -MD -MP -MF -Wno-deprecated
#CXXFLAGS += -DOGRE_GCC_VISIBILITY -fvisibility=hidden -fvisibility-inlines-hidden 
#CXXFLAGS += -DOGRE_GUI_GLX -Wno-deprecated
CXXFLAGS += -Wno-deprecated

DEFINES = -DLINUX
DEFINES += -DDEBUG

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
INCLUDES =  -I. \
			-I../../Build \
			-I../../OgreMain/include \
			-I../GL/include \
			-I../GL/src/GLSL/include \
			-I../GL/src/GLEW \
			-I../GL/include/GL \
			-I../GL/include/GLX \
			-I../GL/src/GLX \

SO_OBJECTS =   \
					../GL/src/GLEW/ogreglewglsupport.o \
					../GL/src/GLEW/ogreglewwindow.o \
					../GL/src/GLSL/src/OgreGLSLExtSupport.o \
					../GL/src/GLSL/src/OgreGLSLGpuProgram.o \
					../GL/src/GLSL/src/OgreGLSLLinkProgram.o \
					../GL/src/GLSL/src/OgreGLSLLinkProgramManager.o \
					../GL/src/GLSL/src/OgreGLSLPreprocessor.o \
					../GL/src/GLSL/src/OgreGLSLProgram.o \
					../GL/src/GLSL/src/OgreGLSLProgramFactory.o \
					../GL/src/OgreGLATIFSInit.o \
					../GL/src/OgreGLContext.o \
					../GL/src/OgreGLDefaultHardwareBufferManager.o \
					../GL/src/OgreGLDepthBuffer.o \
					../GL/src/OgreGLEngineDll.o \
					../GL/src/OgreGLFBOMultiRenderTarget.o \
					../GL/src/OgreGLFBORenderTexture.o \
					../GL/src/OgreGLFrameBufferObject.o \
					../GL/src/OgreGLGpuProgram.o \
					../GL/src/OgreGLGpuProgramManager.o \
					../GL/src/OgreGLHardwareBufferManager.o \
					../GL/src/OgreGLHardwareIndexBuffer.o \
					../GL/src/OgreGLHardwareOcclusionQuery.o \
					../GL/src/OgreGLHardwarePixelBuffer.o \
					../GL/src/OgreGLHardwareVertexBuffer.o \
					../GL/src/OgreGLPBRenderTexture.o \
					../GL/src/OgreGLPixelFormat.o \
					../GL/src/OgreGLPlugin.o \
					../GL/src/OgreGLRenderSystem.o \
					../GL/src/OgreGLRenderTexture.o \
					../GL/src/OgreGLRenderToVertexBuffer.o \
					../GL/src/OgreGLSupport.o \
					../GL/src/OgreGLTexture.o \
					../GL/src/OgreGLTextureManager.o \
					../GL/src/glew.o \
#					../GL/src/OgreGLGpuNvparseProgram.o \
#					../GL/src/OgreWin32GLSupport.o \
					../GL/src/OgreWin32RenderTexture.o \
					../GL/src/OgreWin32Window.o \
					../GL/src/win32/OgreWin32Context.o \

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
#				$(STATICLIBS_DIR)/libGLEW.a \

SHAREDLIBS = -lglfw# -lcurl

#SHAREDLIBS += -lfreetype
#SHAREDLIBS += -lX11 -lXext -lGL -lXrandr -lXxf86vm -lGLU
SHAREDLIBS += -lGL -lGLU
#SHAREDLIBS += -lCg -lfreeimage -lpthread -lm -ldl
SHAREDLIBS += -lfreeimage -lpthread -lm -ldl

#debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lcocos2d -lrt -lz -lcocosdenshion
debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lrt -lz
debug: SHAREDLIBS += -lrt -lz
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
