TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/XMLhandler.cpp \
    src/User.cpp \
    src/SOB.cpp \
    src/Program.cpp \
    src/Gui.cpp \
    src/Display.cpp \
    src/Controls.cpp \
    src/Commands.cpp \
    src/Celestial.cpp \
    pugixml/pugixml.cpp \
    src/Camera.cpp \
    src/SpaceShip.cpp

HEADERS += \
    src/XMLhandler.h \
    src/User.h \
    src/SOB.h \
    src/MapLoader.h \
    src/Gui.h \
    src/Display.h \
    src/Controls.h \
    src/Commands.h \
    src/Celestial.h \
    dependencies/irrlicht/include/vector3d.h \
    dependencies/irrlicht/include/vector2d.h \
    dependencies/irrlicht/include/triangle3d.h \
    dependencies/irrlicht/include/SViewFrustum.h \
    dependencies/irrlicht/include/SVertexManipulator.h \
    dependencies/irrlicht/include/SVertexIndex.h \
    dependencies/irrlicht/include/SSkinMeshBuffer.h \
    dependencies/irrlicht/include/SSharedMeshBuffer.h \
    dependencies/irrlicht/include/SParticle.h \
    dependencies/irrlicht/include/SMeshBufferTangents.h \
    dependencies/irrlicht/include/SMeshBufferLightMap.h \
    dependencies/irrlicht/include/SMeshBuffer.h \
    dependencies/irrlicht/include/SMesh.h \
    dependencies/irrlicht/include/SMaterialLayer.h \
    dependencies/irrlicht/include/SMaterial.h \
    dependencies/irrlicht/include/SLight.h \
    dependencies/irrlicht/include/SKeyMap.h \
    dependencies/irrlicht/include/SIrrCreationParameters.h \
    dependencies/irrlicht/include/SExposedVideoData.h \
    dependencies/irrlicht/include/SColor.h \
    dependencies/irrlicht/include/SceneParameters.h \
    dependencies/irrlicht/include/SAnimatedMesh.h \
    dependencies/irrlicht/include/S3DVertex.h \
    dependencies/irrlicht/include/rect.h \
    dependencies/irrlicht/include/quaternion.h \
    dependencies/irrlicht/include/position2d.h \
    dependencies/irrlicht/include/plane3d.h \
    dependencies/irrlicht/include/path.h \
    dependencies/irrlicht/include/matrix4.h \
    dependencies/irrlicht/include/line3d.h \
    dependencies/irrlicht/include/line2d.h \
    dependencies/irrlicht/include/Keycodes.h \
    dependencies/irrlicht/include/IXMLWriter.h \
    dependencies/irrlicht/include/IXMLReader.h \
    dependencies/irrlicht/include/IWriteFile.h \
    dependencies/irrlicht/include/IVolumeLightSceneNode.h \
    dependencies/irrlicht/include/IVideoModeList.h \
    dependencies/irrlicht/include/IVideoDriver.h \
    dependencies/irrlicht/include/IVertexBuffer.h \
    dependencies/irrlicht/include/ITriangleSelector.h \
    dependencies/irrlicht/include/ITimer.h \
    dependencies/irrlicht/include/ITexture.h \
    dependencies/irrlicht/include/ITextSceneNode.h \
    dependencies/irrlicht/include/ITerrainSceneNode.h \
    dependencies/irrlicht/include/ISkinnedMesh.h \
    dependencies/irrlicht/include/IShadowVolumeSceneNode.h \
    dependencies/irrlicht/include/IShaderConstantSetCallBack.h \
    dependencies/irrlicht/include/ISceneUserDataSerializer.h \
    dependencies/irrlicht/include/ISceneNodeFactory.h \
    dependencies/irrlicht/include/ISceneNodeAnimatorFactory.h \
    dependencies/irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
    dependencies/irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
    dependencies/irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
    dependencies/irrlicht/include/ISceneNodeAnimator.h \
    dependencies/irrlicht/include/ISceneNode.h \
    dependencies/irrlicht/include/ISceneManager.h \
    dependencies/irrlicht/include/ISceneLoader.h \
    dependencies/irrlicht/include/ISceneCollisionManager.h \
    dependencies/irrlicht/include/irrXML.h \
    dependencies/irrlicht/include/irrunpack.h \
    dependencies/irrlicht/include/irrTypes.h \
    dependencies/irrlicht/include/irrString.h \
    dependencies/irrlicht/include/irrpack.h \
    dependencies/irrlicht/include/irrMath.h \
    dependencies/irrlicht/include/irrMap.h \
    dependencies/irrlicht/include/irrList.h \
    dependencies/irrlicht/include/IrrlichtDevice.h \
    dependencies/irrlicht/include/irrlicht.h \
    dependencies/irrlicht/include/IrrCompileConfig.h \
    dependencies/irrlicht/include/irrArray.h \
    dependencies/irrlicht/include/irrAllocator.h \
    dependencies/irrlicht/include/IReferenceCounted.h \
    dependencies/irrlicht/include/IReadFile.h \
    dependencies/irrlicht/include/IRandomizer.h \
    dependencies/irrlicht/include/IQ3Shader.h \
    dependencies/irrlicht/include/IQ3LevelMesh.h \
    dependencies/irrlicht/include/IParticleSystemSceneNode.h \
    dependencies/irrlicht/include/IParticleSphereEmitter.h \
    dependencies/irrlicht/include/IParticleRotationAffector.h \
    dependencies/irrlicht/include/IParticleRingEmitter.h \
    dependencies/irrlicht/include/IParticleMeshEmitter.h \
    dependencies/irrlicht/include/IParticleGravityAffector.h \
    dependencies/irrlicht/include/IParticleFadeOutAffector.h \
    dependencies/irrlicht/include/IParticleEmitter.h \
    dependencies/irrlicht/include/IParticleCylinderEmitter.h \
    dependencies/irrlicht/include/IParticleBoxEmitter.h \
    dependencies/irrlicht/include/IParticleAttractionAffector.h \
    dependencies/irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
    dependencies/irrlicht/include/IParticleAffector.h \
    dependencies/irrlicht/include/IOSOperator.h \
    dependencies/irrlicht/include/IMetaTriangleSelector.h \
    dependencies/irrlicht/include/IMeshWriter.h \
    dependencies/irrlicht/include/IMeshSceneNode.h \
    dependencies/irrlicht/include/IMeshManipulator.h \
    dependencies/irrlicht/include/IMeshLoader.h \
    dependencies/irrlicht/include/IMeshCache.h \
    dependencies/irrlicht/include/IMeshBuffer.h \
    dependencies/irrlicht/include/IMesh.h \
    dependencies/irrlicht/include/IMaterialRendererServices.h \
    dependencies/irrlicht/include/IMaterialRenderer.h \
    dependencies/irrlicht/include/ILogger.h \
    dependencies/irrlicht/include/ILightSceneNode.h \
    dependencies/irrlicht/include/ILightManager.h \
    dependencies/irrlicht/include/IIndexBuffer.h \
    dependencies/irrlicht/include/IImageWriter.h \
    dependencies/irrlicht/include/IImageLoader.h \
    dependencies/irrlicht/include/IImage.h \
    dependencies/irrlicht/include/IGUIWindow.h \
    dependencies/irrlicht/include/IGUITreeView.h \
    dependencies/irrlicht/include/IGUIToolbar.h \
    dependencies/irrlicht/include/IGUITable.h \
    dependencies/irrlicht/include/IGUITabControl.h \
    dependencies/irrlicht/include/IGUIStaticText.h \
    dependencies/irrlicht/include/IGUISpriteBank.h \
    dependencies/irrlicht/include/IGUISpinBox.h \
    dependencies/irrlicht/include/IGUISkin.h \
    dependencies/irrlicht/include/IGUIScrollBar.h \
    dependencies/irrlicht/include/IGUIMeshViewer.h \
    dependencies/irrlicht/include/IGUIListBox.h \
    dependencies/irrlicht/include/IGUIInOutFader.h \
    dependencies/irrlicht/include/IGUIImageList.h \
    dependencies/irrlicht/include/IGUIImage.h \
    dependencies/irrlicht/include/IGUIFontBitmap.h \
    dependencies/irrlicht/include/IGUIFont.h \
    dependencies/irrlicht/include/IGUIFileOpenDialog.h \
    dependencies/irrlicht/include/IGUIEnvironment.h \
    dependencies/irrlicht/include/IGUIElementFactory.h \
    dependencies/irrlicht/include/IGUIElement.h \
    dependencies/irrlicht/include/IGUIEditBox.h \
    dependencies/irrlicht/include/IGUIContextMenu.h \
    dependencies/irrlicht/include/IGUIComboBox.h \
    dependencies/irrlicht/include/IGUIColorSelectDialog.h \
    dependencies/irrlicht/include/IGUICheckBox.h \
    dependencies/irrlicht/include/IGUIButton.h \
    dependencies/irrlicht/include/IGPUProgrammingServices.h \
    dependencies/irrlicht/include/IGeometryCreator.h \
    dependencies/irrlicht/include/IFileSystem.h \
    dependencies/irrlicht/include/IFileList.h \
    dependencies/irrlicht/include/IFileArchive.h \
    dependencies/irrlicht/include/IEventReceiver.h \
    dependencies/irrlicht/include/IDynamicMeshBuffer.h \
    dependencies/irrlicht/include/IDummyTransformationSceneNode.h \
    dependencies/irrlicht/include/ICursorControl.h \
    dependencies/irrlicht/include/IColladaMeshWriter.h \
    dependencies/irrlicht/include/ICameraSceneNode.h \
    dependencies/irrlicht/include/IBoneSceneNode.h \
    dependencies/irrlicht/include/IBillboardTextSceneNode.h \
    dependencies/irrlicht/include/IBillboardSceneNode.h \
    dependencies/irrlicht/include/IAttributes.h \
    dependencies/irrlicht/include/IAttributeExchangingObject.h \
    dependencies/irrlicht/include/IAnimatedMeshSceneNode.h \
    dependencies/irrlicht/include/IAnimatedMeshMD3.h \
    dependencies/irrlicht/include/IAnimatedMeshMD2.h \
    dependencies/irrlicht/include/IAnimatedMesh.h \
    dependencies/irrlicht/include/heapsort.h \
    dependencies/irrlicht/include/fast_atof.h \
    dependencies/irrlicht/include/ETerrainElements.h \
    dependencies/irrlicht/include/EShaderTypes.h \
    dependencies/irrlicht/include/ESceneNodeTypes.h \
    dependencies/irrlicht/include/ESceneNodeAnimatorTypes.h \
    dependencies/irrlicht/include/EPrimitiveTypes.h \
    dependencies/irrlicht/include/EMessageBoxFlags.h \
    dependencies/irrlicht/include/EMeshWriterEnums.h \
    dependencies/irrlicht/include/EMaterialTypes.h \
    dependencies/irrlicht/include/EMaterialFlags.h \
    dependencies/irrlicht/include/EHardwareBufferFlags.h \
    dependencies/irrlicht/include/EGUIElementTypes.h \
    dependencies/irrlicht/include/EGUIAlignment.h \
    dependencies/irrlicht/include/EDriverTypes.h \
    dependencies/irrlicht/include/EDriverFeatures.h \
    dependencies/irrlicht/include/EDeviceTypes.h \
    dependencies/irrlicht/include/EDebugSceneTypes.h \
    dependencies/irrlicht/include/ECullingTypes.h \
    dependencies/irrlicht/include/EAttributes.h \
    dependencies/irrlicht/include/driverChoice.h \
    dependencies/irrlicht/include/dimension2d.h \
    dependencies/irrlicht/include/CVertexBuffer.h \
    dependencies/irrlicht/include/coreutil.h \
    dependencies/irrlicht/include/CMeshBuffer.h \
    dependencies/irrlicht/include/CIndexBuffer.h \
    dependencies/irrlicht/include/CDynamicMeshBuffer.h \
    dependencies/irrlicht/include/aabbox3d.h \
    pugixml/pugixml.hpp \
    pugixml/pugiconfig.hpp \
    src/Camera.h \
    src/SpaceShip.h


