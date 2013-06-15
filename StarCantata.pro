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
    irrlicht/vector3d.h \
    irrlicht/vector2d.h \
    irrlicht/triangle3d.h \
    irrlicht/SViewFrustum.h \
    irrlicht/SVertexManipulator.h \
    irrlicht/SVertexIndex.h \
    irrlicht/SSkinMeshBuffer.h \
    irrlicht/SSharedMeshBuffer.h \
    irrlicht/SParticle.h \
    irrlicht/SMeshBufferTangents.h \
    irrlicht/SMeshBufferLightMap.h \
    irrlicht/SMeshBuffer.h \
    irrlicht/SMesh.h \
    irrlicht/SMaterialLayer.h \
    irrlicht/SMaterial.h \
    irrlicht/SLight.h \
    irrlicht/SKeyMap.h \
    irrlicht/SIrrCreationParameters.h \
    irrlicht/SExposedVideoData.h \
    irrlicht/SColor.h \
    irrlicht/SceneParameters.h \
    irrlicht/SAnimatedMesh.h \
    irrlicht/S3DVertex.h \
    irrlicht/rect.h \
    irrlicht/quaternion.h \
    irrlicht/position2d.h \
    irrlicht/plane3d.h \
    irrlicht/path.h \
    irrlicht/matrix4.h \
    irrlicht/line3d.h \
    irrlicht/line2d.h \
    irrlicht/Keycodes.h \
    irrlicht/IXMLWriter.h \
    irrlicht/IXMLReader.h \
    irrlicht/IWriteFile.h \
    irrlicht/IVolumeLightSceneNode.h \
    irrlicht/IVideoModeList.h \
    irrlicht/IVideoDriver.h \
    irrlicht/IVertexBuffer.h \
    irrlicht/ITriangleSelector.h \
    irrlicht/ITimer.h \
    irrlicht/ITexture.h \
    irrlicht/ITextSceneNode.h \
    irrlicht/ITerrainSceneNode.h \
    irrlicht/ISkinnedMesh.h \
    irrlicht/IShadowVolumeSceneNode.h \
    irrlicht/IShaderConstantSetCallBack.h \
    irrlicht/ISceneUserDataSerializer.h \
    irrlicht/ISceneNodeFactory.h \
    irrlicht/ISceneNodeAnimatorFactory.h \
    irrlicht/ISceneNodeAnimatorCollisionResponse.h \
    irrlicht/ISceneNodeAnimatorCameraMaya.h \
    irrlicht/ISceneNodeAnimatorCameraFPS.h \
    irrlicht/ISceneNodeAnimator.h \
    irrlicht/ISceneNode.h \
    irrlicht/ISceneManager.h \
    irrlicht/ISceneLoader.h \
    irrlicht/ISceneCollisionManager.h \
    irrlicht/irrXML.h \
    irrlicht/irrunpack.h \
    irrlicht/irrTypes.h \
    irrlicht/irrString.h \
    irrlicht/irrpack.h \
    irrlicht/irrMath.h \
    irrlicht/irrMap.h \
    irrlicht/irrList.h \
    irrlicht/IrrlichtDevice.h \
    irrlicht/irrlicht.h \
    irrlicht/IrrCompileConfig.h \
    irrlicht/irrArray.h \
    irrlicht/irrAllocator.h \
    irrlicht/IReferenceCounted.h \
    irrlicht/IReadFile.h \
    irrlicht/IRandomizer.h \
    irrlicht/IQ3Shader.h \
    irrlicht/IQ3LevelMesh.h \
    irrlicht/IParticleSystemSceneNode.h \
    irrlicht/IParticleSphereEmitter.h \
    irrlicht/IParticleRotationAffector.h \
    irrlicht/IParticleRingEmitter.h \
    irrlicht/IParticleMeshEmitter.h \
    irrlicht/IParticleGravityAffector.h \
    irrlicht/IParticleFadeOutAffector.h \
    irrlicht/IParticleEmitter.h \
    irrlicht/IParticleCylinderEmitter.h \
    irrlicht/IParticleBoxEmitter.h \
    irrlicht/IParticleAttractionAffector.h \
    irrlicht/IParticleAnimatedMeshSceneNodeEmitter.h \
    irrlicht/IParticleAffector.h \
    irrlicht/IOSOperator.h \
    irrlicht/IMetaTriangleSelector.h \
    irrlicht/IMeshWriter.h \
    irrlicht/IMeshSceneNode.h \
    irrlicht/IMeshManipulator.h \
    irrlicht/IMeshLoader.h \
    irrlicht/IMeshCache.h \
    irrlicht/IMeshBuffer.h \
    irrlicht/IMesh.h \
    irrlicht/IMaterialRendererServices.h \
    irrlicht/IMaterialRenderer.h \
    irrlicht/ILogger.h \
    irrlicht/ILightSceneNode.h \
    irrlicht/ILightManager.h \
    irrlicht/IIndexBuffer.h \
    irrlicht/IImageWriter.h \
    irrlicht/IImageLoader.h \
    irrlicht/IImage.h \
    irrlicht/IGUIWindow.h \
    irrlicht/IGUITreeView.h \
    irrlicht/IGUIToolbar.h \
    irrlicht/IGUITable.h \
    irrlicht/IGUITabControl.h \
    irrlicht/IGUIStaticText.h \
    irrlicht/IGUISpriteBank.h \
    irrlicht/IGUISpinBox.h \
    irrlicht/IGUISkin.h \
    irrlicht/IGUIScrollBar.h \
    irrlicht/IGUIMeshViewer.h \
    irrlicht/IGUIListBox.h \
    irrlicht/IGUIInOutFader.h \
    irrlicht/IGUIImageList.h \
    irrlicht/IGUIImage.h \
    irrlicht/IGUIFontBitmap.h \
    irrlicht/IGUIFont.h \
    irrlicht/IGUIFileOpenDialog.h \
    irrlicht/IGUIEnvironment.h \
    irrlicht/IGUIElementFactory.h \
    irrlicht/IGUIElement.h \
    irrlicht/IGUIEditBox.h \
    irrlicht/IGUIContextMenu.h \
    irrlicht/IGUIComboBox.h \
    irrlicht/IGUIColorSelectDialog.h \
    irrlicht/IGUICheckBox.h \
    irrlicht/IGUIButton.h \
    irrlicht/IGPUProgrammingServices.h \
    irrlicht/IGeometryCreator.h \
    irrlicht/IFileSystem.h \
    irrlicht/IFileList.h \
    irrlicht/IFileArchive.h \
    irrlicht/IEventReceiver.h \
    irrlicht/IDynamicMeshBuffer.h \
    irrlicht/IDummyTransformationSceneNode.h \
    irrlicht/ICursorControl.h \
    irrlicht/IColladaMeshWriter.h \
    irrlicht/ICameraSceneNode.h \
    irrlicht/IBoneSceneNode.h \
    irrlicht/IBillboardTextSceneNode.h \
    irrlicht/IBillboardSceneNode.h \
    irrlicht/IAttributes.h \
    irrlicht/IAttributeExchangingObject.h \
    irrlicht/IAnimatedMeshSceneNode.h \
    irrlicht/IAnimatedMeshMD3.h \
    irrlicht/IAnimatedMeshMD2.h \
    irrlicht/IAnimatedMesh.h \
    irrlicht/heapsort.h \
    irrlicht/fast_atof.h \
    irrlicht/ETerrainElements.h \
    irrlicht/EShaderTypes.h \
    irrlicht/ESceneNodeTypes.h \
    irrlicht/ESceneNodeAnimatorTypes.h \
    irrlicht/EPrimitiveTypes.h \
    irrlicht/EMessageBoxFlags.h \
    irrlicht/EMeshWriterEnums.h \
    irrlicht/EMaterialTypes.h \
    irrlicht/EMaterialFlags.h \
    irrlicht/EHardwareBufferFlags.h \
    irrlicht/EGUIElementTypes.h \
    irrlicht/EGUIAlignment.h \
    irrlicht/EDriverTypes.h \
    irrlicht/EDriverFeatures.h \
    irrlicht/EDeviceTypes.h \
    irrlicht/EDebugSceneTypes.h \
    irrlicht/ECullingTypes.h \
    irrlicht/EAttributes.h \
    irrlicht/driverChoice.h \
    irrlicht/dimension2d.h \
    irrlicht/CVertexBuffer.h \
    irrlicht/coreutil.h \
    irrlicht/CMeshBuffer.h \
    irrlicht/CIndexBuffer.h \
    irrlicht/CDynamicMeshBuffer.h \
    irrlicht/aabbox3d.h \
    pugixml/pugixml.hpp \
    pugixml/pugiconfig.hpp \
    src/Camera.h \
    src/SpaceShip.h


win32: LIBS += -L$$PWD/irrlicht/Win-32/ -lIrrlicht \
    -lopengl32 \
    -lgdi32 \
    -lglu32
else:unix: LIBS += -L$$PWD/irrlicht/Linux-32/ -lIrrlicht \
    -L/usr/X11R6/lib -lGL -lXxf86vm -lXext -lX11 -lXcursor

INCLUDEPATH += $$PWD/src \
    $$PWD/pugixml \
    $$PWD/irrlicht
win32: INCLUDEPATH += $$PWD/irrlicht/Win-32/
else:unix: INCLUDEPATH += -L$$PWD/irrlicht/Linux-32/  \
    -I/usr/X11R6/include -O3 -ffast-math

win32: DEPENDPATH += $$PWD/irrlicht/Win-32/
else:unix: DEPENDPATH += $$PWD/irrlicht/Linux-32   \
            /usr/X11R6/lib

win32: PRE_TARGETDEPS += $$PWD/irrlicht/Win-32/libIrrlicht.a
else:unix: PRE_TARGETDEPS += $$PWD/irrlicht/Linux-32/libIrrlicht.a
