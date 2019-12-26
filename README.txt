D22 OT SIEMENS BRAND DESIGN
1 Widget 
	SampleProject01
	SampleProject02
	SampleProject03
	SampleProject04
	SampleProject05
	SampleProject06
	SampleProject07
	SampleProject08
2 QML 
    SampleProject09
    SampleProject10
	SampleProject11
	SampleProject12
	SampleProject13
	SampleProject14
	SampleProject15
	SampleProject16
3 hall code 
	SampleProject17

4 The state machine
	SampleProject23
	
	
Expanding Delegate
https://doc.qt.io/archives/qt-4.8/qt-declarative-modelviews-listview-expandingdelegates-example.html



#https://github.com/qt/qt5.git
git fetch
git checked v5.12.0
git submodule update  --init


./configure -prefix $PWD/qtbase -opensource  -nomake tests


qt5/qtbase/qmake/qmake
 
Qt platform plugin
	qt5/qtbase/plugins/platforms/ 
 
-bindir <dir> ......... Executables [PREFIX/bin]
  -headerdir <dir> ...... Header files [PREFIX/include]
  -libdir <dir> ......... Libraries [PREFIX/lib]
  -archdatadir <dir> .... Arch-dependent data [PREFIX]
  -plugindir <dir> ...... Plugins [ARCHDATADIR/plugins]
  -libexecdir <dir> ..... Helper programs [ARCHDATADIR/bin on Windows,
                          ARCHDATADIR/libexec otherwise]
  -qmldir <dir> ......... QML imports [ARCHDATADIR/qml]
  
  
export QT_QPA_PLATFORM_PLUGIN_PATH=/home/etr1hc/samba/view/qt5/qtbase/plugins/platforms
export QT_PLUGIN_PATH=/home/etr1hc/samba/view/qt5/qtbase/plugins/platforms/libqlinuxfb.so

export QT_DEBUG_PLUGINS=1 

Available platform plugins are: eglfs, linuxfb, minimal, minimalegl, offscreen, vnc.
   export QT_QPA_PLATFORM=linuxfb
   export QT_QPA_PLATFORM=vnc
   
qml-module-qtquick-dialogs
Path
	/usr/lib/x86_64-linux-gnu/qt5/qml/QtQuick/Dialogs/libdialogplugin.so
	/usr/lib/x86_64-linux-gnu/qt5/qml/QtQuick/Dialogs/plugins.qmltypes
	/usr/lib/x86_64-linux-gnu/qt5/qml/QtQuick/Dialogs/qmldir
	/usr/lib/x86_64-linux-gnu/qt5/qml/QtQuick/Dialogs/Private/libdialogsprivateplugin.so
	/usr/lib/x86_64-linux-gnu/qt5/qml/QtQuick/Dialogs/Private/qmldir
	/usr/share/doc/qml-module-qtquick-dialogs/changelog.Debian.gz
	/usr/share/doc/qml-module-qtquick-dialogs/copyright