win32: LIBS += -L$$PWD/dependencies/irrlicht/lib/Win32-gcc/ -lIrrlicht \
    -lopengl32 \
    -lgdi32 \
    -lglu32
else:unix: LIBS += -L$$PWD/dependencies/irrlicht/lib/Linux/ -lIrrlicht \
    -L/usr/X11R6/lib -lGL -lXxf86vm -lXext -lX11 -lXcursor

INCLUDEPATH += $$PWD/src \
    $$PWD/pugixml \
    $$PWD/dependencies/irrlicht/include
win32: INCLUDEPATH += $$PWD/dependencies/irrlicht/lib/Win32-gcc/
else:unix: INCLUDEPATH += -L$$PWD/dependencies/irrlicht/lib/Linux/  \
    -I/usr/X11R6/include -O3 -ffast-math

win32: DEPENDPATH += $$PWD/dependencies/irrlicht/lib/Win32-gcc/
else:unix: DEPENDPATH += $$PWD/dependencies/irrlicht/lib/Linux/   \
            /usr/X11R6/lib

win32: PRE_TARGETDEPS += $$PWD/dependencies/irrlicht/lib/Win32-gcc/libIrrlicht.a
else:unix: PRE_TARGETDEPS += $$PWD/dependencies/irrlicht/lib/Linux/libIrrlicht.a

OTHER_FILES += \
    TODO
